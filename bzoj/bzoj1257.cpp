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
LL n,k;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld%lld",&n,&k);
	LL ans=n*k;
	LL sub=0;
	for(int i=1;i<=n&&i<=k;i++){
		LL a=k/i;LL b=k/a;
		b=min(b,n);
		sub+=a*(i+b)*(b-i+1)/2;
		i=b;
	}
	printf("%lld\n",ans-sub);
	return 0;
}
