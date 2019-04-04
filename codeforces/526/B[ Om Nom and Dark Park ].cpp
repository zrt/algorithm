#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=10000;
int a[maxn],ans,n,m;
int dfs(int x)
{
	if(x>=(1<<n))
	return a[x];
	int b=dfs(x*2),c=dfs(x*2+1);
	ans+=abs(b-c);return a[x]+max(b,c);
}
int main()
{
	cin>>n;m=(1<<(n+1))-1;
	for(int i=2;i<=m;i++)scanf("%d",&a[i]);
	dfs(1);
	cout<<ans<<endl;
}