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
int n,k;
int S,T;
int mat[55][55];
#define get(x,y) (((x)-1)*n+(y))
int H[6025],X[90000000],P[90000000],flow[90000000],from[90000000],cost[90000000],tot;
int f,c;
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;cost[tot]=k;from[tot]=x;
}
int a[6025],p[6025],d[6025];
struct N{
	int x,w;
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
queue<N> q;
bool spfa(){
	memset(d,0x3f,sizeof d);
	d[S]=0;a[S]=inf;int x;q.push(N(S,0));
	while(!q.empty()){
		x=q.front().x;q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
				d[P[i]]=d[x]+cost[i];
				p[P[i]]=i;
				a[P[i]]=min(a[x],flow[i]);
				q.push(N(P[i],d[P[i]]));
			}
		}
		while(!q.empty()&&d[q.front().x]!=q.front().w) q.pop();
	}
	if(d[T]==inf ) return 0;
//	printf("%d\n",a[T]);
	x=T;
	f+=a[T];c+=a[T]*d[T];
	while(x!=S){
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tot=1;
	scanf("%d%d",&n,&k);
	S=0,T=get(n,n)<<1|1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j<n){
				add(get(i,j)<<1|1,get(i,j+1)<<1,inf,0);
				add(get(i,j+1)<<1,get(i,j)<<1|1,0,0);
			}
			if(i<n){
				add(get(i,j)<<1|1,get(i+1,j)<<1,inf,0);
				add(get(i+1,j)<<1,get(i,j)<<1|1,0,0);
			}
			add(get(i,j)<<1,get(i,j)<<1|1,1,-mat[i][j]);
			add(get(i,j)<<1|1,get(i,j)<<1,0,mat[i][j]);
			add(get(i,j)<<1,get(i,j)<<1|1,inf,0);
			add(get(i,j)<<1|1,get(i,j)<<1,0,0);
		}
	}
	add(S,get(1,1)<<1,k,0);
	add(get(1,1)<<1,S,0,0);
	while(spfa());
	printf("%d\n",-c);
	return 0 ;
}
