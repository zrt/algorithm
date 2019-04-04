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
int n,m,S,T;
int H[10205],X[1200000],P[1200000],flow[1200000],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[10205];
queue<int>q ;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);int k;
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
			tmp=dfs(P[i],min(a,flow[i]));
			flow[i]-=tmp;
			a-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int Dinic(){
	int f(0);
	while(bfs()) f+=dfs(S,inf);
	return f;
}
int c1[101][101],c2[101][101],c3[101][101],c4[101][101],c5[101][101],c6[101][101];
int sum(0);
#define get(i,j) ((i-1)*(m)+(j))
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tot=1;S=0,T=10204;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&c1[i][j]),sum+=c1[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&c2[i][j]),sum+=c2[i][j];
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++) scanf("%d",&c3[i][j]),sum+=c3[i][j];
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++) scanf("%d",&c4[i][j]),sum+=c4[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<m;j++) scanf("%d",&c5[i][j]),sum+=c5[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<m;j++) scanf("%d",&c6[i][j]),sum+=c6[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) add(S,get(i,j),c1[i][j]<<1),add(get(i,j),S,0),add(get(i,j),T,c2[i][j]<<1),add(T,get(i,j),0);
	for(int i=1;i<=n;i++) for(int j=1;j<m;j++) add(S,get(i,j),c5[i][j]),add(get(i,j),S,0),add(get(i,j),T,c6[i][j]),add(T,get(i,j),0), add(S,get(i,j+1),c5[i][j]),add(get(i,j+1),S,0),add(get(i,j+1),T,c6[i][j]),add(T,get(i,j+1),0),add(get(i,j),get(i,j+1),c5[i][j]+c6[i][j]),add(get(i,j+1),get(i,j),c5[i][j]+c6[i][j]);
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++) add(S,get(i,j),c3[i][j]),add(get(i,j),S,0),add(get(i,j),T,c4[i][j]),add(T,get(i,j),0), add(S,get(i+1,j),c3[i][j]),add(get(i+1,j),S,0),add(get(i+1,j),T,c4[i][j]),add(T,get(i+1,j),0),add(get(i,j),get(i+1,j),c3[i][j]+c4[i][j]),add(get(i+1,j),get(i,j),c3[i][j]+c4[i][j]);
	printf("%d\n",(sum*2-Dinic())>>1);
	return 0 ;
}
