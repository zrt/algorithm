#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int vis[133333];
int start,aim;
char s[10];
queue<int> q;
int a[5][5];
int xk[4]={0,0,1,-1};
int yk[4]={1,-1,0,0};
int to(){
	int ret(0);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			ret|=a[i][j]<<(i*4+j);
		}
	}
	return ret;
}
int main(){
	for(int i=0;i<4;i++){
		scanf("%s",s);
		for(int j=0;j<4;j++){
			start|=((s[j]-'0'))<<(i*4+j);
		}
	}
	for(int i=0;i<4;i++){
		scanf("%s",s);
		for(int j=0;j<4;j++){
			aim|=((s[j]-'0'))<<(i*4+j);
		}
	}
	vis[start]=1;q.push(start);
	while(!q.empty()){
		if(vis[aim]) break;
		int X=q.front();q.pop();
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				a[i][j]=(X>>(i*4+j))&1;
			}
		}
		int t;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(a[i][j]==1){
					for(int k=0;k<4;k++){
						int x=xk[k]+i,y=yk[k]+j;
						if(x<0||x>=4||y<0||y>=4) continue;
						if(a[x][y]) continue;
						swap(a[x][y],a[i][j]);
						t=to();
						swap(a[x][y],a[i][j]);
						if(!vis[t]){
							vis[t]=vis[X]+1;
							q.push(t);
						}
					}
				}
			}
		}
	}
	printf("%d\n",vis[aim]-1);
	return 0;
}
