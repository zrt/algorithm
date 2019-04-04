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
int m,n;
int tot,H[106],X[200000],P[200000],flow[200000];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int S,T;
int val[1006];
int num[106];
int vis[1006];
int d[106];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	return d[T];
}
int dfs(int x,int a){
	int f=a,tmp;
	if(x==T||a==0) return a;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(a,flow[i]));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
//	printf("%d\n",f-a);
	return f-a;
}
int Dinic(){
	int f=0;
	while(bfs()) f+=dfs(S,inf);
	return f;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d",&m,&n);
	S=0;T=n+1;tot=1;
	for(int i=1;i<=m;i++) scanf("%d",&val[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0,x;j<k;j++){
			scanf("%d",&x);
			if(vis[x]){
				add(vis[x],i,inf);
				add(i,vis[x],0);
				vis[x]=i;
			}else{
				vis[x]=i;
				add(S,i,val[x]);
				add(i,S,0);
			}
		}
		scanf("%d",&num[i]);
		add(i,T,num[i]);
		add(T,i,0);
	}
	printf("%d\n",Dinic());
	return 0 ;
}
