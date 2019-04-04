#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k;
int a[1005];
int sum;
int H[1005],X[40005],P[40005],flow[40005],cost[40005],from[40005],tot=1;
int S=1003,T=1004;
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;cost[tot]=k;from[tot]=x;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;cost[tot]=-k;from[tot]=y;
}
int _cost;
int d[1005],p[1005];
const int inf=0x3f3f3f3f;
queue<int> q;
bool spfa(){
	memset(d,0x3f,sizeof d);
	d[S]=0;a[S]=inf;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
				d[P[i]]=d[x]+cost[i];
				a[P[i]]=min(a[x],flow[i]);
				p[P[i]]=i;
				q.push(P[i]);
			}
		}
	}
	if(d[T]==inf) return 0;
	_cost+=a[T]*d[T];
	int x=T;
	while(x!=S){
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k>=m){
		for(int i=1,x;i<=n;i++){
			scanf("%d",&x);
			sum+=x;
		}
		printf("%d\n",sum);
	}else{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=k;i++) add(S,i,1,0);
		for(int i=1;i<=n-m;i++){
			add(i,i+m,1,-a[i]);
		}
		for(int i=n-m+1;i<=n;i++){
			add(i,T,1,-a[i]);
		}
		add(n,T,k,0);
		for(int i=1;i<n;i++) add(i,i+1,inf,0);
		while(spfa());
		printf("%d\n",-_cost);
	}
	return 0;
}
