#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int S,T;
const int MAXN=250005,MAXM=2500050;
int H[MAXN],X[MAXM],P[MAXM],E[MAXM],tot,d[MAXN];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
inline int get(int x,int y){
	return (x-1)*n+y;
}
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (const N&a,const N&b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
bool vis[MAXN];
int main(){
	scanf("%d",&n);
	S=0,T=n*n+1;
	int w;
	for(int i=1;i<=n;i++)
		scanf("%d",&w),add(S,get(1,i),w);
	for(int i=1;i<n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&w),add(get(i,j),get(i+1,j),w);
	for(int i=1;i<=n;i++)
		scanf("%d",&w),add(get(n,i),T,w);
	for(int i=1;i<=n;i++){
		scanf("%d",&w);add(get(i,1),T,w);
		for(int j=2;j<=n;j++) scanf("%d",&w),add(get(i,j),get(i,j-1),w);
		scanf("%d",&w);add(S,get(i,n),w);
	}
	for(int i=1;i<=n;i++) scanf("%*d");
    for(int i=1;i<n;i++)
        for(int j=1;j<=n;j++) 
            scanf("%d",&w),add(get(i+1,j),get(i,j),w);
    for(int i=1;i<=n;i++) scanf("%d",&w);
    for(int i=1;i<=n;i++){
        scanf("%d",&w);
        for(int j=2;j<=n;j++) scanf("%d",&w),add(get(i,j-1),get(i,j),w);
        scanf("%d",&w);
    }
	
	memset(d,0x3f,sizeof d);
	q.push(N(S,0));
	d[S]=0;
	while(!q.empty()){
		int x=q.top().x;q.pop();
		if(vis[x]) continue;
		else vis[x]=1;
	//	printf("%d %d\n",x,d[x]);
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				q.push(N(P[i],d[P[i]]));
			}
		}
	}
	printf("%d\n",d[T]);
	return 0;
}
