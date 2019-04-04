#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n,sum=0,minn=1e9;
	cin>>n;
	if(n==1)
	{
		cin>>n;
		if(n&1)
		cout<<"NIESTETY";
		else
		cout<<n<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x&1)if(x<minn)minn=x;
		sum+=x;
	}
	if(sum&1)cout<<sum-minn;else cout<<sum;
	return 0;
}
