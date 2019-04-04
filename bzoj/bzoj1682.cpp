#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int H[2005],X[20005],P[20005];
LL E[20005];
LL d[2005];
int tot;
inline void add(int x,int y,LL z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int n,m;
int x,y;
LL z;
struct N{
	int x;
	LL w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
bool vis[2005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	memset(d,0x3f,sizeof d);
	for(int i=0;i<m;i++){
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	d[1]=0;
	q.push(N(1,0));
	while(!q.empty()){
		x=q.top().x;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>max(d[x],E[i])){
				d[P[i]]=max(d[x],E[i]);
				q.push(N(P[i],d[P[i]]));
			}
		}
	}
	LL ans=0;
	for(int i=2;i<=n;i++) ans=max(ans,d[i]);
	printf("%lld\n",ans);
	return 0;
}
