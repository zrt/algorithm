#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-8) ;
const int inf(0x3fffffff) ;
int n,m,p,S,T;
double M;
int H[105],X[2005],P[2005];double flow[2005];int tot,cap[2005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;cap[tot]=flow[tot]=z;
}
struct N{
	int x,y,z;
}a[1005];
queue<int > q;
int d[105];
bool bfs(){
	memset(d,0,sizeof d);
	int k;
	d[S]=1;q.push(S);
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
double dfs(int x,double a){
	if(x==T||a<eps) return a;
	double f=a, tmp;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(flow[i],a));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(a<=0) break;
		}
	}
	if((fabs(f-a)<eps)) d[x]=-1;
	return f-a;
}
double Dinic(){
	double ff(0);
	while(bfs())ff+=dfs(S,inf);
	return ff;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tot=1;
	scanf("%d%d%d",&n,&m,&p);
	S=1,T=n;
	int maxe=0;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		add(a[i].x,a[i].y,a[i].z);
		add(a[i].y,a[i].x,0);
		maxe=max(maxe,a[i].z);
	}
	M=inf;
	double maxflow=Dinic();
	double l=-1,r=maxe;
	for(int tt=0;tt<27;tt++){
		M=(l+r)/2.0;
		for(int i=1;i<=n;i++){
			for(int j=H[i];j;j=X[j]){
				flow[j]=min((double)cap[j],M);
			}
		}
		if(fabs(Dinic()-maxflow)<eps){
			r=M;
		}else l=M;
	}
	printf("%.0f\n%.5f\n",maxflow,r*(double)p);
	return 0 ;
}
