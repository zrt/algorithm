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
int n,m;
int ai[101][101],bi[101][101],ci[101][101];
int H[11000],P[100005],X[100005],flow[100005],tot,S,T;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
queue<int> q;
int d[11000];
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;int k;q.push(S);
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
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a)break;
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
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tot=1;S=0,T=10009;
	scanf("%d%d",&n,&m);
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&ai[i][j]);
		//	sum+=ai[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&bi[i][j]);
	//		sum+=bi[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&ci[i][j]);
		//	sum+=ci[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum+=ai[i][j]+bi[i][j];
			if((i+j)&1){
				add(S,(i-1)*m+j,ai[i][j]);
				add((i-1)*m+j,S,0);
				add((i-1)*m+j,T,bi[i][j]);
				add(T,(i-1)*m+j,0);
			}else{
				add(S,(i-1)*m+j,bi[i][j]);
				add((i-1)*m+j,S,0);
				add((i-1)*m+j,T,ai[i][j]);
				add(T,(i-1)*m+j,0);
			}
			if(i<n){
				add((i-1)*m+j,i*m+j,ci[i][j]+ci[i+1][j]);
				add(i*m+j,(i-1)*m+j,ci[i][j]+ci[i+1][j]);
				sum+=ci[i][j]+ci[i+1][j];
			}
			if(j<m){
				add((i-1)*m+j,(i-1)*m+j+1,ci[i][j]+ci[i][j+1]);
				add((i-1)*m+j+1,(i-1)*m+j,ci[i][j]+ci[i][j+1]);
				sum+=ci[i][j]+ci[i][j+1];
			}
		}
	}
	printf("%d\n",sum-Dinic());
	return 0 ;
}
