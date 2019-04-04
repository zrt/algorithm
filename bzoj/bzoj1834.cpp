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
int H[1005],P[22000],X[22000],tot,flow[22000],cost[22000],from[22000];
int n,m,k,maxflow,S,T;
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;cost[tot]=k;from[tot]=x;
}
int x[5005],y[5005],cst[5005];
int d[1005];
queue<int> bq;
int f,c;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;bq.push(S);int k;
	while(!bq.empty()){
		k=bq.front();bq.pop();
		for(int i=H[k];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[k]+1;
				bq.push(P[i]);
			}
		}
	}
	return d[T];
}
int dfs(int x,int a){
	if(x==T||a==0) return a;
	int f=a,tmp;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(flow[i],a));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int Dinic(){
	int ff(0);
	while(bfs()) ff+=dfs(S,inf);
	return ff;
}
int a[1005],p[1005];
struct N{
	int x,w;
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
priority_queue<N> q;
bool spfa(){
	memset(d,0x3f,sizeof d);
	d[S]=0;a[S]=inf;p[S]=0;
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
	bool flag=0;
	if(a[T]>=maxflow+k-f){
		a[T]=maxflow+k-f;
		flag=1;
	}
	f+=a[T];
	c+=a[T]*d[T];
	x=T;
	while(x!=S){
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	if(flag) return false ;
	else return true ;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tot=1;
	scanf("%d%d%d",&n,&m,&k);
	S=1,T=n;
	for(int i=0,a;i<m;i++){
		scanf("%d%d%d%d",&x[i],&y[i],&a,&cst[i]);
		add(x[i],y[i],a,0);
		add(y[i],x[i],0,0);
	}
	maxflow=Dinic();
	f=maxflow;
	for(int i=0;i<m;i++){
		add(x[i],y[i],inf,cst[i]);
		add(y[i],x[i],0,-cst[i]);
	}
	while(spfa()) ;
	printf("%d %d\n",maxflow,c);
	return 0 ;
}
