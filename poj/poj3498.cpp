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
int n,S,T;double d;
int x[105],y[105],ni[105],mi[105];
int H[205],X[85000],P[85000],tot,flow[85000],tott,floww[85000],xx[85000],h[205];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int D[205];
queue<int> q;
bool bfs(){
	memset(D,0,sizeof D);
	D[S]=1;int x;q.push(S);
	while(!q.empty()){
		x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&!D[P[i]]){
				D[P[i]]=D[x]+1;
				q.push(P[i]);
			}
		}
	}
	return D[T];
}
int dfs(int x,int a){
	if(x==T||a==0) return a;
	int f=a,tmp;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&D[P[i]]==D[x]+1){
			tmp=dfs(P[i],min(flow[i],a));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a ) D[x]=-1;
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
	scanf("%d",&tt);
	S=0,T=204;
	while(tt--){
		tot=1;
		memset(H,0,sizeof H);
		scanf("%d%lf",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d%d",&x[i],&y[i],&ni[i],&mi[i]);
		}
		bool ok=1;
		int sum(0);
		// x<<1 x<<1|1
		for(int i=1;i<=n;i++){
			if(mi[i]) add(S,i<<1,ni[i]),add(i<<1,S,0),sum+=ni[i];
			add(i<<1,i<<1|1,mi[i]);add(i<<1|1,i<<1,0);
		}
		d=d*d;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=d){
					add(i<<1|1,j<<1,inf);add(j<<1,i<<1|1,0);
					add(j<<1|1,i<<1,inf);add(i<<1,j<<1|1,0);
				}
			}
		}
		tott=tot;
		int maxflow;
		memcpy(h,H,sizeof H);
		memcpy(xx,X,sizeof X);
		memcpy(floww,flow,sizeof flow);
		for(int i=1;i<=n;i++){
			tot=tott;
 
			memcpy(H,h,sizeof H);memcpy(X,xx,sizeof X);memcpy(flow,floww,sizeof flow);
			add(i<<1,T,inf);add(T,i<<1,0);
			if((maxflow=Dinic())>=sum){
				if(ok) ok=0;else putchar(' '); printf("%d",i-1);
			}
		}
		if(ok) puts("-1");else puts("");
	}
	return 0 ;
}
 