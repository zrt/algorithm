#include <cstdio>
#include <cstring>
#include <algorithm>
#include<queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int m,n,k;
int h[105],l[105];
int li[105],ci[105],S,T;
int sx[10005],sy[10005];
int H[300],X[30000],P[30000],tot,flow[30000];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
queue<int> q;
int d[300];
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
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int Dinic(){
	int ff(0);
	while(bfs()) ff+=dfs(S,inf);
	return ff;
}
int f[105][105];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tot=1;
	S=0,T=299;
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=m;i++) scanf("%d",&li[i]);
	for(int i=1;i<=n;i++) scanf("%d",&ci[i]);
	for(int i=0;i<k;i++){
		scanf("%d%d",&sx[i],&sy[i]);
		h[sx[i]]++;l[sy[i]]++;
		f[sx[i]][sy[i]]=1;
	}
	for(int i=1;i<=m;i++){
		if(li[i]>n-h[i]){
			puts("JIONG!");goto ed;
		}
	}
	for(int i=1;i<=n;i++){
		if(ci[i]>m-l[i]){
			puts("JIONG!");goto ed;
		}
	}
	for(int i=1;i<=m;i++){
		add(S,i,n-h[i]-li[i]);
		add(i,S,0);
	}
	for(int i=1;i<=n;i++){
		add(i+100,T,m-l[i]-ci[i]);
		add(T,i+100,0);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(!f[i][j]) {
				add(i,j+100,1);
				add(j+100,i,0);
			}
		}
	}
	printf("%d\n",n*m-k-Dinic());
	ed:;
	return 0 ;
}
