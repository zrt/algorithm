#include<cstdio>
#include<cstring>
#include<algorithm>
#define lowbit(x) (x&-x)
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n,m;
char s[10];
int H[250005],P[250005],X[250005],tot;
int f[250005],l[250005];
int c[500005];
int tim;
int stk[500005],top;
void add(int pos,int x){
    for(;pos<=n;pos+=lowbit(pos)){
        c[pos]+=x;
    }
}
int ask(int pos){
    int ret=0;
    for(;pos>0;pos-=lowbit(pos)){
        ret+=c[pos];
    }
    return ret;
}
inline void Add(int x,int y){
    P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        if(x<y) Add(x,y);
        else Add(y,x);
    }
    stk[top++]=1;
    int k;
    while(top>0){
        k=stk[--top];
        if(f[k]){
            l[k]=++tim;
            c[tim]=-1;
            continue;
        }else{
            f[k]=++tim;
            c[tim]=1;
            stk[top++]=k;
            for(int i=H[k];i;i=X[i]){
                stk[top++]=P[i];
            }
            continue;
        }
    }
    n*=2;
    for(int i=1;i<n;i++){
        if(i+lowbit(i)<=n){
            c[i+lowbit(i)]+=c[i];
        }
    }
    scanf("%d",&m);
    m=n/2+m-1;
    for(int i=0,x,y;i<m;i++){
        scanf("%s",s);
        if(s[0]=='W'){
            scanf("%d",&x);
            printf("%d\n",ask(f[x])-1);
        }else{
            scanf("%d%d",&x,&y);
            if(x>y){
                add(f[x],-1);
                add(l[x],1);
            }else{
                add(f[y],-1);
                add(l[y],1);
            }
        }
    }
    return 0;
}
