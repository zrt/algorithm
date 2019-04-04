/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
//by zrt
//problem:
using namespace std;
int X,Y,n,dis[1005][1005];
bool map[1005][1005];
struct N{
	int x,y;
	N(int a=0,int b=0){
		x=a,y=b;
	}
}tmp;
N q[1000000];int h,t;
int xk[]={0,0,1,-1},yk[]={1,-1,0,0};
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&X,&Y,&n);
	X+=500;Y+=500;
	int a,b;
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		map[a+500][b+500]=1;
	}
	q[t++]=N(500,500);
	dis[500][500]=1;
	int x,y;
	while(h!=t){
		tmp=q[h++];
		if(tmp.x==X&&tmp.y==Y) break;
		for(int k=0;k<4;k++){
			x=tmp.x+xk[k];
			y=tmp.y+yk[k];
			if(x>=0&&x<=1000&&y>=0&&y<=1000&&!map[x][y]&&!dis[x][y]){
				dis[x][y]=dis[tmp.x][tmp.y]+1;q[t++]=N(x,y);
			}
		}
	}
	printf("%d\n",dis[X][Y]-1);
	return 0;
}
