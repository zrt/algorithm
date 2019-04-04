#include<iostream>
#include<cstdio>
//by zrt
//problem:poj1154
using namespace std;
int m,n;
bool a[26]={0};
char map[20][21];
int maxx=0;
int count=0;
int xk[4]={0,0,-1,1},yk[4]={-1,1,0,0};
void dfs(int i,int j){
	int ok=1;
	for(int k=0;k<4;k++){
		int x=xk[k]+i,y=yk[k]+j;
		if(x<0||y<0||x>=m||y>=n||a[map[x][y]-'A']){
			continue;
		}
		ok=0;
		count++;
		a[map[x][y]-'A']=1;
		dfs(x,y);
		a[map[x][y]-'A']=0;
		count--;
	}
	if(ok){
		if(maxx<count) maxx=count;
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)scanf("%s",map[i]);
	a[map[0][0]-'A']=1;
	dfs(0,0);
	printf("%d",maxx+1);
	return 0;
}
