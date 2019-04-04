#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> v[5];
/*
某人有一套玩具,并想法给玩具命名。
首先他选择 WING 四个字母中的任意一个字母作为玩具的基本名字。
然后他会根据 自己的喜好,
将名字中任意一个字母用“WING”中的某两个字母代替,
使得自己的名字能够扩充得很长。
现在,他想请你猜猜某一个很长的名字,最初可能是由哪个字母变形过来的。
Len ≤ 200, 每个字母可替换的两个字母组数 ≤ 16
*/
int book;
char in1[300];
int in[300];
int dp[300][300][5];
int t[5];
int main()
{
	for(int i=1;i<=4;i++)cin>>t[i];
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=t[i];j++)
		{
			char t3[10];
			cin>>t3;
			char t1=t3[0],t2=t3[1];
			v[i].push_back((t1=='W'?1:t1=='I'?2:t1=='N'?3:4)*10+(t2=='W'?1:t2=='I'?2:t2=='N'?3:4));
		}
	}
	cin>>in1;
	int len=strlen(in1);
	for(int i=0;i<len;i++)
		in[i]=in1[i]=='W'?1:in1[i]=='I'?2:in1[i]=='N'?3:4;
	for(int i=0;i<len;i++)
		for(int j=1;j<=4;j++)
			if(in[i]==j)
				dp[i][i][j]=1;
	for(int length=2;length<=len;length++)
	{
		for(int l=0;l<len;l++)
		{
			int r=l+length-1;
			if(r>=len)break;
			for(int i=1;i<=4;i++)
			{
				for(int j=0;j<v[i].size();j++)
				{
					for(int k=l;k<r;k++)
					{
						int t1=v[i][j]/10,t2=v[i][j]%10;
						if(dp[l][k][t1] && dp[k+1][r][t2])
						{
							dp[l][r][i]=1;
							goto label;
						}
					}
				}
				label:;
			}
		}
	}
	for(int i=1;i<=4;i++)
		if(dp[0][len-1][i])
		{
			book=1;
			cout<<(i==1?'W':i==2?'I':i==3?'N':'G');
		}
	if(!book)cout<<"The name is wrong!";
	return 0;
}
