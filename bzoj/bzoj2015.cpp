#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long LL;
struct N{
	int x;LL w;
	N(int a=0,LL b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
int H[50005],X[200005],P[200005],tot;
LL E[200005];
inline void add(int x,int y,LL z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int n,m,b;
LL d[50005];
bool vis[50005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&m,&b);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	memset(d,0x3f,sizeof d);
	d[1]=0;q.push(N(1,0));
	int x;
	while(!q.empty()){
		x=q.top().x;q.pop();
		if(vis[x] ) continue;
		vis[x]=1;
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				q.push(N(P[i],d[P[i]]));
			}
		}
	}
	for(int i=0,x,y;i<b;i++){
		scanf("%d%d",&x,&y);
		printf("%lld\n",d[x]+d[y]);
	}
	return 0;
}
