#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1005][1005][2];
int h[1005];
int n;
const int mod=19650827;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	for(int i=1;i<=n;i++) dp[i][i][0]=1;
	for(int l=1;l<n;l++){
		for(int i=1;i<=n;i++){
            int j=i+l;
			if(j>n) break;
			if(h[i]<h[i+1])dp[i][j][0]+=dp[i+1][j][0];
			if(h[i]<h[j])  dp[i][j][0]+=dp[i+1][j][1];
			if(h[j]>h[i]) dp[i][j][1]+=dp[i][j-1][0];
			if(h[j]>h[j-1]) dp[i][j][1]+=dp[i][j-1][1];
			dp[i][j][0]%=mod;
			dp[i][j][1]%=mod;
		}
	}
	printf("%d\n",(dp[1][n][0]+dp[1][n][1])%mod);
//	while(1);
	return 0;
}
