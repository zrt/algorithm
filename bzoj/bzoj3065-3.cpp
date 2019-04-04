#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
typedef long double ld;
const ld alpha=0.85;
int n,m;
int v[75005],dfn[75005];
int root,lastans,K;
int tmp,sz;
int rt[75005],ls[75005],rs[75005];
vector<int> rec,t,p;
struct seg{
    int l,r,sum;
}a[10000500];
inline int newnode(){
    if(!rec.size()) return ++sz;
    else{
        int k=rec.back();rec.pop_back();
        return k;
    }
}
void reclaim(int &x){
    if(!x) return;
    rec.push_back(x);
    reclaim(a[x].l);reclaim(a[x].r);
    a[x].sum=0;x=0;
}
void insert(int &k,int l,int r,int val,int f){
    if(!k) k=newnode();
    if(l==r){
        a[k].sum+=f;return;
    }
    int mid=(l+r)>>1;
    if(val<=mid) insert(a[k].l,l,mid,val,f);
    else insert(a[k].r,mid+1,r,val,f);
    a[k].sum=a[a[k].l].sum+a[a[k].r].sum;
    if(!a[k].sum) reclaim(k);
}
void build(int &k,int l,int r){
    if(l>r) return;
    if(l==r){
        k=dfn[l];insert(rt[k],0,70000,v[k],1);
        return;
    }
    int mid=(l+r)>>1;
    k=dfn[mid];
    build(ls[k],l,mid-1);
    build(rs[k],mid+1,r);
    for(int i=l;i<=r;i++){
        insert(rt[k],0,70000,v[dfn[i]],1);
    }
}
int modify(int k,int x,int val){
    insert(rt[k],0,70000,val,1);
    int t,L=a[rt[ls[k]]].sum;
    if(L+1==x){
        t=v[k];v[k]=val;
    }else if(L>=x){
        t=modify(ls[k],x,val);
    }else{
        t=modify(rs[k],x-L-1,val);
    }
    insert(rt[k],0,70000,t,-1);
    return t;
}
void del(int&x){
    if(!x) return;reclaim(rt[x]);
    del(ls[x]);p.push_back(x);del(rs[x]);
    x=0;
}
void rebuild(int&x){
    del(x);int s1=p.size();
    for(int i=1;i<=s1;i++) dfn[i]=p[i-1];
    build(x,1,s1);
    p.clear();
}
void insert(int &k,int x,int val){
    if(!k){
        k=++n;
        insert(rt[k],0,70000,val,1);
        v[k]=val;
        return;
    }
    insert(rt[k],0,70000,val,1);
    int L=a[rt[ls[k]]].sum;
    if(L>=x) insert(ls[k],x,val);
    else insert(rs[k],x-L-1,val);
    if(a[rt[k]].sum*alpha>max(a[rt[ls[k]]].sum,a[rt[rs[k]]].sum)){
        if(tmp){
            if(ls[k]==tmp) rebuild(ls[k]);
            else rebuild(rs[k]);
            tmp=0;
        }
    }else tmp=k;
}
void query(int k,int l,int r){
    int L=a[rt[ls[k]]].sum,R=a[rt[k]].sum;
    if(l==1&&r==R) {
        t.push_back(rt[k]);
        return;
    }
    if(l<=L+1&&r>=L+1) p.push_back(v[k]);
    if(r<=L) query(ls[k],l,r);
    else if(l>L+1) query(rs[k],l-L-1,r-L-1);
    else{
        if(l<=L) query(ls[k],l,L);
        if(r>L+1) query(rs[k],1,r-L-1);
    }
}
int solve_query(int L,int R,int K){
    query(root,L,R);K--;
    int l=0,r=70000,s1=t.size(),s2=p.size();
    while(l<r){
        int mid=(l+r)>>1,sum=0;
        for(int i=0;i<s1;i++) sum+=a[a[t[i]].l].sum;
        for(int i=0;i<s2;i++) if(p[i]>=l&&p[i]<=mid) sum++;
        if(K<sum){
            for(int i=0;i<s1;i++) t[i]=a[t[i]].l;
            r=mid;
        }else{
            for(int i=0;i<s1;i++) t[i]=a[t[i]].r;
            l=mid+1,K-=sum;
        }
    }
    t.clear();p.clear();
    return l;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++) dfn[i]=i;
    build(root,1,n);
    scanf("%d",&m);
    char ch[2];
    int x,y,K;
    while(m--){
        scanf("%s%d%d",ch,&x,&y);
        x^=lastans;y^=lastans;
        if(ch[0]=='Q'){
            scanf("%d",&K);
            K^=lastans;
            lastans=solve_query(x,y,K);
            printf("%d\n",lastans);
        }else if(ch[0]=='M'){
            modify(root,x,y);
        }else{
            tmp=0;
            insert(root,x-1,y);
        }
    }
    return 0;
}
