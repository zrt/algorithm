#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int H[450],X[85000],P[85000],flow[85000],tot=1,cost[85000],from[85000];
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;from[tot]=x;flow[tot]=z;cost[tot]=k;
}
int S=448,T=449;
int a[450],p[450],d[450];
queue<int> q;
int inf=400,ff,cc;
bool inq[450];
bool spfa(){
	memset(d,0x3f,sizeof d);
	memset(a,0,sizeof a);
	d[S]=0;a[S]=inf;
	q.push(S);
	inq[S]=1;
	while(!q.empty()){
		int x=q.front();q.pop();inq[x]=0;
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
				d[P[i]]=d[x]+cost[i];
				a[P[i]]=min(flow[i],a[x]);
				p[P[i]]=i;
				if(!inq[P[i]])q.push(P[i]),inq[P[i]]=1;
			}
		}
	}
	if(!a[T]) return 0;
	ff+=a[T];
	cc+=a[T]*d[T];
	int x=T;
	while(x!=S){
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1,m,a,b,k;i<=n;i++){
		scanf("%d%d%d%d",&m,&a,&b,&k);
		add(S,i<<1,1,0);
		add(i<<1,S,0,0);
		for(int j=a;j<=b;j++){
			add(i<<1,j<<1|1,1,k*abs(m-j));
			add(j<<1|1,i<<1,0,-k*abs(m-j));
		}
		add(i<<1|1,T,1,0);
		add(T,i<<1|1,0,0);
	}
	while(spfa());
	if(ff==n){
		printf("%d\n",cc);
	}else{
		puts("NIE");
	}
	return 0;
}
