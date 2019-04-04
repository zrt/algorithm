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
int n;
int a[1005],b[1005];
int inf=0x3f3f3f3f;
int dp[1005][12005];
int w=6000;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	int minn,maxx;
	minn=maxx=w;
	memset(dp,0x3f,sizeof dp);
	dp[0][w]=0;
	for(int i=1;i<=n;i++){
		for(int k=minn;k<=maxx;k++){
			if(dp[i-1][k]!=inf){
				dp[i][k+a[i]-b[i]]=min(dp[i][k+a[i]-b[i]],dp[i-1][k]);
				dp[i][k-a[i]+b[i]]=min(dp[i][k-a[i]+b[i]],dp[i-1][k]+1);
				minn=min(min(k+a[i]-b[i],k-a[i]+b[i]),minn);
				maxx=max(max(k+a[i]-b[i],k-a[i]+b[i]),maxx);
			}
		}
	}
	for(int i=0;;i++){
		if(dp[n][w+i]!=inf||dp[n][w-i]!=inf){
			printf("%d\n",min(dp[n][w+i],dp[n][w-i]));break;
		}
	}
	return 0;
}
