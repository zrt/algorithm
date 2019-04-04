#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k;
int map[155][155];
const int inf=0x3f3f3f3f;
int H[355],X[600000],P[600000],tot=1,flow[600000],cost[600000],from[600000],d[355],p[355],a[355];
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;cost[tot]=k;from[tot]=x;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;cost[tot]=-k;from[tot]=y;
}
bool inq[355];
queue<int> q;
int S=353,T=354;
long long Cost;
bool spfa(){
	memset(d,0x3f,sizeof d);
	a[S]=inf;d[S]=0;q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		inq[x]=0;
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
				d[P[i]]=d[x]+cost[i];
				a[P[i]]=min(a[x],flow[i]);
				p[P[i]]=i;
				if(!inq[P[i]]) q.push(P[i]),inq[P[i]]=1;
			}
		}
	}
	if(d[T]==0x3f3f3f3f) return 0;
	Cost+=a[T]*d[T];
	int x=T;
	while(x!=S){
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	return 1;
}
int main(){
	memset(map,0x3f,sizeof map);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n;i++) map[i][i]=0;
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=map[y][x]=min(map[x][y],z);
	}
	for(int k=0;k<=n;k++){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}
		}
		if(k>0){
			for(int i=0;i<k;i++){
				add(i<<1,k<<1|1,inf,map[i][k]);
			}
		}
	}
	add(S,0,k,0);
	for(int i=1;i<=n;i++) add(S,i<<1,1,0),add(i<<1|1,T,1,0);
	while(spfa());
	printf("%lld\n",Cost);
	return 0;
}
