#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
//  by zrt
//  problem:
//  ???è?o?????¨????1???????????§????é??è|??????ˉ????§???￥????°±???è|?????-￠???
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int m,n,S,T;
int t[65][11];
int H[2200],X[400000],P[400000],flow[400000],tot,cost[400000],from[400000];
int d[2200],p[2200],a[2200];
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;cost[tot]=k;from[tot]=x;
}
struct N{
	int x,w;
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
priority_queue<N> q;
int f,c;
bool spfa(){
	while(!q.empty()) q.pop();
	memset(d,0x3f,sizeof d);
	d[S]=0,p[S]=0,a[S]=inf;
	int u;q.push(N(S,0));
	while(!q.empty()){
		u=q.top().x;q.pop();
//		if(u==T) continue;
		for(int i=H[u];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[u]+cost[i]){
				d[P[i]]=d[u]+cost[i];
				a[P[i]]=min(flow[i],a[u]);
				p[P[i]]=i;
				q.push(N(P[i],d[P[i]]));
			}
		}
		while(!q.empty()&&d[q.top().x]!=q.top().w) q.pop();
	}
	if(d[T]==inf) return false;
	f+=a[T];
	c+=a[T]*d[T];
//	printf("$%d %d\n",a[T],d[T]);
	u=T;
	while(u!=S){
		flow[p[u]]-=a[T];
		flow[p[u]^1]+=a[T];
		u=from[p[u]];
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tot=1;
	S=1198,T=1188;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&t[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=1;j<=n;j++){
			add(S,i*100+j,1,0);
			add(i*100+j,S,0,0); 
			for(int k=0;k<n;k++){
				add(i*100+j,1000+k,1,j*t[k][i]);
				add(1000+k,i*100+j,0,-(j*t[k][i]));
			}
		}
	}
	for(int i=0;i<n;i++){
		add(1000+i,T,1,0);
		add(T,1000+i,0,0);
	}
	f=c=0;
	while(spfa());
	printf("%.2f\n",c/(double)n);
	return 0 ;
}
