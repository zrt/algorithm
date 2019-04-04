#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
int t,c,ts,te,from,to,cost,dis[2510],inque[2510];
vector<pair<int,int> > v[2510];
int SPFA(int start,int end)
{
	memset(dis,0x3f,sizeof(dis));
	dis[start]=0;
	queue<int> q;
	q.push(start);
	while(q.size())
	{
		int x=q.front();q.pop();
		inque[x]=0;
		for(int i=0;i<v[x].size();i++)
		{
			int y=v[x][i].first;
			int z=v[x][i].second;
			if(dis[y]>dis[x]+z)
			{
				dis[y]=dis[x]+z;
				if(!inque[y])
				{
					inque[y]=1;
					q.push(y);
				}
			}
		}
	}
	return dis[end];
}
int main()
{
	scanf("%d%d%d%d",&t,&c,&ts,&te);
	for(int i=1;i<=c;i++)
	{
		scanf("%d%d%d",&from,&to,&cost);
		v[from].push_back(make_pair(to,cost));
		v[to].push_back(make_pair(from,cost));
	}
	printf("%d",SPFA(ts,te));
	return 0;
}
