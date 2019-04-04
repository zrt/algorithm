#include<cstdio>
#include<cstring>
using namespace std;
int H[2005],X[4005],P[4005],tot;
inline void add(int x,int y){
    P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int v[2005];
int n,d;
long long ans;
long long mod=1e9+7;
bool vis[2005];

long long calc(int x,int mx,int mn,int p){
    vis[x]=1;
    long long num=1;
    for(int i=H[x];i;i=X[i]){
        if(!vis[P[i]]&&v[P[i]]>=mn&&v[P[i]]<=mx){
            if(v[P[i]]==mx&&P[i]>p) continue;
            num=num*(calc(P[i],mx,mn,p)+1)%mod;
        }
    }
    return num;
}

int main(){
    scanf("%d%d",&d,&n);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++) memset(vis,0,sizeof vis),ans+=calc(i,v[i],v[i]-d,i),ans%=mod;
    printf("%I64d\n",ans);
//  while(1);
    return 0;
}