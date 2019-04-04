#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n,m,S,T;
int H[405],P[50000],X[50000],tot,flow[50000],cost[50000],from[50000];
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;cost[tot]=k;;from[tot]=x;
}
int f,c;
int a[405],p[405],d[405];
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
bool spfa(){
	while(!q.empty()) q.pop();
	memset(d,0x3f,sizeof d);
	d[S]=0;a[S]=inf;p[S]=-1;
	q.push(N(S,0));
	int x;
	while(!q.empty()){
		x=q.top().x;q.pop();
		if(x==T) continue;
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
				d[P[i]]=d[x]+cost[i];
				a[P[i]]=min(a[x],flow[i]);
				p[P[i]]=i;
				q.push(N(P[i],d[P[i]]));
			}
		}
		while(!q.empty()&&d[q.top().x]!=q.top().w) q.pop();
	}
	if(d[T]==inf) return false;
	f+=a[T];c+=d[T]*a[T];
	x=T;
	while(x!=S){
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	return true;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tot=1;
	scanf("%d%d",&n,&m);
	S=3,T=n<<1;
	for(int i=1;i<=n;i++){
		add(i<<1,i<<1|1,1,0);
		add(i<<1|1,i<<1,0,0);
	}
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x<<1|1,y<<1,1,z);
		add(y<<1,x<<1|1,0,-z);
	}
	while(spfa());
	printf("%d %d\n",f,c);
	return 0 ;
}
