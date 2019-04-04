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
int n,m,k;
int ci[100],fi[100];
//stu 1...100 101...m 
int H[205],X[3000000],P[3000000],tot,cost[3000000],from[3000000],flow[3000000];
int S,T;
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;cost[tot]=k;from[tot]=x;
}
int f,c;
int a[205],p[205],d[205];
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
bool spfa(){
	memset(d,0x3f,sizeof d);
	d[S]=0,a[S]=inf,p[S]=0;int x;
	q.push(N(S,0));
	while(!q.empty()){
		x=q.top().x;q.pop();
		if(x==T) continue; 
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
				d[P[i]]=d[x]+cost[i];
				a[P[i]]=min(a[x],flow[i]);
				p[P[i]]=i;
				q.push(N(P[i],d[P[i]]));
			}
		}
		while(!q.empty()&&d[q.top().x]!=q.top().w) q.pop();
	}
	if(d[T]==inf) return 0;
	f+=a[T];
	c+=a[T]*d[T];
	x=T;
	while(x!=S){
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	return 1;
}
bool spfa2(){
	memset(d,0x3f,sizeof d);
	d[S]=0,a[S]=inf,p[S]=0;int x;
	q.push(N(S,0));
	while(!q.empty()){
		x=q.top().x;q.pop();
		if(x==T) continue; 
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
				d[P[i]]=d[x]+cost[i];
				a[P[i]]=min(a[x],flow[i]);
				p[P[i]]=i;
				q.push(N(P[i],d[P[i]]));
			}
		}
		while(!q.empty()&&d[q.top().x]!=q.top().w) q.pop();
	}
	if(d[T]>=0) return 0;
	f+=a[T];
	c+=a[T]*d[T];
	x=T;
	while(x!=S){
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	return 1;
}
char s[150];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tot=1;S=0,T=204;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		add(S,i,1,0);
		add(i,S,0,0);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&ci[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&fi[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			if(s[j]-'0') add(i,j+100,1,-fi[j]),add(j+100,i,0,fi[j]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			add(i+100,T,1,ci[i]*(j*j-(j-1)*(j-1)));
			add(T,i+100,0,-ci[i]*(j*j-(j-1)*(j-1)));
		}
	}
	while(spfa());
	for(int i=1;i<=n;i++){
		add(S,i,k-1,0);
		add(i,S,0,0);
	}
	while(spfa2());
	printf("%d\n",c);
	return 0 ;
}
