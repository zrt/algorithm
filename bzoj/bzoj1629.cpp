#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long LL;
LL inf =(1<<30);
int n;
struct N{
	LL f,w;
	//                        i   i+1
	friend bool operator < (N a,N b){
		return max(a.w-b.f,-a.f)<max(-b.f,b.w-a.f);
	}
}a[50005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].w,&a[i].f);
	}
	//  max w[i]-f[i+1],-f[i] < max -f[i+1],w[i+1]-f[i]
	sort(a+1,a+1+n);
	LL ans=-inf;
	LL sum=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,sum-a[i].f);
		sum+=a[i].w;
	}
	printf("%lld\n",ans);
	return 0;
}
