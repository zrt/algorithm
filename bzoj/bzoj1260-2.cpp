#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char in[100],len;
int dp[100][100];
int main()
{
	cin>>in;
	len=strlen(in);
	for(int i=0;i<len;i++)dp[i][i]=1;
	for(int length=2;length<=len;length++)
	{
		for(int l=0;l<len;l++)
		{
			int r=l+length-1;
			if(r>=len)break;
			dp[l][r]=0x3fffffff;
			if(in[l]==in[r])
			{
				dp[l][r]=min(dp[l+1][r],min(dp[l][r-1],length>2?dp[l+1][r-1]+1:dp[l][r-1]));
			}else{
				for(int k=l;k<r;k++)
				{
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
			}
		}
	}
	cout<<dp[0][len-1];
	return 0;
}
