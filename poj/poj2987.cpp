#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
//  by zrt
//  problem:
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const LL inf(0x3f3f3f3f3f3f3f3f) ;
LL n,m;
LL val[5005];
LL S,T;
LL sum;
LL H[5005],X[150000],P[150000],tot,flow[150000];
inline void add(LL x,LL y,LL z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
LL d[5005];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);LL x;
	while(!q.empty()){
		x=q.front();q.pop();
		for(LL i=H[x];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	return d[T];
}
LL dfs(LL x,LL a){
	if(x==T||a==0) return a;
	LL f=a,tmp;
	for(LL i=H[x];i;i=X[i]){
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
LL Dinic(){
	LL f(0);
	while(bfs()) f+=dfs(S,inf);
	return f;
}
LL ans=0;
bool vis[5005];
void dfs(LL x){
	vis[x]=1;ans++;
	for(LL i=H[x];i;i=X[i]){
		if(flow[i]>0&&!vis[P[i]]){
			dfs(P[i]);
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%lld%lld",&n,&m);
	S=0,T=n+1;
	tot=1;
	for(LL i=1;i<=n;i++) {
		scanf("%lld",&val[i]);
		if(val[i]>0){
			sum+=val[i];add(S,i,val[i]);add(i,S,0);
		}else if(val[i]<0){
			add(i,T,-val[i]);add(T,i,0);
		}
	}
	for(LL i=0,x,y;i<m;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y,inf);
		add(y,x,0);
	}
	LL maxflow=Dinic();
	dfs(S);
	printf("%lld %lld\n",ans-1,sum-maxflow);
	return 0 ;
}
