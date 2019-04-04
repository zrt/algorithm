/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
int dp[10005];
int w[10005];
int tot[10005];
int p[10005][105];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		scanf("%d",&tot[i]);
		for(int j=0;j<tot[i];j++){
			scanf("%d",&p[i][j]);
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		int minn=0;
		for(int j=0;j<tot[i];j++){
			if(dp[p[i][j]]>minn) minn=dp[p[i][j]];
		}
		dp[i]=minn+w[i];
		if(dp[i]>maxx) maxx=dp[i];
	}
	printf("%d\n",maxx);
	return 0;
}
