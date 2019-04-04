#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,e,d,q,cost[1010],weight[1010],times[1010];
int fr_dp[1010][1010],ba_dp[1010][1010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>weight[i]>>cost[i]>>times[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=1000;j++)fr_dp[i][j]=fr_dp[i-1][j];
		int t=times[i];
		for(int j=1;j<=t;j<<=1)
		{
			t-=j;
			int V=weight[i]*j;
			int C=cost[i]*j;
			for(int k=1000;k>=V;k--)
				fr_dp[i][k]=max(fr_dp[i][k],fr_dp[i][k-V]+C);
		}
		for(int j=t;j<=t;j++)
		{
			t-=j;
			int V=weight[i]*j;
			int C=cost[i]*j;
			for(int k=1000;k>=V;k--)
				fr_dp[i][k]=max(fr_dp[i][k],fr_dp[i][k-V]+C);
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<=1000;j++)ba_dp[i][j]=ba_dp[i+1][j];
		int t=times[i];
		for(int j=1;j<=t;j<<=1)
		{
			t-=j;
			int V=weight[i]*j;
			int C=cost[i]*j;
			for(int k=1000;k>=V;k--)
				ba_dp[i][k]=max(ba_dp[i][k],ba_dp[i][k-V]+C);
		}
		for(int j=t;j<=t;j++)
		{
			t-=j;
			int V=weight[i]*j;
			int C=cost[i]*j;
			for(int k=1000;k>=V;k--)
				ba_dp[i][k]=max(ba_dp[i][k],ba_dp[i][k-V]+C);
		}
	}
	
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&d,&e);
		d++;
		int ans=0;
		for(int i=0;i<=e;i++)
			ans=max(ans,fr_dp[d-1][i]+ba_dp[d+1][e-i]);
		printf("%d\n",ans);
	}
	return 0;
}
