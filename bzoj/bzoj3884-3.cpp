#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tt;
const int MAXN=1e7+5;
int mindiv[MAXN],prime[664580],tot,phi[MAXN];
int x;
int pow(int a,int b,int p){
	int ret=1;
	while(b){
		if(b&1) ret=ret*1LL*a%p;
		b>>=1;
		a=a*1LL*a%p;
	}
	return ret;
}
typedef long long LL;
void exgcd(int a,int b,int&d,LL&x,LL&y,int mod){
	if(!b) {
		d=a;x=1;y=0;
	}else{
		exgcd(b,a%b,d,y,x,mod);
		if(x>=mod) x%=mod;
		if(x<=-mod) x%=mod,x+=mod;
		y-=x*(a/b);
	}
}
int calc(int x){
	int solve(int);
	int p=0,mod=x;
	
	while(!(x&1)){
		x>>=1;
		p++;
	}
	LL k1,k2;
	int d;
	k1=k2=0;
	exgcd(x,-(1<<p),d,k1,k2,mod);
	if(d==-1) k1*=-1,k2*=-1;
	k1%=mod,k2%=mod;
	k1=(k1+mod)%mod;
	k2=(k2+mod)%mod;
	int pp=solve(x);
	k1=k1*pp%mod;
	k2=k2*pp%mod;
	return (-k2*(1<<p)%mod+mod)%mod;
}
int solve(int x){
	if(x==1) return 0;
	if(x&1){
		return pow(2,solve(phi[x]),x);
	}else{
		return calc(x);
	}
}
int main(){
	//double tttt=clock();
	int n=1e7;
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!mindiv[i]) mindiv[i]=i,prime[tot++]=i,phi[i]=i-1;
		for(int j=0;prime[j]*1LL*i<=n;j++){
			mindiv[prime[j]*i]=prime[j];
			if(mindiv[i]==prime[j]){
				phi[prime[j]*i]=prime[j]*phi[i];
				break;
			}
			phi[prime[j]*i]=phi[prime[j]]*phi[i];
		}
	}
	scanf("%d",&tt);
	//tt=0;
	while(tt--){
		scanf("%d",&x);
		printf("%d\n",solve(x));
	}
	//printf("%.3f\n",(clock()-tttt)/CLOCKS_PER_SEC);
	return 0;
}
