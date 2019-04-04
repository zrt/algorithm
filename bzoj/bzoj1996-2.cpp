#include <iostream>
#include <algorithm>
using namespace std;

int n,h[1010];
long long dp[1010][1010][2];//0:left,1:right
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1;i<=n;i++)
		dp[i][i][0]=1;
	for(int len=1;len<n;len++)
	{
		for(int l=1;l<=n;l++)
		{
			int r=l+len-1;
			if(r>n)break;
			dp[l][r][0]%=19650827;
			dp[l][r][1]%=19650827;
			if(h[l-1]<h[l]&&l-1>0)
			{
				dp[l-1][r][0]+=dp[l][r][0];
			}
			if(h[r+1]>h[l]&&r+1<=n)
			{
				dp[l][r+1][1]+=dp[l][r][0];
			}

			if(h[l-1]<h[r]&&l-1>0)
			{
				dp[l-1][r][0]+=dp[l][r][1];
			}
			if(h[r+1]>h[r]&&r+1<=n)
			{
				dp[l][r+1][1]+=dp[l][r][1];
			}
		}
	}
	cout<<(dp[1][n][0]+dp[1][n][1])%19650827;
	return 0;
}
