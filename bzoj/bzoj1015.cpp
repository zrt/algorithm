#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#define MAXN 1000010 
using namespace std; 
int father[MAXN],l[MAXN],r[MAXN],n,m,p,planet[MAXN],ans[MAXN],sum; 
int start[MAXN],num[MAXN],next[MAXN],tot; 
bool mark[MAXN]; 
void make(int a,int b){  tot++,num[tot]=b,next[tot]=start[a],start[a]=tot;  } 

int Find(int p) 
{ 
    if(father[p]==0)  return p; 
    father[p]=Find(father[p]); 
    return father[p]; 
} 

int main() 
{ 
    scanf("%d %d",&n,&m); 
    for(int i=1,a,b;i<=m;i++) 
    { 
        scanf("%d %d",&a,&b); 
        make(a+1,b+1),make(b+1,a+1); 
    } 
    scanf("%d",&p); 
    for(int i=1;i<=p;i++) 
    { 
        scanf("%d",&planet[i]); 
        mark[++planet[i]]=true; 
    } 
    for(int i=1;i<=n;i++) 
        if(mark[i]==false) 
            for(int j=start[i];j;j=next[j]) 
                if(mark[num[j]]==false) 
                { 
                    int px=Find(i),py=Find(num[j]); 
                    if(px!=py)  father[py]=px; 
                } 
    for(int i=1;i<=n;i++) 
        if(mark[i]==false&&Find(i)==i) 
            sum++; 
    ans[p]=sum; 
    for(int i=p;i>=1;i--) 
    { 
        int x=planet[i]; 
        sum++; 
        for(int j=start[x];j;j=next[j]) 
            if(mark[num[j]]==false) 
            { 
                int px=Find(x),py=Find(num[j]); 
                if(px!=py)  father[py]=px,sum--; 
            } 
        ans[i-1]=sum,mark[planet[i]]=false; 
    } 
    for(int i=1;i<=n;i++) 
        for(int j=start[i];j;j=next[j]) 
        { 
            int x=Find(i),y=Find(j); 
            if(x!=y)  father[y]=x; 
        } 
    for(int i=0;i<=p;i++) 
        printf("%d\n",ans[i]);
    return 0; 
}
