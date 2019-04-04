#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n,s,l;
int q1[100005],h1,t1;
int q2[100005],h2,t2;
int a[100005];
int mn[400005];

void change(int o,int l,int r,int pos,int k){
    if(l==r){
        mn[o]=min(mn[o],k);
    }else{
        int mid=(l+r)/2;
        if(pos<=mid){
            change(o<<1,l,mid,pos,k);
        }else{
            change(o<<1|1,mid+1,r,pos,k);
        }
        mn[o]=min(mn[o<<1],mn[o<<1|1]);
    }
}
int ask(int o,int l,int r,int L ,int R){
    if(L==l&&R==r){
        return mn[o];
    }else{
        int mid=(l+r)>>1;
        if(R<=mid){
            return ask(o<<1,l,mid,L,R);
        }else if(L>mid) return ask(o<<1|1,mid+1,r,L,R);
        else return min(ask(o<<1,l,mid,L,mid),ask(o<<1|1,mid+1,r,mid+1,R));
    }
}
int ask(int L,int R){
    return ask(1,0,n,L,R);
}
int main(){
    scanf("%d%d%d",&n,&s,&l);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int pos=1;
    memset(mn,0x3f,sizeof mn);
    change(1,0,n,0,0);
    for(int i=1;i<=n;i++){
        //q1 mx
        //q2 mn
        while(h1!=t1&&a[q1[t1-1]]<=a[i]) t1--;
        q1[t1++]=i;
        while(h2!=t2&&a[q2[t2-1]]>=a[i]) t2--;
        q2[t2++]=i;
        while(a[q1[h1]]-a[q2[h2]]>s){
            if(q1[h1]==pos) h1++;
            if(q2[h2]==pos) h2++;
            pos++;
        }
        int L=pos-1;
        int R=i-l;
        if(L>R) continue;
        change(1,0,n,i,ask(L,R)+1);
    }
    int ans=ask(n,n);
    if(ans>n){
        puts("-1");
    }else{
        printf("%d\n",ans);
    }
//  while(1);
    return 0;
}