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
int n,m;
LL f[100005];
int minn;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	minn=min(n,m);LL ans=0;
	for(int i=minn;i>0;i--){
		f[i]=(n/i)*1LL*(m/i);
		for(int j=2;i*j<=minn;j++){
			f[i]-=f[i*j];
		}
		ans+=f[i]*(2*i-1);
	}
	printf("%lld\n",ans);
	return 0;
}
