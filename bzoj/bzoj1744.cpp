#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int n,m;
int h[105][105];
int v;
double d[105][105];
struct N{
	int x,y;
	N(int a=0,int b=0){
		x=a,y=b;
	}
};
bool inq[105][105];
queue<N> q; 
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&v,&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) scanf("%d",&h[i][j]),d[i][j]=1e100;
	}
	d[1][1]=0;
	q.push(N(1,1));
	inq[1][1]=1;
	while(!q.empty()){
		int x=q.front().x,y=q.front().y;
		q.pop();
		inq[x][y]=0;
		double tmp=1/((double)v*pow(2.0,h[1][1]-h[x][y]));
		for(int k=0;k<4;k++){
			int xx=x+dx[k];
			int yy=y+dy[k];
			if(xx>0&&xx<=n&&yy>0&&yy<=m){
				if(d[xx][yy]>d[x][y]+tmp){
					d[xx][yy]=d[x][y]+tmp;
					if(!inq[xx][yy]){
						q.push(N(xx,yy));
					}
				}
			}
		}
	}
	printf("%.2f\n",d[n][m]);
	return 0;
}
