#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
struct N{
	LL x,w;
	N(LL a=0,LL b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w<b.w;
	}
};
priority_queue<N> q;
bool ans[255001];
LL a[255001],b[255001];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	int n;scanf("%d",&n);
	LL now(0);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++){
		now+=a[i];
		if(now>=b[i]){
			now-=b[i];q.push(N(i,b[i]));ans[i]=1;
		}else{
			if(q.empty()) continue;
			int big=q.top().w,x=q.top().x;
			if(big>b[i]) {
				q.pop();ans[x]=0;now+=big-b[i];
				q.push(N(i,b[i]));ans[i]=1;
			}
		}
	}
	int tot=0;
	for(int i=1;i<=n;i++) if(ans[i]) tot++;
	printf("%d\n",tot);
	for(int i=1;i<=n;i++) if(ans[i]) printf("%d ",i);
	return 0 ;
}
