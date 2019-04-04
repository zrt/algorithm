#include<cstdio>
#include<algorithm>
using namespace std;
int H[500005],X[1000005],P[1000005],tot;

inline void add(int x,int y){
    P[++tot]=y;X[tot]=H[x];H[x]=tot;
}

int fr[500005],ls[500005];
bool vis[500005];
int tim;

void dfs(int x){
    vis[x]=1;
    fr[x]=++tim;
    for(int i=H[x];i;i=X[i]){
        if(!vis[P[i]]){
            dfs(P[i]);
        }
    }
    ls[x]=++tim;
}

int n,m;

int t1[1000005*3],t2[1000005*3]; //tree1  tree2 //
int set[1000005*3];
int _l,_r,_c,_ret;
int pos;
void pushdown(int o){
    if(set[o]){
        t1[o<<1]=t1[o<<1|1]=set[o<<1]=set[o<<1|1]=set[o];
        set[o]=0;
    }
}
void add1(int o,int l,int r){ //区间覆盖 单点 
    if(_l<=l&&r<=_r){
        t1[o]=set[o]=_c;
    }else{
        pushdown(o);
        int m=(l+r)>>1;
        if(_l<=m) add1(o<<1,l,m);
        if(_r>m) add1(o<<1|1,m+1,r);
    }
}
void add2(int o,int l,int r){//单点覆盖  区间max 
    if(l==r){
        t2[o]=_c;
    }else{
        int m=(l+r)>>1;
        if(pos<=m){
            add2(o<<1,l,m);
        }else add2(o<<1|1,m+1,r);
        t2[o]=max(t2[o<<1],t2[o<<1|1]);
    }
}
void ask1(int o,int l,int r){//单点查询 
    if(l==r){
        _ret=t1[o];
    }else{
        int m=(l+r)>>1;
        pushdown(o);
        if(pos<=m){
            ask1(o<<1,l,m);
        }else ask1(o<<1|1,m+1,r);
    }
}
void ask2(int o,int l,int r){//区间查询 
    if(_l<=l&&r<=_r){
        _ret=max(_ret,t2[o]);
    }else{
        int m=(l+r)>>1;
        if(_l<=m) ask2(o<<1,l,m);
        if(_r>m) ask2(o<<1|1,m+1,r);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    dfs(1);
    scanf("%d",&m);
    //优先操作2 
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        if(x==1){
            _l=fr[y],_r=ls[y];_c=i;
            add1(1,1,tim);
        }else if(x==2){
            _c=i;
            pos=fr[y];
            add2(1,1,tim);
            pos=ls[y];
            add2(1,1,tim);
        }else{
            pos=fr[y];
            ask1(1,1,tim);
            int val1=_ret;
            pos=ls[y];
            ask1(1,1,tim);
            val1=max(val1,_ret);
            _l=fr[y];_r=ls[y];
            _ret=-1;
            ask2(1,1,tim);
            int val2=_ret;
            if(val1>val2) puts("1");
            else puts("0");
        }
    }
    return 0;
}