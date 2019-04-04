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
LL n,Sa,Sb,Sc,Sd,mod;
LL a[5000005];
LL F(int x){
	return (((Sa*x%mod*x%mod*x%mod+Sb*x%mod*x%mod)%mod+Sc*x%mod)%mod+Sd)%mod;
}
LL maxx;
LL ans;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&Sa,&Sb,&Sc,&Sd,&a[1],&mod);
	for(int i=2;i<=n;i++){
		a[i]=(F(a[i-1])+F(a[i-2]))%mod;
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,a[i]);
		ans=max(ans,maxx-a[i]);
	}
	printf("%lld\n",(ans-1)/2+1);
	return 0;
}
