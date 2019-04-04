#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int dp[2][4000][2];
//0 wake 1 sleep
int n,b,c;
int a[4000];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&b);
	int ans;
	if(b==1) {
		puts("0");
		goto ed;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	c=0;
	for(int i=2;i<=n;i++){
		dp[c^1][0][1]=-(1<<30);
		for(int j=0;j<=i&&j<=b;j++){
			dp[c][j][0]=max(dp[c^1][j][0],dp[c^1][j][1]);
			dp[c][j][1]=max(dp[c^1][j-1][0],dp[c^1][j-1][1]+a[i]);
		}
		c^=1;
	}
	c^=1;
	ans=max(dp[c][b][0],dp[c][b][1]);
	memset(dp,0,sizeof dp);
	
	for(int j=1;j<=b;j++) dp[1][j][1]=a[1];
	c=0;
	for(int i=2;i<=n;i++){
		dp[c^1][0][1]=-(1<<30);
		for(int j=0;j<=i&&j<=b;j++){
			dp[c][j][0]=max(dp[c^1][j][0],dp[c^1][j][1]);
			dp[c][j][1]=max(dp[c^1][j-1][0],dp[c^1][j-1][1]+a[i]);
		}
		c^=1;
	}
	c^=1;
	ans=max(ans,max(dp[c][b][1],dp[c][b-1][0]));
	printf("%d\n",ans);
	ed:return 0;
}
