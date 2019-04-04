#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int n;
char s[2000];
int main()
{
	cin>>n;scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	for(int d=1;i+4*d<=n;d++)
	{
		int flag=1;
		for(int k=0;k<5;k++)
		{
			if(s[i+d*k]!='*')
			flag=0;
		}
		if(flag==1)
		{
			;puts("yes");
			goto ed;
		}
	} 
	cout<<"no\n";
	ed:;
	return 0;
}