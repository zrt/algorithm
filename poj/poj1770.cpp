#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <map>

#define N 10000
#define M 100000

using namespace std;

map<int,int> mp;

int head[N],to[M],next[M],a[N],b[N],cnt,num,n,m,tc[N],dp[N][2];
bool vis[N];

inline void add(int u,int v)
{
    to[cnt]=v; next[cnt]=head[u]; head[u]=cnt++;
}

void read()
{
    mp.clear();
    memset(head,-1,sizeof head);cnt=0;
    num=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=1;k<=m;k++)
                if(abs(a[i]-a[j])==b[k])
                {
                    if(mp[a[i]]==0) {mp[a[i]]=++num;tc[num]=a[i];}
                    if(mp[a[j]]==0) {mp[a[j]]=++num;tc[num]=a[j];}
                    int ta=mp[a[i]],tb=mp[a[j]]; 
                    add(ta,tb),add(tb,ta);
                }
}

void find(int u,int fa)
{
    vis[u]=true;
    for(int i=head[u];~i;i=next[i])
        if(to[i]!=fa) find(to[i],u);
        
    dp[u][1]=tc[u];dp[u][0]=0;
    for(int i=head[u];~i;i=next[i])
        if(fa!=to[i])
        {
            dp[u][0]+=max(dp[to[i]][1],dp[to[i]][0]);
            dp[u][1]+=dp[to[i]][0];
        }
}

void go()
{
    memset(dp,0x8f,sizeof dp);
    memset(vis,0,sizeof vis);
    int ans=0;
    for(int i=1;i<=num;i++)
        if(!vis[i])
        {
            find(i,-1);
            ans+=max(dp[i][0],dp[i][1]);
        }
    printf("%d\n",ans);
}

int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        read();
        go();
    }
    return 0;
}