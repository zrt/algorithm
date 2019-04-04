#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;
char map[101][101];
int count=0;
	int m,n;
int vis[101][101]={0};
int xk[8]={-1,-1,-1,0,0,1,1,1},yk[8]={-1,0,1,-1,1,-1,0,1};
void dfs(int i,int j){
	vis[i][j]=1;
	for(int k=0;k<8;k++){
		int x=i+xk[k],y=j+yk[k];
		if(x<0||y<0||x>=m||y>=n||vis[x][y]||(map[x][y]=='.')){
			continue;
		}
		dfs(x,y);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif

	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++){
		scanf("%s",map[i]);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]=='.') continue;
			if(vis[i][j]) continue;
			count++;
			dfs(i,j);
		}
	}
	printf("%d",count);
	return 0;
}
