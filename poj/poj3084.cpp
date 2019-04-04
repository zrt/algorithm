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
int tt;
int n,S,T,k;
int H[21],X[1000],P[1000],tot,flow[1000];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[21];
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
	while(f<=inf-1&&bfs()) f+=dfs(S,inf);
	return f;
}
char s[10];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d",&tt);S=20;
	while(tt--){
		scanf("%d%d",&n,&T);
		tot=1;memset(H,0,sizeof H);
		for(int i=0;i<n;i++){
			scanf("%s%d",s,&k);
			if(s[0]=='I') add(S,i,inf),add(i,S,0);
			for(int j=0,x;j<k;j++){
				scanf("%d",&x);
				add(i,x,inf);
				add(x,i,1);
			}
		}
		int ans=Dinic();
		if(ans>10000) puts("PANIC ROOM BREACH");
		else printf("%d\n",ans);
	}
	return 0 ;
}
