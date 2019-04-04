#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int art[105][105];
int science[105][105];
int same_art[105][105];
int same_science[105][105];
int get(int x,int y){
	return (x-1)*m+y;
}
const int MAXN=30005,MAXM=2100050;
int H[MAXN],P[MAXM],X[MAXM],tot=1,flow[MAXM];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;
}
int S=30003,T=30004;
// 1..n 本身
// n+1..2n 文
// 2n+1..3n 理
int N;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
const int inf=0x3f3f3f3f;
long long sum;
bool check(int x,int y){
	return x>0&&x<=n&&y>0&&y<=m;
}
void add_edge(int x,int y){
	sum-=art[x][y]*2+science[x][y]*2;
	add(S,get(x,y),science[x][y]*2);
	add(get(x,y),T,art[x][y]*2);
	sum-=2*same_art[x][y]+2*same_science[x][y];
	add(get(x,y),get(x,y)+N,same_art[x][y]);
	add(get(x,y)+N,get(x,y),same_art[x][y]);
	add(get(x,y),get(x,y)+N*2,same_science[x][y]);
	add(get(x,y)+N*2,get(x,y),same_science[x][y]);
	add(get(x,y),T,same_art[x][y]);
	add(get(x,y)+N,T,same_art[x][y]);
	add(S,get(x,y)+N*2,same_science[x][y]);
	add(S,get(x,y),same_science[x][y]);
}
void add_(int i,int j,int x,int y){
	add(get(x,y),get(i,j)+N,inf);
	add(get(i,j)+N*2,get(x,y),inf);
}
int d[MAXN];
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
	if(x==T||a==0) return a;
	int f=a,tmp;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(a,flow[i]));
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
	int ret=0;
	while(bfs()) ret+=dfs(S,inf);
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);N=n*m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&art[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&science[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&same_art[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&same_science[i][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			add_edge(i,j);
			for(int k=0;k<4;k++){
				int x=dx[k]+i;
				int y=dy[k]+j;
				if(check(x,y)) add_(i,j,x,y);
			}
		}
	}
	printf("%lld\n",-(sum+Dinic())/2);
	return 0;
}
