/*
ID: zrtdrea1
PROG:
LANG: C++
*/
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int stmin[50005][17];
int stmax[50005][17];
int log;
int ask(int l,int r){
	int lg;
	int d=r-l+1;
	for(lg=0;1<<lg<=d;lg++);lg--;
	int maxx=max(stmax[l][lg],stmax[r-(1<<lg)+1][lg]);
	int minn=min(stmin[l][lg],stmin[r-(1<<lg)+1][lg]);
	return maxx-minn;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&stmin[i][0]);
		stmax[i][0]=stmin[i][0];
	}
	for(log=0;1<<log<=n;log++);log--;
	for(int i=1;i<=log;i++){
		for(int j=1;j<=n;j++){
			if(j+(1<<i)-1<=n){
				stmin[j][i]=min(stmin[j][i-1],stmin[j+(1<<(i-1))][i-1]);
				stmax[j][i]=max(stmax[j][i-1],stmax[j+(1<<(i-1))][i-1]);
			}
		}
	}
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",ask(x,y));
	}
	return 0;
}
