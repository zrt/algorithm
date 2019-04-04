/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int stmx[50005][16],stmn[50005][16];
int log,n,x,y,q;
int ask(int l,int r){
	int d=r-l+1;
	int lg;
	for(lg=0;1<<lg<=d;lg++);lg--;
	int maxx=max(stmx[l][lg],stmx[r-(1<<lg)+1][lg]);
	int minn=min(stmn[l][lg],stmn[r-(1<<lg)+1][lg]);
	return maxx-minn;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&stmx[i][0]);
		stmn[i][0]=stmx[i][0];
	}
	for(log=0;1<<log<=n;log++);log--;
	for(int i=1;i<=log;i++){
		for(int j=1;j<=n;j++){
			if(j+(1<<i)-1<=n){
				stmx[j][i]=max(stmx[j][i-1],stmx[j+(1<<(i-1))][i-1]);
				stmn[j][i]=min(stmn[j][i-1],stmn[j+(1<<(i-1))][i-1]);
			}
		}
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",ask(x,y));
	}
	return 0;
}
