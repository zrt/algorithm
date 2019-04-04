#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n,m,S,T;
int tot;
int H[205],X[80000],P[80000],flow[80000],cost[80000],from[80000];
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;cost[tot]=k;from[tot]=x;
}
struct Point{
	int x,y;
}ni[105],mi[105];
int dis(Point a,Point b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int a[205],d[205],p[205];
struct N{
	int x,w,t;
	N(int a=0,int b=0,int c=0) {
		x=a,w=b;t=c;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
};
bool vis[205];
priority_queue<N> q;
bool spfa(){
	int siz=n+m+1;
	int x,t;
	for(int i=1;i<=siz;i++){
		q.push(N(i,0,0));
	}
	bool flag=0;
	while(!q.empty()){
		x=q.top().x;t=q.top().t;q.pop();
		if(t>siz) {
			flag=1;break;
		}
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
				d[P[i]]=d[x]+cost[i];
				p[P[i]]=i;
				q.push(N(P[i],d[P[i]],t+1));
			}
		}
		while(!q.empty()&&d[q.top().x]!=q.top().w) q.pop();
	}
	if(!flag) return 0;
	else{
		while(1){
			if(vis[x]) break;
			vis[x]=1;
			x=from[p[x]];
		}
		int k=x;bool ff(1);
		while(ff||x!=k){
			ff=0;flow[p[x]]-=1;flow[p[x]^1]+=1;
			x=from[p[x]];
		}
		return 1;
	}
}
int bi[105],ci[105];
int ans[105][105];
int ti[105];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tot=1;
	scanf("%d%d",&n,&m);
	S=0,T=n+m+1;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&ni[i].x,&ni[i].y,&bi[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&mi[i].x,&mi[i].y,&ci[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&ans[i][j]);ti[j]+=ans[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		add(S,i,0,0);add(i,S,bi[i],0);
		for(int j=1;j<=m;j++){
			add(i,j+n,inf-ans[i][j],(dis(ni[i],mi[j])+1));add(j+n,i,ans[i][j],-(dis(ni[i],mi[j])+1));
		}
	}
	for(int i=1;i<=m;i++){
		add(i+n,T,ci[i]-ti[i],0);add(T,i+n,ti[i],0);
	}
	if(!spfa()) puts("OPTIMAL");
	else {
		puts("SUBOPTIMAL");
		for(int i=2;i<=tot;i++){
			if(from[i]>0&&from[i]<=n&&P[i]>n&&P[i]<=n+m){
				ans[from[i]][P[i]-n]=inf-flow[i];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d ",ans[i][j]);
			}
			puts("");
		}
	}
	return 0 ;
}
