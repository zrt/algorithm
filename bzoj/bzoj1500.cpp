#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
 
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
const int MAXN=600005;
int stk[600005],top;
int val[MAXN],ls[MAXN],rs[MAXN],fa[MAXN],root,maxl[MAXN],maxr[MAXN],maxm[MAXN],siz[MAXN],sum[MAXN],set[MAXN];
bool rev[MAXN];
int a[MAXN];
int cc;
inline void init(int x){
    rev[x]=0;
    set[x]=ls[x]=fa[x]=rs[x]=maxl[x]=maxr[x]=maxm[x]=siz[x]=val[x]=sum[x]=0;
}
inline int getnew(){
    if(top>0){
        init(stk[top-1]);
        return stk[--top];
    }else return ++cc;
}
 
inline void push_down(int x){
    if(!x) return;
    if(set[x]){
        rev[x]=0;
        if(ls[x]){
            set[ls[x]]=1;
            val[ls[x]]=val[x];
            rev[ls[x]]=0;
            sum[ls[x]]=val[x]*siz[ls[x]];
            maxl[ls[x]]=maxr[ls[x]]=maxm[ls[x]]=max(val[x],sum[ls[x]]);
        }
        if(rs[x]){
            val[rs[x]]=val[x];
            set[rs[x]]=1;
            rev[rs[x]]=0;
            sum[rs[x]]=val[x]*siz[rs[x]];
            maxl[rs[x]]=maxr[rs[x]]=maxm[rs[x]]=max(val[x],sum[rs[x]]);
        }
        set[x]=0;
    }
    if(rev[x]){
        swap(ls[x],rs[x]);
        if(ls[x]) rev[ls[x]]^=1;
        if(rs[x]) rev[rs[x]]^=1;
        rev[x]=0;
        if(ls[x]){
            swap(maxl[ls[x]],maxr[ls[x]]);
        }
        if(rs[x]){
            swap(maxl[rs[x]],maxr[rs[x]]);
        }
    }
}
inline void push_up(int x){
    if(!x) return;
    siz[x]=1;
    if(ls[x]) siz[x]+=siz[ls[x]];
    if(rs[x]) siz[x]+=siz[rs[x]];
    sum[x]=val[x];
    if(ls[x]) sum[x]+=sum[ls[x]];
    if(rs[x]) sum[x]+=sum[rs[x]];
    if(ls[x]){
        maxl[x]=max(maxl[ls[x]],max(sum[ls[x]]+val[x],sum[ls[x]]+val[x]+maxl[rs[x]]));
    }else maxl[x]=max(val[x],val[x]+maxl[rs[x]]);
    if(rs[x]){
        maxr[x]=max(maxr[rs[x]],max(sum[rs[x]]+val[x],sum[rs[x]]+val[x]+maxr[ls[x]]));
    }else maxr[x]=max(val[x],val[x]+maxr[ls[x]]);
    if(ls[x]&&rs[x]){
        maxm[x]=max(maxm[ls[x]],max(maxm[rs[x]],max(max(val[x],maxr[ls[x]]+val[x]),max(maxl[rs[x]]+val[x],maxl[rs[x]]+maxr[ls[x]]+val[x]))));
    }else if(ls[x]){
        maxm[x]=max(maxr[x],maxm[ls[x]]);
    }else if(rs[x]){
        maxm[x]=max(maxl[x],maxm[rs[x]]);
    }else{
        maxm[x]=val[x];
    }
}
int mk(int l,int r){
    if(l>r) return 0;
    if(l==r){
        int c=getnew();
        val[c]=a[l];
        push_up(c);
        return c;
    }else{
        int mid=(l+r)>>1;
        int c=getnew();
        val[c]=a[mid];
        ls[c]=mk(l,mid-1);
        rs[c]=mk(mid+1,r);
        if(ls[c]) fa[ls[c]]=c;
        if(rs[c]) fa[rs[c]]=c;
        push_up(c);
        return c;
    }
}
inline void zig(int x){
    int y=fa[x];push_down(fa[y]);push_down(y);push_down(x);//!!!!!!!!!!!!!!!!!!!!11
    if(rs[x]) ls[y]=rs[x],fa[rs[x]]=y;else ls[y]=0;
    fa[x]=fa[y];
    if(fa[x]){
        if(ls[fa[x]]==y) ls[fa[x]]=x;else rs[fa[x]]=x;
    }
    fa[y]=x;rs[x]=y;
    push_up(y);
}
inline void zag(int x){
    int y=fa[x];
    if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;else rs[y]=0;
    fa[x]=fa[y];
    if(fa[x]){
        if(ls[fa[x]]==y) ls[fa[x]]=x;else rs[fa[x]]=x;
    }
    fa[y]=x;ls[x]=y;
    push_up(y);
}
int list[MAXN],t;
inline void splay(int x,int z){
	int f=x;t=0;
	for(;f!=z;f=fa[f]) list[t++]=f;
	list[t++]=z;
	for(int i=t-1;i>=0;i--) push_down(list[i]);
    while(fa[x]!=z){
        int y=fa[x];
        if(fa[y]==z){
            if(ls[y]==x) zig(x);else zag(x);
        }else{
            if(ls[fa[y]]==y){
                if(ls[y]==x) zig(y),zig(x);
                else zag(x),zig(x);
            }else{
                if(ls[y]==x) zig(x),zag(x);
                else zag(y),zag(x);
            }
        }
    }
    if(!z) root=x;
}
inline int getpos(int pos){
    pos++;
    int o=root;
    push_down(o);
    while(siz[ls[o]]+1!=pos){
        if(siz[ls[o]]>=pos) o=ls[o];
        else pos-=siz[ls[o]]+1,o=rs[o];
        push_down(o);
    }
    return o;
}
void dfs_del(int x){
    if(x==0) return;
    stk[top++]=x;
    if(ls[x]) dfs_del(ls[x]);
    if(rs[x]) dfs_del(rs[x]);
}
inline void del(int x){
    int y=fa[x];
    if(ls[y]==x) ls[y]=0;else rs[y]=0;
    push_up(y);
    dfs_del(x);
}
int n,m;
char s[20];
int main(){
    val[0]=-inf;siz[0]=0;
    maxm[0]=maxr[0]=maxl[0]=-inf;
    scanf("%d%d",&n,&m);
    a[1]=-inf;a[n+2]=-inf;
    int lim=n+1;
    for(int i=2;i<=lim;i++){
        scanf("%d",&a[i]);
    }
    root=mk(1,n+2);
    int A,b,tot,posi,c;
    while(m--){
        scanf("%s",s);
        if(s[0]=='I'){
            scanf("%d%d",&posi,&tot);
            if(tot==0) continue;
            n+=tot;
            for(int i=1;i<=tot;i++){
                scanf("%d",&a[i]);
            }
            c=mk(1,tot);
            A=getpos(posi);
            b=getpos(posi+1);
            splay(A,0);
            splay(b,A);
            ls[b]=c;
            fa[c]=b;
            push_up(b);
            splay(c,0);
        }else if(s[0]=='D'){
            scanf("%d%d",&posi,&tot);
            if(tot==0) continue;
            n-=tot;
            A=getpos(posi-1);
            b=getpos(posi+tot);
            splay(A,0);splay(b,A);
            del(ls[b]);
        }else if(s[0]=='M'&&s[2]=='K'){
            scanf("%d%d%d",&posi,&tot,&c);
            if(tot==0) continue;
            A=getpos(posi-1);
            b=getpos(posi+tot);
            splay(A,0);splay(b,A);
            A=ls[b];
            val[A]=c;
            set[A]=1;
            rev[A]=0;
            sum[A]=c*siz[A];
            maxl[A]=maxr[A]=maxm[A]=max(c,c*siz[A]);
            push_down(A);
            push_up(b);
            splay(A,0);
        }else if(s[0]=='R'){
            scanf("%d%d",&posi,&tot);
            if(tot==0) continue;
            A=getpos(posi-1);
            b=getpos(posi+tot);
            splay(A,0);
            splay(b,A);
            rev[ls[b]]^=1;
            swap(maxl[ls[b]],maxr[ls[b]]);
            splay(ls[b],0);
        }else if(s[0]=='G'){
            scanf("%d%d",&posi,&tot);
            if(tot==0){
                puts("0");continue;
            }
            A=getpos(posi-1);
            b=getpos(posi+tot);
            splay(A,0);
            splay(b,A);
            printf("%d\n",sum[ls[b]]);
            splay(ls[b],0);
        }else{
            A=getpos(0);
            b=getpos(n+1);
            splay(A,0);splay(b,A);
            printf("%d\n",maxm[ls[b]]);
            splay(ls[b],0);
        }
    }
    return 0;
}
