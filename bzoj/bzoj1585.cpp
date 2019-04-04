#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
//by zrt
//problem:
using namespace std;
int n,m,k;
int H[6005],X[400050],P[400050],tot,flow[400050];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
// << 1 in || <<1|1 out
int inf=8000;
int d[6005];
int S=6003,T=6004;
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	int x;d[S]=1;
	while(!q.empty()) q.pop();
	q.push(S);
	while(!q.empty()){
		x=q.front();q.pop();
		if(x==T) return 1;
		for(int i=H[x];i;i=X[i]){
			if(!d[P[i]]&&flow[i]>0){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	return 0;
}
int dfs(int x,int a){
	int f=a,tmp;
	if(x==T||a==0) return a;
	for(int i=H[x];i;i=X[i]){
		if(d[P[i]]==d[x]+1&&flow[i]>0){
			tmp=dfs(P[i],min(flow[i],a));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int Dinic(){
	int f=0,tmp;
	while(bfs()){
		while((tmp=dfs(S,inf))>0) f+=tmp;
	}
	return f;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	tot=1;
	
	scanf("%d%d%d",&n,&m,&k);
	add(S,1<<1|1,inf);
	add(1<<1|1,S,0);
	for(int i=1;i<=n;i++){
		add(i<<1,i<<1|1,1);
		add(i<<1|1,i<<1,0);
	}
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x<<1|1,y<<1,inf);
		add(y<<1,x<<1|1,0);
		add(y<<1|1,x<<1,inf);
		add(x<<1,y<<1|1,0);
	}
	for(int i=0,x;i<k;i++){
		scanf("%d",&x);
		add(x<<1,T,inf);
		add(T,x<<1,0);
	}
	printf("%d\n",Dinic());
	return 0;
}
