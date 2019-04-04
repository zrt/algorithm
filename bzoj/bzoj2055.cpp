/**************************************************************
    Problem: 2055
    User: zrts
    Language: C++
    Result: Accepted
    Time:400 ms
    Memory:1308 kb
****************************************************************/
 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int H[207],X[20000],P[20000],tot=1,from[20000],c[20000],f[20000];
inline void add(int x,int y,int z,int k){
    P[++tot]=y;X[tot]=H[x];H[x]=tot;from[tot]=x;c[tot]=k;f[tot]=z;
}
int S=205,T=206,s=203,t=204;
int n,m,M;
int _cost;
int d[207];
int a[207];
bool inq[207];
int p[20000];
queue<int> q;
bool spfa(){
    memset(d,0x3f,sizeof d);
    a[T]=0;
    d[S]=0;a[S]=M;int x;q.push(S);p[S]=-1;
    inq[S]=1;
    while(!q.empty()){
        x=q.front();q.pop();
        inq[x]=0;
        for(int i=H[x];i;i=X[i]){
            if(f[i]>0&&d[P[i]]>d[x]+c[i]){
                d[P[i]]=d[x]+c[i];
                a[P[i]]=min(a[x],f[i]);
                p[P[i]]=i;
                if(!inq[P[i]]) inq[P[i]]=1,q.push(P[i]);
            }
        }
    }
    if(!a[T]) return 0;
    _cost+=a[T]*d[T];
    x=T;
    while(x!=S){
        f[p[x]]-=a[T];
        f[p[x]^1]+=a[T];
        x=from[p[x]];
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,v;i<=n;i++){
        scanf("%d",&v);
        M+=v;
        add(S,i+n,v,0);
        add(i+n,S,0,0);
        add(i,T,v,0);
        add(T,i,0,0);
    }
    add(t,s,m,0);
    add(s,t,0,0);
    for(int i=1;i<=n;i++){
        add(s,i,M*3,0);
        add(i,s,0,0);
        add(i+n,t,M,0);
        add(t,i+n,0,0);
        for(int j=i+1,c;j<=n;j++){
            scanf("%d",&c);
            if(c!=-1){
                add(i+n,j,M,c);
                add(j,i+n,0,-c);
            }
        }
    }
    while(spfa());
    printf("%d\n",_cost);
    return 0;
}
