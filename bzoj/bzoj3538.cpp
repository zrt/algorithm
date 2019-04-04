#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
//by zrt

using namespace std;
typedef long long LL;
int n,m;
int H[10005],X[50005],P[50005],tot,w1[50005],w2[50005],from[50005];
inline void add(int x,int y,int z1,int z2){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;w1[tot]=z1;w2[tot]=z2;from[tot]=x;
}
bool vis[10005];
int d1[50005],d2[50005];
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
vector<N> v[10005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0,x,y,p,q;i<m;i++){
		scanf("%d%d%d%d",&x,&y,&p,&q);
		add(y,x,p,q);
	}
	memset(d1,0x3f,sizeof d1);
	memset(d2,0x3f,sizeof d2);
	d1[n]=d2[n]=0;
	q.push(N(n,0));
	while(!q.empty()){
		int x=q.top().x;q.pop();
		if(vis[x]) continue;
		else vis[x]=1;
		for(int i=H[x];i;i=X[i]){
			if(!vis[P[i]]&&d1[P[i]]>d1[x]+w1[i]){
				d1[P[i]]=d1[x]+w1[i];
				q.push(N(P[i],d1[P[i]]));
			}
		}
	}
	memset(vis,0,sizeof vis);
	q.push(N(n,0));
	while(!q.empty()){
		int x=q.top().x;q.pop();
		if(vis[x]) continue;
		else vis[x]=1;
		for(int i=H[x];i;i=X[i]){
			if(!vis[P[i]]&&d2[P[i]]>d2[x]+w2[i]){
				d2[P[i]]=d2[x]+w2[i];
				q.push(N(P[i],d2[P[i]]));
			}
		}
	}
	for(int i=1;i<=tot;i++){
		int w=0;
		if(d1[P[i]]-d1[from[i]]!=w1[i]) w++;
		if(d2[P[i]]-d2[from[i]]!=w2[i]) w++;
		v[P[i]].push_back(N(from[i],w));
	}
	memset(vis,0,sizeof vis);
	memset(d1,0x3f,sizeof d1);
	d1[1]=0;
	q.push(N(1,0));
	while(!q.empty()){
		int x=q.top().x;q.pop();
		if(vis[x]) continue;
		else vis[x]=1;
		for(int i=0;i<v[x].size();i++){
			if(!vis[v[x][i].x]&&d1[v[x][i].x]>d1[x]+v[x][i].w){
				d1[v[x][i].x]=d1[x]+v[x][i].w;
				q.push(N(v[x][i].x,d1[v[x][i].x]));
			}
		}
	}
	printf("%d\n",d1[n]);
	return 0;
}
