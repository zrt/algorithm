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
int n,m;
int map[40][40];
int d[40][40];
LL g[40][40];
int dx[]={1,1,-1,-1,2,-2,2,-2};
int dy[]={2,-2,2,-2,1,1,-1,-1};
struct N{
	int x,y;
	int w;
	N(int a=0,int b=0,int c=0){
		x=a,y=b,w=c;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
bool vis[40][40];
int w(int x,int y){
	if(map[x][y]==2) return 0x3fffffff;
	if(map[x][y]==0) return 10000;
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&map[i][j]);
	memset(d,0x3f,sizeof d);
	int sx,sy,ex,ey;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(map[i][j]==3) sx=i,sy=j;else if(map[i][j]==4) ex=i,ey=j;
	d[sx][sy]=0;
	g[sx][sy]=1;
	q.push(N(sx,sy,0));
	while(!q.empty()){
		int x=q.top().x,y=q.top().y;q.pop();
		if(vis[x][y]) continue;
		else vis[x][y]=1;
		for(int k=0;k<8;k++){
			int xx=x+dx[k];
			int yy=y+dy[k];
			if(xx<=0||xx>n||yy<=0||yy>m) continue;
			if(d[xx][yy]==d[x][y]+w(xx,yy)){
				g[xx][yy]+=g[x][y];
			}else if(d[xx][yy]>d[x][y]+w(xx,yy)){
				g[xx][yy]=g[x][y];
				d[xx][yy]=d[x][y]+w(xx,yy);
				q.push(N(xx,yy,d[xx][yy]));
			}
		}
	}
	if(d[ex][ey]==0x3f3f3f3f) puts("-1");
	else printf("%d\n%d\n%lld\n",d[ex][ey]/10000,d[ex][ey]/10000+d[ex][ey]%10000,g[ex][ey]);
	return 0;
}
