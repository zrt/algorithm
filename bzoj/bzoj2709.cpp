#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef double ld;
int tt;
int n,m;
char s[305][305];
ld d[305][305];
ld L;
struct N{
	int x,y;
	ld w;
	N(int a=0,int b=0,ld c=0){
		x=a,y=b,w=c;
	}
	friend bool operator < (const N&a,const N&b){
		return a.w>b.w;
	}
}t;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool check(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
priority_queue<N> q;
bool judge(ld v){
	int sx,sy;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) d[i][j]=1e100;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='S') sx=i,sy=j;
	d[sx][sy]=0;
	q.push(N(sx,sy,0));
	while(!q.empty()){
		t=q.top();q.pop();
		int x=t.x,y=t.y;
		for(int k=0;k<2;k++){//1
			int xx=x+dx[k],yy=y+dy[k];
			if(!check(xx,yy)) continue;
			if(s[xx][yy]=='#') continue;
			if(d[xx][yy]>d[x][y]+1){
				d[xx][yy]=d[x][y]+1;
				q.push(N(xx,yy,d[xx][yy]));
			}
		}
		for(int k=2;k<4;k++){//v
			int xx=x+dx[k],yy=y+dy[k];
			if(!check(xx,yy)) continue;
			if(s[xx][yy]=='#') continue;
			if(d[xx][yy]>d[x][y]+v){
				d[xx][yy]=d[x][y]+v;
				q.push(N(xx,yy,d[xx][yy]));
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		if(s[i][j]=='E') return d[i][j]<L;
	}
}
int main(){
	scanf("%d",&tt);
	while(tt--){
		scanf("%lf%d%d\n",&L,&n,&m);
		for(int i=1;i<=n;i++) gets(s[i]+1);
		ld l=0,r=10;
		for(int t=0;t<35;t++){
			ld mid=(l+r)/2;
			if(judge(mid)) l=mid;
			else r=mid;
		}
		printf("%.5f\n",l);
	}
	return 0;
}
