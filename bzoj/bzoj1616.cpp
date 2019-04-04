/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
//by zrt
//problem:
using namespace std;
int n,m,t;
char s[105][105];
int r1,c1,r2,c2;
long long tot;
int xk[]={0,0,1,-1};
int yk[]={1,-1,0,0};
inline int abs(int x){
	return x>=0?x:-x;
}
void dfs(int x,int y,int t){
	if(t==0){
		if(x==r2&&y==c2){
			tot++;
		}
		return ;
	}else{
		if(abs(x-r2)+abs(y-c2)>t) return;
		for(int k=0;k<4;k++){
			int X=x+xk[k],Y=y+yk[k];
			if(X>=0&&Y>=0&&X<n&&Y<m&&s[X][Y]=='.'){
				dfs(X,Y,t-1);
			}
		} 
	}
	
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&m,&t);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	r1--;c1--;r2--;c2--;
	dfs(r1,c1,t);
	printf("%lld\n",tot);
	return 0;
}
