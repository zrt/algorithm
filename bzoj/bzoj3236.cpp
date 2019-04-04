#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
typedef long double ld;
void read(int&x){scanf("%d",&x);}
void read(long double&x){double xx;scanf("%lf",&xx);x=xx;}
void read(LL&x){scanf("%lld",&x);}
void read(char*s){scanf("%s",s);}
// Mo-Dui
int n,m;
int a[200005];
int num[200005];
int c[200005];
int d[200005];
int belong[200005];
int SIZE;
int NUM;
struct N{
    int l,r,a,b,id;
    friend bool operator < (const N&a,const N&b){
        if(belong[a.l]!=belong[b.l]) return belong[a.l]<belong[b.l];
        return a.r<b.r;
    }
}q[1200005];
int ans1[1200005],ans2[1200005];
#define lowbit(x) ((x)&-(x))
void add(int* c,int x,int d){
    while(x<=n){
        c[x]+=d;
        x+=lowbit(x);
    }
}
int ask(int *c,int x){
    int ret=0;
    while(x){
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}
void upd(int x,int t){
    num[x]+=t;
    add(c,x,t);
    if((num[x]==1&&t==1)||(num[x]==0&&t==-1)){
        add(d,x,t);
    }
}
int ask1(int a,int b){
    return ask(c,b)-ask(c,a-1);
}
int ask2(int a,int b){
    return ask(d,b)-ask(d,a-1);
}
int main(){
    read(n);read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=m;i++){
        read(q[i].l);read(q[i].r);read(q[i].a);read(q[i].b);q[i].id=i;
    }
    SIZE=sqrt(n+1);
    NUM=(n-1)/SIZE+1;
    for(int i=1;i<=NUM;i++){
        for(int j=1;j<=SIZE;j++){
            belong[j+(i-1)*SIZE]=i;
        }
    }
    sort(q+1,q+m+1);
    int L=1,R=0;
    for(int i=1;i<=m;i++){
        while(R<q[i].r) R++,upd(a[R],1);
        while(L>q[i].l) L--,upd(a[L],1);
        while(R>q[i].r) upd(a[R],-1),R--;
        while(L<q[i].l) upd(a[L],-1),L++;
        ans1[q[i].id]=ask1(q[i].a,q[i].b);
        ans2[q[i].id]=ask2(q[i].a,q[i].b);
    }
    for(int i=1;i<=m;i++) printf("%d %d\n",ans1[i],ans2[i]);
    return 0;
}
