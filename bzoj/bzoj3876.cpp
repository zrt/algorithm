#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int H[305],	X[50000],P[50000],tot=1,cost[50000],flow[50000],from[50000];
int a[305],p[305];
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;cost[tot]=k;flow[tot]=z;from[tot]=x;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;cost[tot]=-k;flow[tot]=0;from[tot]=y;
}
int Cost;
int S=303,T=304;
int d[305];
bool inq[305];
queue<int> q;
const int inf=0x3f3f3f3f;
bool spfa(){
	memset(d,0x3f,sizeof d);
	d[S]=0;a[S]=inf;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		inq[x]=0;
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
				d[P[i]]=d[x]+cost[i];
				a[P[i]]=min(a[x],flow[i]);
				p[P[i]]=i;
				if(!inq[P[i]]) inq[P[i]]=1,q.push(P[i]);
			}
		}
	}
	if(d[T]==0x3f3f3f3f) return 0;
	Cost+=a[T]*d[T];
	int x=T;
	//puts("HAHA");
	while(x!=S){
	//	printf("%d\n",x);
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1,k,x,y;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&x,&y);
			add(i,x,inf,y);
			add(S,x,1,y);
			add(i,T,1,0);
		}
		if(i!=1) add(i,1,inf,0);
	}
	while(spfa());
	printf("%d\n",Cost);
	return 0;
}
