#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL mod = 998244353;

LL n,m,k;
LL dp[2005][2005]; // qian i ,   k diff
LL dps[2005][2005];
// dp[i][j] = dp[k][j-1]*(m-1)  // k<i
int main(){
	cin>>n>>m>>k;
	k++;
	dp[0][0]=1;
	for(int j=1;j<=k;j++){
		LL sum = 0;
		for(int i=1;i<=n;i++){
			dp[i][j] = dp[0][j-1]*(m)%mod;
			dp[i][j] = (dp[i][j]+sum*(m-1)%mod)%mod;
			sum = (sum+dp[i][j-1])%mod;
			
		}
	}
	cout<<dp[n][k]<<endl;



	return 0;
}