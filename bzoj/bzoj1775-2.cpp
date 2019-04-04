#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000+100

int dp[MAX],dp1[MAX];
int n,v;
int t1,t2,t3,t4;
int main()
{
	cin>>n>>v;
	for(int i=0;i<n;i++)
	{
		cin>>t1>>t2;
		for(int i=0;i<=v;i++)
			dp1[i]=dp[i];
		for(int j=0;j<t2;j++)
		{
			cin>>t3>>t4;
			for(int k=v;k>=t3;k--)
				dp1[k]=max(dp1[k],dp1[k-t3]+t4);
		}
		for(int j=v;j>=t1;j--)
			dp[j]=max(dp[j],dp1[j-t1]);
	}
	cout<<dp[v];
	return 0;
}
