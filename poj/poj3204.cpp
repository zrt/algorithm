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
const int inf(0x3fffffff) ;
int n,m,c;
int S,T;
int H[505],X[10005],P[10005],flow[10005],tot,cap[10005];
int floww[10005];
int maxflow;
inline void add(int x,int y,int z ){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=cap[tot]=z;
}
int d[505];
queue<int> q;
bool belong[505];
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);
	int k;
	while(!q.empty()){
		k=q.front();q.pop();
		for(int i=H[k];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[k]+1;
				q.push(P[i]);
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
	if(f==a) d[x]=0-1;
	return f-a;
}
int Dinic(int flows){
	int f=flows;
	while(f<=maxflow&&bfs()) f+=dfs(S,inf);
	return f;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d",&n,&m);
	memset(belong,0,sizeof belong);
	tot=1;
	S=1,T=n;
	memset(H,0,sizeof H);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		x++;y++;
		add(x,y,z);
		add(y,x,0);
	}
	maxflow=inf;
	maxflow=Dinic(0);
	belong[S]=1;
	q.push(S);int k;
	while(!q.empty()){
		k=q.front();q.pop();
		for(int i=H[k];i;i=X[i]){
			if(flow[i]>0&&!belong[P[i]]) {
				belong[P[i]]=1;
				q.push(P[i]);
			}
		}
	}
	memcpy(floww,flow,sizeof flow);
	int t(0);
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if((belong[P[j]]^belong[i])&&cap[j]>0){
				memcpy(flow,floww,sizeof flow);
				flow[j]=inf;
				if(Dinic(maxflow)>maxflow){
					t++;
				}
			}
		}
	}
	printf("%d\n",t);
	return 0 ;
}
 