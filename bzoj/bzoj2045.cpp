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
int a,b,d;
LL f[1000050];
int minn;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&a,&b,&d);
	minn=min(a,b);
	for(int i=minn;i>=d;i--){
		f[i]=(a/i)*1LL*(b/i);
		for(int j=2;i*j<=minn;j++){
			f[i]-=f[i*j];
		}
	}
	printf("%lld\n",f[d]);
	return 0;
}
