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
int d1[355][155][155];//h,x,y
int d2[355][155][155];
int d3[355][155][155];
bool vis[355][155][155];
struct N{
	int h,x,y,d;
	N(int h=0,int x=0,int y=0,int d=0){
		this->h=h;this->x=x;this->y=y;this->d=d;
	}
	friend bool operator < (N a,N b){
		return a.d>b.d;
	}
};
priority_queue<N> q;
int n,m;
int h[155][155];
int c[155][155];
int maxx;
int xk[]={0,0,1,-1,0};
int yk[]={1,-1,0,0,0};
int x1,y1,x2,y2,x3,y3;
N t;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	memset(d1,0x3f,sizeof d1);
	memset(d2,0x3f,sizeof d2);
	memset(d3,0x3f,sizeof d3);
	scanf("%d%d",&n,&m);
	maxx=n+m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&h[i][j]);
			h[i][j]=min(h[i][j],maxx);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&c[i][j]);
		}
	}
	
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	d1[0][x1][y1]=d2[0][x2][y2]=d3[0][x3][y3]=0;
	q.push(N(0,x1,y1,0));
	while(!q.empty()){
		t=q.top();q.pop();
		if(vis[t.h][t.x][t.y]) continue;
		vis[t.h][t.x][t.y]=1;
		if(vis[0][x1][y1]&&vis[0][x2][y2]&&vis[0][x3][y3]) break;
		if(t.h){
			int x;int y;
			for(int i=0;i<5;i++){
				x=t.x+xk[i];y=t.y+yk[i];
				if(x>0&&y>0&&x<=n&&y<=m&&!vis[t.h-1][x][y]){
					if(d1[t.h-1][x][y]>d1[t.h][t.x][t.y]){
						d1[t.h-1][x][y]=d1[t.h][t.x][t.y];
						q.push(N(t.h-1,x,y,d1[t.h-1][x][y]));
					}
				}
			}
		}else{
			if(!vis[h[t.x][t.y]][t.x][t.y]&&d1[h[t.x][t.y]][t.x][t.y]>d1[t.h][t.x][t.y]+c[t.x][t.y]){
				d1[h[t.x][t.y]][t.x][t.y]=d1[t.h][t.x][t.y]+c[t.x][t.y];
				q.push(N(h[t.x][t.y],t.x,t.y,d1[h[t.x][t.y]][t.x][t.y]));
			}
		}
	}
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof vis);
	q.push(N(0,x2,y2,0));
	while(!q.empty()){
		t=q.top();q.pop();
		if(vis[t.h][t.x][t.y]) continue;
		vis[t.h][t.x][t.y]=1;
		if(vis[0][x1][y1]&&vis[0][x2][y2]&&vis[0][x3][y3]) break;
		if(t.h){
			int x;int y;
			for(int i=0;i<5;i++){
				x=t.x+xk[i];y=t.y+yk[i];
				if(x>0&&y>0&&x<=n&&y<=m&&!vis[t.h-1][x][y]){
					if(d2[t.h-1][x][y]>d2[t.h][t.x][t.y]){
						d2[t.h-1][x][y]=d2[t.h][t.x][t.y];
						q.push(N(t.h-1,x,y,d2[t.h-1][x][y]));
					}
				}
			}
		}else{
			if(!vis[h[t.x][t.y]][t.x][t.y]&&d2[h[t.x][t.y]][t.x][t.y]>d2[t.h][t.x][t.y]+c[t.x][t.y]){
				d2[h[t.x][t.y]][t.x][t.y]=d2[t.h][t.x][t.y]+c[t.x][t.y];
				q.push(N(h[t.x][t.y],t.x,t.y,d2[h[t.x][t.y]][t.x][t.y]));
			}
		}
	}
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof vis);
	q.push(N(0,x3,y3,0));
	while(!q.empty()){
		t=q.top();q.pop();
		if(vis[t.h][t.x][t.y]) continue;
		vis[t.h][t.x][t.y]=1;
		if(vis[0][x1][y1]&&vis[0][x2][y2]&&vis[0][x3][y3]) break;
		if(t.h){
			int x;int y;
			for(int i=0;i<5;i++){
				x=t.x+xk[i];y=t.y+yk[i];
				if(x>0&&y>0&&x<=n&&y<=m&&!vis[t.h-1][x][y]){
					if(d3[t.h-1][x][y]>d3[t.h][t.x][t.y]){
						d3[t.h-1][x][y]=d3[t.h][t.x][t.y];
						q.push(N(t.h-1,x,y,d3[t.h-1][x][y]));
					}
				}
			}
		}else{
			if(!vis[h[t.x][t.y]][t.x][t.y]&&d3[h[t.x][t.y]][t.x][t.y]>d3[t.h][t.x][t.y]+c[t.x][t.y]){
				d3[h[t.x][t.y]][t.x][t.y]=d3[t.h][t.x][t.y]+c[t.x][t.y];
				q.push(N(h[t.x][t.y],t.x,t.y,d3[h[t.x][t.y]][t.x][t.y]));
			}
		}
	}
	int ans=inf;
	int which;
	//1
	if(d1[0][x1][y1]!=inf&&d2[0][x1][y1]!=inf&&d3[0][x1][y1]!=inf){
		if(d1[0][x1][y1]+d2[0][x1][y1]+d3[0][x1][y1]<ans){
			ans=d1[0][x1][y1]+d2[0][x1][y1]+d3[0][x1][y1];
			which=1;
		}
	}
	//2
	if(d1[0][x2][y2]!=inf&&d2[0][x2][y2]!=inf&&d3[0][x2][y2]!=inf){
		if(d1[0][x2][y2]+d2[0][x2][y2]+d3[0][x2][y2]<ans){
			ans=d1[0][x2][y2]+d2[0][x2][y2]+d3[0][x2][y2];
			which=2;
		}
	}
	//3
	if(d1[0][x3][y3]!=inf&&d2[0][x3][y3]!=inf&&d3[0][x3][y3]!=inf){
		if(d1[0][x3][y3]+d2[0][x3][y3]+d3[0][x3][y3]<ans){
			ans=d1[0][x3][y3]+d2[0][x3][y3]+d3[0][x3][y3];
			which=3;
		}
	}
	if(ans==inf) puts("NO");
	else {
		switch(which){
			case 1:puts("X");break;
			case 2:puts("Y");break;
			case 3:puts("Z");break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
