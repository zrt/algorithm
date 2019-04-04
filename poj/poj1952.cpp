#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[5005],dp[5005],t[5005];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{dp[i]=1;t[i]=1;}
	t[0]=1;
	a[0]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]<a[j])
			{
				if(dp[i]<dp[j]+1)
				{
					dp[i]=dp[j]+1;
					t[i]=t[j];
				}
				else if(dp[i]==dp[j]+1)//else!
				t[i]+=t[j];
			}
			if(a[i]==a[j])
			t[i]=0;
		}	
	}
	t[0]=1;
	for(int i=1;i<=n;i++) t[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--)
		{
			if(a[i]==a[j]&&dp[i]==dp[j]){
				break;
			}
			if(dp[i]==dp[j]+1&&a[i]<a[j])
			t[i]+=t[j];
		}
	
	//		cout<<t[i]<<endl;
	}
	int anslen=0,ans=0;
	for(int i=1;i<=n;i++)
	anslen=max(anslen,dp[i]);
	for(int i=1;i<=n;i++)
	if(dp[i]==anslen)
	ans+=t[i];
	cout<<anslen<<" "<<ans;
	return 0;
}