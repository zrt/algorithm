#include<bits/stdc++.h>
using namespace std;
int tt;
typedef long long LL;
LL p;
LL pi[10],ai[10],tot;
LL ans[10];
LL f[10][20000];
int n,n1,n2;
LL m;
int a[20];
LL pow(LL a,LL b,LL p){
	LL ret=1%p;
	while(b){
		if(b&1) ret=ret*a%p;
		b>>=1;
		a=a*a%p;
	}
	return ret;
}
void pre(int x){
	f[x][0]=1;
	LL pik=pow(pi[x],ai[x],p+1);
	for(int i=1;i<=pik;i++){
		if(i%pi[x]==0) f[x][i]=f[x][i-1];
		else f[x][i]=f[x][i-1]*i%pik;
	}
}
int count(int x){
	int ret=0;
	while(x){
		ret++;x&=(x-1);
	}
	return ret;
}

int calc(int n,int k){
	if(n==0) return 0;
	return n/k+calc(n/k,k);
}
LL calc2(int n,int x,LL mod){
	if(n==0) return 1;
	return pow(f[x][mod],n/mod,mod)*f[x][n%mod]%mod*calc2(n/pi[x],x,mod)%mod;
}
LL ni(LL a,LL x){
	return pow(a,pow(pi[x],ai[x],p+1)-pow(pi[x],ai[x]-1,p+1)-1,pow(pi[x],ai[x],p+1));
}
LL C(LL n,LL m,LL x){
	// n!/m!/(n-m)!  mod pi[x]^ai[x]
	LL pik=pow(pi[x],ai[x],p+1);
	LL ret=pow(pi[x],calc(n,pi[x])-calc(m,pi[x])-calc(n-m,pi[x]),pik);
	return ret*calc2(n,x,pik)%pik*ni(calc2(m,x,pik),x)%pik*ni(calc2(n-m,x,pik),x)%pik;
}
LL CRT(){//合并ans[]
	LL ret=0;
	for(int i=1;i<=tot;i++){
		LL pik=pow(pi[i],ai[i],p+1);
		ret=(ret+p/pik*ni(p/pik,i)%p*ans[i]%p)%p;
	}
	return ret;
}
LL C(LL n,LL m){
	if(n<m) return 0;
	for(int i=1;i<=tot;i++){
		ans[i]=C(n,m,i);
	}
	return CRT();
}
LL solve(int s){//哪些不合法
	LL num=m;
	for(int i=0;i<n1;i++){
		if(s&(1<<i)){
			num-=a[i];
		}
	}
	return C(num-1,n-1);
}
int main(){
	scanf("%d%lld",&tt,&p);
	LL lim=sqrt(p),tmp=p;
	for(int i=2;i<=lim;i++){
		if(tmp%i==0){
			pi[++tot]=i;
			while(tmp%i==0) tmp/=i,ai[tot]++;
		}
	}
	if(tmp>1) pi[++tot]=tmp,ai[tot]=1;
	for(int i=1;i<=tot;i++) pre(i);
	while(tt--){
		scanf("%d%d%d%lld",&n,&n1,&n2,&m);
		for(int i=0;i<n1;i++) scanf("%d",&a[i]);
		for(int i=1,x;i<=n2;i++){
			scanf("%d",&x);
			m-=x-1;
		}
		LL ans=0;
		for(int i=0;i<1<<n1;i++){
			if(~count(i)&1) ans=(ans+solve(i))%p;
			else ans=(ans-solve(i)+p)%p;
		}
		printf("%lld\n",ans);
	}
	
	
	return 0;
}
