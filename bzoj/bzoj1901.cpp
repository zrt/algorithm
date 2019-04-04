#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int san,n,m,tot;
int num[30010];
int  cc[30010];
int  in[10010][4];
int   T[(int)1e7];
int  lc[(int)1e7];
int  rc[(int)1e7];
vector<int> ss;
vector<int> ss2;

void add(int l,int r,int v,int k)
{
    for(int i=0;i<ss.size();i++)
        T[ss[i]]+=k;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(v<=mid)
    {
        for(int i=0;i<ss.size();i++)
        {
            if(lc[ss[i]]==0)
                lc[ss[i]]=++tot;
            ss[i]=lc[ss[i]];
        }
        add(l,mid,v,k);
    }
    else
    {
        for(int i=0;i<ss.size();i++)
        {
            if(rc[ss[i]]==0)
                rc[ss[i]]=++tot;
            ss[i]=rc[ss[i]];
        }
        add(mid+1,r,v,k);
    }
}

void add(int pos,int v,int k)
{
    ss.clear();
    for(int i=pos;i<=n;i+=i&-i)
    {
        ss.push_back(i);
    }
    add(1,san,v,k);
}

int find(int l,int r,int k)
{
    if(l==r)return cc[l];
    int mid=(l+r)>>1,lnum=0;
    for(int i=0;i<ss.size();i++)
        lnum+=T[lc[ss[i]]];
    for(int i=0;i<ss2.size();i++)
        lnum-=T[lc[ss2[i]]];
    if(k<=lnum)
    {
        for(int i=0;i<ss.size();i++)
            ss[i]=lc[ss[i]];
        for(int i=0;i<ss2.size();i++)
            ss2[i]=lc[ss2[i]];
        return find(l,mid,k);
    }
    else
    {
        for(int i=0;i<ss.size();i++)
            ss[i]=rc[ss[i]];
        for(int i=0;i<ss2.size();i++)
            ss2[i]=rc[ss2[i]];
        return find(mid+1,r,k-lnum);
    }
}

void ask(int l,int r,int k)
{
    ss.clear();
    ss2.clear();
    for(int i=r;i>0;i-=i&-i)
        ss.push_back(i);
    for(int i=l-1;i>0;i-=i&-i)
        ss2.push_back(i);
    printf("%d\n",find(1,san,k));
}

void change(int i,int j,int o=-1)
{
    if(o!=0)
    {
        add(i,num[i],-1);
    }
    num[i]=j;
    add(i,num[i],1);
}

void build()
{
    for(int i=1;i<=n;i++)
        change(i,num[i],0);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]),cc[i]=num[i];
    san=n;
    tot=n;
    for(int i=1;i<=m;i++)
    {
        char t[1000];
        scanf("%s%d%d",t,&in[i][1],&in[i][2]);
        if((in[i][0]=t[0]=='Q'))
            scanf("%d",&in[i][3]);
        else
            cc[++san]=in[i][2];
    }
    sort(cc+1,cc+san+1);
    san=unique(cc+1,cc+san+1)-cc-1;
    for(int i=1;i<=n;i++)
        num[i]=lower_bound(cc+1,cc+san+1,num[i])-cc;
    for(int i=1;i<=m;i++)
        if(in[i][0]==0)
            in[i][2]=lower_bound(cc+1,cc+san+1,in[i][2])-cc;
    build();
    for(int i=1;i<=m;i++)
    {
        if(in[i][0]==1)
            ask(in[i][1],in[i][2],in[i][3]);
        else
            change(in[i][1],in[i][2]);
    }
}
