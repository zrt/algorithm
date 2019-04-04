#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 200200
using namespace std;
int n,m;
int a[M],b[M],c[M],d[M],ans[M];
bool Compare(int x,int y)
{
    if(a[x]!=a[y])
        return a[x]<a[y];
    if(b[x]!=b[y])
        return b[x]<b[y];
    return x<y;
}
int main()
{
    int i;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        b[i]=a[i];
    sort(b+1,b+n+1);
    for(i=1;i<=n;i++)
        c[i]=i;
    sort(c+1,c+n+1,Compare);
    for(i=1;i<=n;i++)
        d[c[i]]=i;
    int pos=1;
    for(i=n;i;i--)
    {
        ans[i]=a[pos];
        pos=d[pos];
    }
    for(i=1;i<n;i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    return 0;
}
