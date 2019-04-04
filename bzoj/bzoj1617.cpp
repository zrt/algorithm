/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,m,w[2505],sum[2505];
int f[2505];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+w[i];
		f[i]=sum[i]+m;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			f[i]=min(f[i],sum[i-j+1]+f[j-1]+m+m);
		}
	}
	printf("%d\n",f[n]);
	return 0;
}
