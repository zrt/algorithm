#include<iostream>
#include<cstdio>
#include<queue>
//#include<stack>
using namespace std;
int f[110][110]={0};
struct pot{
	int x,y;
};
queue<pot> q;
int xk[8]={-1,1,0,0,-1,-1,1,1},yk[8]={0,0,1,-1,-1,1,1,-1};
//bitset<110> vis[110];
/*
void bfs(int x,int y,int count){
	for(int i=0;i<4;i++){
		if(f[x+xk[i]][y+yk[i]]!=-1){
			if(f[x+xk[i]][y+yk[i]]==0||f[x+xk[i]][y+yk[i]]>count+1){
				f[x+xk[i]][y+yk[i]]=count+1;
				bfs(x+xk[i],y+yk[i],count+1);
			}
		}
	}
}*/
int main(){
	int x,y,m,n;
	char c;
	cin>>x>>y>>m>>n;
	for(int i=0;i<=x+2||i<=y+2;i++){
		f[i][x+1]=f[y+1][i]=f[0][i]=f[i][0]=-1;
	}
	f[y-n+1][m]=1;
	for(int i=1;i<=y;i++){
		for(int j=1;j<=x;j++){
			scanf(" %c",&c);
			if(c=='*') f[i][j]=-1;
		}
	}
//	for(int i=0;i<=y+1;i++){
//		for(int j=0;j<=x+1;j++){
//		cout<<f[i][j]<<' ';
//	}
//	puts("");
//	}
	pot temp;
	temp.x=y-n+1;temp.y=m;
	q.push(temp);
//	int count=0;
	//bfs
	while(!q.empty()){
		pot now=q.front();q.pop();
		for(int i=0;i<8;i++){
			if(f[now.x+xk[i]][now.y+yk[i]]==0){
				//if(f[x+xk[i]][y+yk[i]]==0||f[x+xk[i]][y+yk[i]]>count+1){
					f[now.x+xk[i]][now.y+yk[i]]=f[now.x][now.y]+1;
					temp.x=now.x+xk[i];temp.y=now.y+yk[i];
					q.push(temp);
				//}
			}
		}
	}
	//bfs(n,m,0);
	int maxx=0;
//	for(int i=1;i<=y;i++){
//		for(int j=1;j<=x;j++){
//		cout<<f[i][j]<<' ';
//	}
//	puts("");
//	}
	
	for(int i=1;i<=y;i++)
	for(int j=1;j<=x;j++){
		maxx=max(maxx,f[i][j]);
	}
	cout<<maxx-1;
}
