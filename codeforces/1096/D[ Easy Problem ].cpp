#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL p = 998244353 ;

int n;
char s[100005];
LL a[100005];
LL dp[100005][4];
char hard[]="hard";

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++){
		// del dangqian
		for(int j=0;j<4;j++){
			dp[i][j] = dp[i-1][j]+a[i];
		}
		// xuan dangqian
		for(int j=0;j<4;j++){
			if(s[i] == hard[j]){
				if(j!=3){
					dp[i][j+1] = min(dp[i][j+1],dp[i-1][j]);
				}
			}else{
				dp[i][j] = min(dp[i][j],dp[i-1][j]);
			}
		}
	}

	LL mn = dp[n][0];
	for(int i=0;i<4;i++) mn=min(mn,dp[n][i]);
	printf("%I64d\n",mn);
	


	return 0;
}