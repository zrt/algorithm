/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
int t[350][350];
int ans=-1;
int d[350][350];
struct N{
	int x,y;
	N(int a=0,int b=0){
		x=a,y=b;
	}
}p;
int xk[]={0,0,-1,1};
int yk[]={1,-1,0,0};
queue<N> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int m;
	memset(t,0x3f,sizeof t);
	scanf("%d",&m);
	int x,y,z;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		t[x][y]=min(t[x][y],z);
		for(int k=0;k<4;k++){
			int X=x+xk[k],Y=y+yk[k];
			if(X>=0&&Y>=0){
				t[X][Y]=min(t[X][Y],z);
			} 
		}
	}
	q.push(N(0,0));d[0][0]=1;
	while(!q.empty()){
		p=q.front();q.pop();
		x=p.x;y=p.y;
		for(int k=0;k<4;k++){
			int X=x+xk[k],Y=y+yk[k];
			if(X>=0&&Y>=0&&!d[X][Y]&&d[x][y]<t[X][Y]){
				d[X][Y]=d[x][y]+1;
				if(t[X][Y]==0x3f3f3f3f){
					ans=d[x][y];goto ed;
				}
				q.push(N(X,Y));
			} 
		}
	}
	ed:;
	printf("%d\n",ans);
	return 0;
}
