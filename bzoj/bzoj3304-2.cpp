#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
char a[600],b[600],c[600];
int dp[2][502][502];
int main()
{
	memset(dp,0x80,sizeof dp);
	scanf("%s%s%s",a+1,b+1,c+1);
	int l1=strlen(a+1),l2=strlen(b+1),l3=strlen(c+1);
	dp[0][0][0]=0;
	for(int i=0;i<=l2;i++)dp[0][i][0]=0;
	for(int i=1;i<=l1;i++)
	{
		memset(dp[i&1],0x80,sizeof dp[i&1]);
		dp[i&1][0][0]=0;
		for(int j=1;j<=l2;j++)
		{
			for(int k=0;k<=l3;k++)
			{
				if(a[i]==b[j])
				{
					dp[i&1][j][k]=dp[~i&1][j-1][k]+1;
					if(k>0&&a[i]==c[k])
						dp[i&1][j][k]=dp[~i&1][j-1][k-1]+1;
				}else{
					dp[i&1][j][k]=max(dp[~i&1][j][k],dp[i&1][j-1][k]);
				}
			}
		}
	}
	if(dp[l1&1][l2][l3]>=l3)
		printf("%d",dp[l1&1][l2][l3]);
	else 
		printf("NO SOLUTION");
	return 0;
}
