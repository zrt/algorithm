#include<cstdio>
#include<queue>
#include <cstring>
using namespace std;
const int inf(0x3f3f3f3f);
int H[50],X[1000],P[1000],flow[1000],cost[1000],from[1000],tot;
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;cost[tot]=k;from[tot]=x;
}
int a[50],p[50],d[50];
int S,T;
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
queue<N> q;
int f,c;
bool spfa(){
	memset(d,0x3f,sizeof d);
	d[S]=0;a[S]=inf;
	q.push(S);int x;
	while(!q.empty()){
		x=q.front().x;q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
				d[P[i]]=d[x]+cost[i];
				a[P[i]]=min(a[x],flow[i]);
				p[P[i]]=i;
				q.push(N(P[i],d[P[i]]));
			}
		}
		while(!q.empty()&&d[q.front().x]!=q.front().w) q.pop();
	}
	if(d[T]==inf) return 0;
	f+=a[T];c+=a[T]*d[T];
	x=T;
	while(x!=S){
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
}
int main(){
	tot=1;
	S=0,T=2;
	int a,b;
	scanf("%d%d",&a,&b);
	add(S,1,1,a);add(1,S,0,-a);
	add(1,T,1,b);add(1,T,0,-b);
	while(spfa());
	printf("%d\n",c);
	return 0;
}
