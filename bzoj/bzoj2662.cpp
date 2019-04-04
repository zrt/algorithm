#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=2505;
int head[maxn],ver[maxn],nxt[maxn],edge[maxn],tot;
int dis[55][55],vis[55][55];
struct node
{
	int x,y,z;
};
bool operator <(node a,node b)
{
	return a.z>b.z;
}
priority_queue<node>q;
int n,m,k;
void add(int x,int y,int z)
{
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
	edge[tot]=z;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1][0]=0;
	node x;
	x.x=1;
	x.y=0;
	x.z=0;
	q.push(x);
	while(!q.empty())
	{
		node tmp=q.top();
		q.pop();
	    if(vis[tmp.x][tmp.y])
		continue;
		vis[tmp.x][tmp.y]=1;
		for(int i=head[tmp.x];i;i=nxt[i])
		{
			if(edge[i]+dis[tmp.x][tmp.y]<dis[ver[i]][tmp.y])
			{
				dis[ver[i]][tmp.y]=edge[i]+dis[tmp.x][tmp.y];
				node temp;
				temp.x=ver[i];
				temp.y=tmp.y;
				temp.z=dis[ver[i]][tmp.y];
				q.push(temp);
			}
			if(tmp.y<k&&(edge[i]/2)+dis[tmp.x][tmp.y]<dis[ver[i]][tmp.y+1])
			{
				dis[ver[i]][tmp.y+1]=(edge[i]/2)+dis[tmp.x][tmp.y];
				node temp;
				temp.x=ver[i];
				temp.y=tmp.y+1;
				temp.z=dis[ver[i]][tmp.y+1];
				q.push(temp); 
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=0;i<=k;i++)
	ans=min(ans,dis[n][i]);
	cout<<ans<<endl;
	return 0;
}
