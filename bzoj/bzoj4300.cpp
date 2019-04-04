#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int f[100];
int n,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		int tmp=0;
		for(int j=0;j<=30;j++)
		if(x&(1<<j))
		tmp=max(tmp,f[j]+1);
		for(int j=0;j<=30;j++)
		if(x&(1<<j))
		f[j]=tmp;
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
} 
