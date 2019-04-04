#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdlib>

//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
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
int H[100005],X[400005],P[400005],E[400005];
int d[100005];
int f[100005];
int dep[100005];
int fa[100005];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
struct edge{
	int x,y,l;
	bool is;
	friend bool operator < (edge a,edge b){
		return a.l<b.l;
	}
}e[200005];
int tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
bool vis[100005];
void dfs(int x){
	for(int i=H[x];i;i=X[i]){
		if(d[P[i]]-d[x]==E[i]){
			fa[P[i]]=x;
			dep[P[i]]=dep[x]+1;
			dfs(P[i]);
		}
	}
}
int ans[100005];
int n,m;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].l);
		add(e[i].x,e[i].y,e[i].l);
		add(e[i].y,e[i].x,e[i].l);
	}
	memset(d,0x3f,sizeof d);
	d[1]=0;
	q.push(N(1,0));
	while(!q.empty()){
		int x=q.top().x;q.pop();
		if(vis[x]) continue;else vis[x]=1;
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				q.push(N(P[i],d[P[i]]));
			}
		}
	}
	for(int i=0;i<m;i++){
		if(abs(d[e[i].x]-d[e[i].y])==e[i].l) e[i].is=1,e[i].l=1<<30;
		else e[i].is=0,e[i].l+=d[e[i].x]+d[e[i].y];
	}
	sort(e,e+m);
	dep[1]=1;
	dfs(1);
	for(int i=1;i<=n;i++) f[i]=i;
	memset(ans,0x3f,sizeof ans);
	for(int i=0;i<m;i++){
		int x=e[i].x,y=e[i].y,len=e[i].l;
		while(x!=y){
			if(dep[x]<dep[y]) swap(x,y);
			ans[x]=min(ans[x],len-d[x]);
			f[get(x)]=get(fa[x]);
			x=get(fa[x]);
		}
	}
	for(int i=2;i<=n;i++){
		if(ans[i]==0x3f3f3f3f) puts("-1");
		else printf("%d\n",ans[i]);
	}
	return 0;
}
