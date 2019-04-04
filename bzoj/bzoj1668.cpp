#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,m;
int a[105][105];
int dp[105][105];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dp[1][1]=a[1][1];
	for(int i=2;i<=n+1;i++){
		dp[i][1]=-(1<<30);
	}
	dp[0][1]=-(1<<30);
	for(int i=2;i<=m;i++){
		dp[0][i]=-(1<<30);
		for(int j=1;j<=n;j++){
			dp[j][i]=max(max(dp[j][i-1],dp[j-1][i-1]),dp[j+1][i-1])+a[j][i];
		}
		dp[n+1][i]=-(1<<30);
	}
	printf("%d\n",dp[n][m]);
	return 0;
}
