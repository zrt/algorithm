#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
int n,maxr,ans;
char s[1010][100];
int l[1010];
int trie[80010][26],ok[80010],cnt;
int head[1010],to[1000010],next[1000010],graphmr;
int q[1010],h,t;
bool vis[1010];
inline void add(int x,int y)
{
	int p=graphmr++;
	to[p]=y;next[p]=head[x];head[x]=p;
}
inline void insert(char *a,int x)
{
	int idx=0;
	for(int i=0;a[i];i++)
	{
		if(!trie[idx][a[i]-'a']) trie[idx][a[i]-'a']=++cnt;
		idx=trie[idx][a[i]-'a'];
	}
	ok[idx]=x;
}
inline int find(string a)
{
	int idx=0;
	for(int i=0;a[i];i++)
	{
		if(!trie[idx][a[i]-'a']) return -1;
		idx=trie[idx][a[i]-'a'];
	}
	return ok[idx];
}
inline void bfs()
{
	q[1]=0;h=1;t=1;
	vis[0]=1;
	while(h<=t)
	{
		int sta=q[h++];
		for(int i=head[sta];~i;i=next[i])
			if(!vis[to[i]])
			{
				vis[to[i]]=1;
				q[++t]=to[i];
			}
	}
}
int main()
{
	memset(ok,-1,sizeof ok);
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		scanf("%s",s[i]);
		l[i]=strlen(s[i]);
		if(i==0)insert(s[0],0);
		else if(l[i]>l[0])
			insert(s[i],i);
	}
	memset(head,-1,sizeof head);
	for(int i=1;i<=n;i++)
	{
		string now=s[i];
		for(int j=0;j<l[i];j++)
		{
			now.erase(now.begin()+j);
			int x=find(now);
			if(x!=-1) add(x,i);
			now=s[i];
		}
	}
	bfs();
	for(int i=0;i<=n;i++)
		if(vis[i]&&maxr<l[i])
		{
			maxr=l[i];
			ans=i;
		}
	printf("%s\n",s[ans]);
	return 0;
}

/*

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
int n,maxr,ans;
char s[1010][100];
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
int n,maxr,ans;
char s[1010][100];
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
int n,maxr,ans;
char s[1010][100];
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
int n,maxr,ans;
char s[1010][100];

*/