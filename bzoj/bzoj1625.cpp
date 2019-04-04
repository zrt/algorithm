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
int n,m,w,d;
int f[300000];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&w,&d);
		for(int j=m;j>=w;j--){
			f[j]=max(f[j],f[j-w]+d);
		}
	}
	printf("%d",f[m]);
	return 0;
}
