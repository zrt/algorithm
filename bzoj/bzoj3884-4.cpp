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

int solve(int x){
	if(x==1) return 0;
	return pow(2,solve(phi[x])+phi[x],x);
}
int main(){
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
	while(tt--){
		scanf("%d",&x);
		printf("%d\n",solve(x));
	}
	return 0;
}

