#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int H[405],X[350000],P[350000],tot=1,flow[350000];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;
}
int S=403,T=404;
const int inf=0x3f3f3f3f;
int d[405];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	q.push(S);d[S]=1;
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
	if(x==T||a==0 ) return a;
	int f=a,tmp;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(flow[i],a));
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			a-=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int Dinic(){
	int f=0;
	while(bfs()) f+=dfs(S,inf);
	return f;
}
bool f[205][205];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		f[x][y]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]|=f[i][k]&f[k][j];
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(f[i][j]) add(i,j+n,1);
	for(int i=1;i<=n;i++) add(S,i,1),add(i+n,T,1);
	printf("%d\n",n-Dinic());
	return 0;
}
