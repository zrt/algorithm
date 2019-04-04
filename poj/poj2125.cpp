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
int w1[1050],w2[1050];
int H[2005],X[800000],P[800000],tot,flow[800000];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int S,T;
int d[2050];
bool belong[2050];
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
void dfs1(int x){
	belong[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&!belong[P[i]]){
			dfs1(P[i]);
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	S=0,T=1;
	tot=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w1[i]),add(i<<1|1,T,w1[i]),add(T,i<<1|1,0);
	for(int j=1;j<=n;j++) scanf("%d",&w2[j]),add(S,j<<1,w2[j]),add(j<<1,S,0);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x<<1,y<<1|1,inf);
		add(y<<1|1,x<<1,0);
	}
	printf("%d\n",Dinic());
	int num(0);
	dfs1(S);
	for(int i=1;i<=n;i++){
		if(!belong[i<<1]) num++;
		if(belong[i<<1|1]) num++;
	}
	printf("%d\n",num);
	for(int i=1;i<=n;i++){
		if(!belong[i<<1]) printf("%d -\n",i);
		if(belong[i<<1|1]) printf("%d +\n",i);
	}
	return 0 ;
}
