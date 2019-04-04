#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n,m;
int H[100005],X[4000005],P[4000005],tot;
int q[100005],h,t;
int siz[100005],cnt;
inline void add(int x,int y){
    P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int pre[100005],nxt[100005];// nxt[0] head;
bool now[100005];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    for(int i=0,x,y;i<m;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    for(int i=0;i<n;i++) nxt[i]=i+1;
    nxt[n]=0;
    for(int i=1;i<=n;i++) pre[i]=i-1;
    int k;
    while(nxt[0]){
        {
            cnt++;h=t=0;
            q[t++]=nxt[0];
            nxt[0]=nxt[nxt[0]];
            pre[nxt[0]]=0;
            while(h!=t){
                k=q[h++];
                siz[cnt]++;
                memset(now,0,sizeof now);
                for(int i=H[k];i;i=X[i]){
                    now[P[i]]=1;
                }
                for(int i=nxt[0];i;i=nxt[i]){
                    if(!now[i]){
                        q[t++]=i;
                        nxt[pre[i]]=nxt[i];
                        pre[nxt[i]]=pre[i];
                    }
                }
            }
        }
    }
    sort(siz+1,siz+cnt+1);
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++) printf("%d ",siz[i]);
    return 0;
}
