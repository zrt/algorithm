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
int n,b;
int S,T;
int H[1030],X[45000],P[45000],tot,flow[45000];
int order[1005][25];
int rank[1005][25];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int val[25];
int d[1030];
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
	return f-a;
}
int Dinic(){
	int f=0;
	while(bfs()) f+=dfs(S,inf);
	return f;
}
bool judge(int ans){
	for(int i=1;i<=b-ans+1;i++){
		tot=1;memset(H,0,sizeof H);
		for(int j=1;j<=n;j++){
			add(S,j,1);add(j,S,0);
			for(int k=i;k<i+ans;k++){
				add(j,n+order[j][k],1);add(n+order[j][k],j,0);
			}
		}
		for(int j=1;j<=b;j++){
			add(n+j,T,val[j]);
			add(T,n+j,0);
		}
		if(Dinic()==n) return 1;
	}
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	S=1029,T=1028;
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b;j++){
			scanf("%d",&order[i][j]);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=b;j++){
//			order[i][rank[i][j]]=j;
//		}
//	}
	for(int i=1;i<=b;i++) scanf("%d",&val[i]);
	for(int ans=1;ans<=b;ans++){
		if(judge(ans)){
			printf("%d\n",ans);break;
		}
	}
	return 0 ;
}
