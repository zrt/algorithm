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
int f,c;
int H[1605],P[655000],X[655000],tot,flow[655000],cost[655000],from[655000];
int d[1605],a[1605],p[1605];
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;cost[tot]=k;from[tot]=x;
}
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
	memset(d,0x3f,sizeof d);
	d[S]=0,a[S]=inf,p[S]=0;
	q.push(N(S,0));int x;
	while(!q.empty()){
		x=q.top().x;q.pop();
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
	f+=a[T];
	c+=a[T]*d[T];
	x=T;
	while(x!=S){
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tot=1;S=0,T=1604;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		add(S,i,1,0);
		add(i,S,0,0);
		add(i+800,T,1,0);
		add(T,i+800,0,0);
	}
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		add(S,i+800,1,x);
		add(i+800,S,0,-x);
	}
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(x>y) swap(x,y);
		add(x,y+800,1,z);
		add(y+800,x,0,-z);
	}
	while(spfa());
	printf("%d\n",c);
	return 0 ;
}
