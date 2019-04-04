#include<iostream>
#include<cstdio>
#include<queue> 
#include<cstring>
//by zrt
//problem:
using namespace std;
char s[505][505];
int r,c;
int dis[505][505][3];//0 (1) 1 (2up)(2down) 2(2left)(2right)
struct N{
	int x,y,w;
	N(int a=0,int b=0,int c=0){
		x=a;y=b;w=c;
	}
};
queue<N> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d",&r,&c)==2&&r){
		while(!q.empty()) q.pop();
		memset(dis,0,sizeof dis);
		for(int i=1;i<=r;i++){
			scanf("%s",s[i]+1);
		}
		for(int i=0;i<=r+1;i++){
			s[i][0]=s[i][c+1]='#';
		}
		for(int i=0;i<=c+1;i++){
			s[0][i]=s[r+1][i]='#';
		}
		int tot=0;
		N t,tarjet;
		for(int i=r;i;i--){
			for(int j=c;j;j--){
				if(s[i][j]=='X'){
					tot++;t.x=i;t.y=j;
				}
				if(s[i][j]=='O'){
					tarjet.x=i;tarjet.y=j;
				}
			}
		}
		if(tot==1){
			t.w=0;
		}else{
			if(s[t.x+1][t.y]=='X'){
				t.w=1;
			}else if(s[t.x][t.y+1]=='X'){
				t.w=2;
			}
		}
		dis[t.x][t.y][t.w]=1;
		s[tarjet.x][tarjet.y]='.';
		q.push(t);
		while(!q.empty()){
			t=q.front();q.pop();
			if(t.x==tarjet.x&&t.y==tarjet.y&&t.w==0){
				break;
			}
			if(t.x==3&&t.y==2&&t.w==2){
				int k;
				k=1<<20;
			}
			if(t.w==0){
				if(t.x-2>0&&(!dis[t.x-2][t.y][1])){
					if(((s[t.x-1][t.y]=='E')||(s[t.x-1][t.y]=='.'))&&(s[t.x-2][t.y]=='E'||s[t.x-2][t.y]=='.')){
						dis[t.x-2][t.y][1]=dis[t.x][t.y][0]+1;
						q.push(N(t.x-2,t.y,1));
					}
				} 
				if(t.y-2>0&&(!dis[t.x][t.y-2][2])){
					if(((s[t.x][t.y-1]=='E')||(s[t.x][t.y-1]=='.'))&&(s[t.x][t.y-2]=='E'||s[t.x][t.y-2]=='.')){
						dis[t.x][t.y-2][2]=dis[t.x][t.y][0]+1;
						q.push(N(t.x,t.y-2,2));
					}
				}
				 if(t.x+2<=r&&(!dis[t.x+1][t.y][1])){
					if(((s[t.x+1][t.y]=='E')||(s[t.x+1][t.y]=='.'))&&(s[t.x+2][t.y]=='E'||s[t.x+2][t.y]=='.')){
						dis[t.x+1][t.y][1]=dis[t.x][t.y][0]+1;
						q.push(N(t.x+1,t.y,1));
					}
				}
				 if(t.y+1<=c&&(!dis[t.x][t.y+1][2])){
					if(((s[t.x][t.y+1]=='E')||(s[t.x][t.y+1]=='.'))&&(s[t.x][t.y+2]=='E'||s[t.x][t.y+2]=='.')){
						dis[t.x][t.y+1][2]=dis[t.x][t.y][0]+1;
						q.push(N(t.x,t.y+1,2));
					}
				}
			}else if(t.w==1){
				if(!dis[t.x-1][t.y][0]){
					if(s[t.x-1][t.y]=='.'){
						dis[t.x-1][t.y][0]=dis[t.x][t.y][1]+1;
						q.push(N(t.x-1,t.y,0));
					}
				}
				if(!dis[t.x][t.y-1][1]){
					if((s[t.x][t.y-1]=='.'||s[t.x][t.y-1]=='E')&&(s[t.x+1][t.y-1]=='.'||s[t.x+1][t.y-1]=='E')){
						dis[t.x][t.y-1][1]=dis[t.x][t.y][1]+1;
						q.push(N(t.x,t.y-1,1));
					}
				}
				if(!dis[t.x][t.y+1][1]){
					if((s[t.x][t.y+1]=='.'||s[t.x][t.y+1]=='E')&&(s[t.x+1][t.y+1]=='.'||s[t.x+1][t.y+1]=='E')){
						dis[t.x][t.y+1][1]=dis[t.x][t.y][1]+1;
						q.push(N(t.x,t.y+1,1));
					}
				}
				if(t.x+2<=r&&(!dis[t.x+2][t.y][0])){
					if((s[t.x+2][t.y]=='.')){
						dis[t.x+2][t.y][0]=dis[t.x][t.y][1]+1;
						q.push(N(t.x+2,t.y,0));
					}
				}
			}else if(t.w==2){
				if(!dis[t.x][t.y-1][0]){
					if(s[t.x][t.y-1]=='.'){
						dis[t.x][t.y-1][0]=dis[t.x][t.y][2]+1;
						q.push(N(t.x,t.y-1,0));
					}
				}
				if(!dis[t.x-1][t.y][2]){
					if((s[t.x-1][t.y]=='.'||s[t.x-1][t.y]=='E')&&(s[t.x-1][t.y+1]=='.'||s[t.x-1][t.y+1]=='E')){
						dis[t.x-1][t.y][2]=dis[t.x][t.y][2]+1;
						q.push(N(t.x-1,t.y,2));
					}
				}
				if(!dis[t.x+1][t.y][2]){
					if((s[t.x+1][t.y]=='.'||s[t.x+1][t.y]=='E')&&(s[t.x+1][t.y+1]=='.'||s[t.x+1][t.y+1]=='E')){
						dis[t.x+1][t.y][2]=dis[t.x][t.y][2]+1;
						q.push(N(t.x+1,t.y,2));
					}
				}
				if(t.y+2<=c&&(!dis[t.x][t.y+2][0])){
					if((s[t.x][t.y+2]=='.')){
						dis[t.x][t.y+2][0]=dis[t.x][t.y][2]+1;
						q.push(N(t.x,t.y+2,0));
					}
				}
			}
		}
		if(dis[tarjet.x][tarjet.y][0]){
			printf("%d\n",dis[tarjet.x][tarjet.y][0]-1);
		}else{
			puts("Impossible");
		}
	}
	return 0;
}
