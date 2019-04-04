#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int m,n,pb,pa1,pa2;
int H[100005],X[400005],P[400005],E[400005],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
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
int d[100005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d%d%d",&m,&n,&pb,&pa1,&pa2);
	int ans=inf;
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	memset(d,0x3f,sizeof d);
	d[pa1]=0;
	q.push(N(pa1,0));
	while(!q.empty()){
		int x=q.top().x;q.pop();
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				q.push(N(P[i],d[P[i]]));
			}
		}
	}
	ans=min(ans,d[pa2]+d[pb]);
	memset(d,0x3f,sizeof d);
	d[pa2]=0;
	q.push(N(pa2,0));
	while(!q.empty()){
		int x=q.top().x;q.pop();
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				q.push(N(P[i],d[P[i]]));
			}
		}
	}
	ans=min(ans,d[pa1]+d[pb]);
	printf("%d\n",ans);
	return 0;
}
