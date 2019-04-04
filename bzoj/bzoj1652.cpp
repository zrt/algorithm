#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n;
int val[2005];
int sum[2005];
long long dp[2005][2005];
long long ans;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
		dp[i][i]=val[i];
		sum[i]=sum[i-1]+val[i];
	}
	
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			int j=i+l;
			if(j>n) break;
			dp[i][j]=max(dp[i+1][j]+sum[j]-sum[i]+val[i],dp[i][j-1]+sum[j-1]-sum[i-1]+val[j]);
		}
	}
	printf("%lld\n",dp[1][n]);
	return 0;
}
