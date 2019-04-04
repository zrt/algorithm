#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
int n,m;
int H[408],S,T,X[200000],P[200000],flow[200000];
int tot=1;
const int inf=0x7fffffff;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[408];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	return d[T];
}
int dfs(int x,int f){
	if(x==T||f==0) return f;
	int a=f,tmp;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(flow[i],f));
			f-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!f) break;
		}
	}
	if(f==a) d[x]=-1;
	return a-f;
}
int Dinic(){
	int f=0;
	while(bfs()){
		f+=dfs(S,inf);
	}
	return f;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d",&S,&T);
	S=S<<1;T=T<<1|1;
	for(int i=1,w;i<=n;i++){
		scanf("%d",&w);
		add(i<<1,i<<1|1,w);
		add(i<<1|1,i<<1,0);
	}
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x<<1|1,y<<1,inf);
		add(y<<1,x<<1|1,0);
		add(y<<1|1,x<<1,inf);
		add(x<<1,y<<1|1,0);
	}
	printf("%d\n",Dinic());
	return 0;
}
