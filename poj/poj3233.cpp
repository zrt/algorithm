#include<cstdio>
#include<iostream>
using namespace std;
int k,n,base;
struct matrix
{
    int n;
    int m[33][33];
    void clear()
    {
         for (int i=1;i<=n;i++)
             for (int j=1;j<=n;j++)
                 m[i][j]=0;     
    }
    void in(int t)
    {
         n=t;
         for (int i=1;i<=n;i++)
             for (int j=1;j<=n;j++)
                 scanf("%d",&m[i][j]);     
    }
    void out()
    {
         for (int i=1;i<=n;i++)
         {
             for (int j=1;j<n;j++)
                 printf("%d ",m[i][j]);
             printf("%d\n",m[i][n]);    
         }     
    }
    void operator +=(const matrix &b)
    {
         for (int i=1;i<=n;i++)
             for (int j=1;j<=n;j++)
                 m[i][j]=(m[i][j]+b.m[i][j])%base;     
    }
}a,b,f;
matrix operator *(const matrix &a,const matrix &b)
{
    matrix c;
    c.n=n;
    c.clear();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            for (int k=1;k<=n;k++)
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%base;
    return c;
}
int main()
{
    scanf("%d%d%d",&n,&k,&base);
    a.in(n);
    b=a;
    f=a;
    int i;
    for (i=0;(1<<i)<=k;i++);
    for (i-=2;i>=0;i--)
    {
        f+=b*f;
        b=b*b;
        if (((1<<i)&k)>0) b=b*a,f+=b;       
    }
    f.out();
    return 0;   
}