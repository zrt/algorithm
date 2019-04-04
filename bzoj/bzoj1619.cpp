#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,m;
struct N{
	int x,y,z;
	friend bool operator < (N a,N b){
		return a.z>b.z;
	}
}a[490005];
bool vis[701][701];
int h[701][701];
int cc;
int xk[]={0,0,1,-1,1,1,-1,-1};
int yk[]={1,-1,0,0,1,-1,1,-1};
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<8;i++){
		int xx=x+xk[i];
		int yy=y+yk[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&h[xx][yy]<=h[x][y]&&!vis[xx][yy]){
			dfs(xx,yy);
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[++cc].z);
			h[i][j]=a[cc].z;
			a[cc].x=i;
			a[cc].y=j;
		}
	}
	sort(a+1,a+cc+1);
	int ans=0;
	for(int i=1;i<=cc;i++){
		if(!vis[a[i].x][a[i].y]){
			ans++;
			dfs(a[i].x,a[i].y);
		}
	}
	printf("%d\n",ans);
	return 0;
}
