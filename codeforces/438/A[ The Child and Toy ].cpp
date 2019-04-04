#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n,m;
int H[1005],P[4005],X[4005],tot;
inline void add(int x,int y){
    P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int v[1005];
int h,t,q[1005];
int maxx[1005];
bool cmp(int x,int y){
    return x>y;
}
bool vis[1005];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d",&n,&m);long long ans=0;
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=0,x,y;i<m;i++){
        scanf("%d%d",&x,&y);
        ans+=min(v[x],v[y]);
    }
    
    
    printf("%I64d\n",ans);
    return 0;
}
