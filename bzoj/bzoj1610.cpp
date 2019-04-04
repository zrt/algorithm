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
int x[300],y[300];
int lx[40005],ly[40005];
int tot;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			lx[tot]=x[j]-x[i];
			ly[tot]=y[j]-y[i];
			tot++;
		}
	}
	for(int i=0;i<tot;i++){
		bool b=1;
		for(int j=i+1;j<tot;j++){
			if(lx[i]*ly[j]==ly[i]*lx[j]){
				b=0;break;
			}
		}
		if(b) ans++;
	}
	printf("%d",ans);
	return 0;
}
