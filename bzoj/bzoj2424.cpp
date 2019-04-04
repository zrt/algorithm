#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int H[105],X[500005],P[500005],flow[500005],cost[500005],from[500005],tot=1;
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;cost[tot]=k;from[tot]=x;
}
int S,T;
const int inf=5000000;
int n,m,s;
long long costs;
int u[55];
int w[55];
int a[105],d[105],p[105];
bool inq[105];
queue<int> q;
bool spfa(){
	memset(d,0x3f,sizeof d);
	memset(a,0,sizeof a);
	d[S]=0;a[S]=inf;inq[S]=1;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
	//	printf("%d\n",x);
		inq[x]=0;
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
				d[P[i]]=d[x]+cost[i];
				a[P[i]]=min(a[x],flow[i]);
				p[P[i]]=i;
				if(!inq[P[i]])q.push(P[i]),inq[P[i]]=1;
			}
		}
	}
	if(a[T]==0) return 0;
	costs+=a[T]*d[T];
	int k=T;
	while(k!=S){
		flow[p[k]]-=a[T];
		flow[p[k]^1]+=a[T];
		k=from[p[k]];
	}
	return 1;
}
int main(){
	S=103,T=104;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n;i++) scanf("%d",&u[i]);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		add(S,i<<1,inf,w[i]);
		add(i<<1,S,0,-w[i]);
		add(i<<1|1,T,u[i],0);
		add(T,i<<1|1,0,0);
		add(i<<1,i<<1|1,inf,0);
		add(i<<1|1,i<<1,0,0);
		if(i<n) add(i<<1|1,(i+1)<<1,s,m),add((i+1)<<1,i<<1|1,0,-m);
	}
	while(spfa());
	printf("%lld\n",costs);
	return 0;
}
