#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
LL mod=19940417;
LL getsum(LL x){
	return x*(x+1)%mod*(2*x+1)%mod*23263820%mod;
}
LL calc(LL x,LL lim){
	LL ret=0;
	for(int i=1;i<=lim;i++){
///		printf("%d %lld\n",i,ret);
		LL a=x/i,b=x/a;
		b=min(b,lim);
		ret=(ret+(b-i+1)*(i+b)%mod*29910626%mod*a%mod)%mod;
		i=b;
	}
	return ret;
}
LL calc2(LL x,LL y,LL lim){
	LL ret=0;
	for(int i=1;i<=lim;i++){
//		printf("%d\n",i);
		LL a=x/i,b=y/i;
		LL c=min(lim,min(x/a,y/b));
	//	printf("%lld\n",c);
		ret=(ret+a*b%mod*((getsum(c)-getsum(i-1))%mod)%mod)%mod;
		i=c;
	}
	return ret;
}
LL n,m;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld%lld",&n,&m);
	if(n>m) swap(n,m);
	LL ans=0;
	ans=(n*n-calc(n,n))%mod*((m*m-calc(m,m))%mod)%mod;
//	printf("%lld %lld %lld %lld\n",n*n,calc(n,n),m*m,calc(m,m));
//	printf("%lld\n",ans);
	ans-=n*n%mod*m%mod-n*calc(m,n)%mod-m*calc(n,n)%mod+calc2(n,m,n);
	printf("%lld\n",(ans%mod+mod)%mod);
	return 0;
}
