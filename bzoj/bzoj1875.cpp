#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,s,t;long long q;
int H[35],X[130],P[130];
int tot;
inline void add(int x,int y){
    P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int mod=45989;
struct N{
    int a[125][125];
    friend N operator * (const N&a,const N&b){
        static N c;
        for(int i=1;i<=tot;i++){
            for(int j=1;j<=tot;j++){
                c.a[i][j]=0;
                for(int k=1;k<=tot;k++){
                    c.a[i][j]+=a.a[i][k]*b.a[k][j];
                    if(c.a[i][j]>=mod)c.a[i][j]%=mod;
                }
            }
        }
        return c;
    }
}a,c;
void pow(long long b){
    for(int i=1;i<=tot;i++) c.a[i][i]=1;
    while(b){
        if(b&1) c=c*a;
        b>>=1;
        a=a*a;
    }
}
int ans[35];
int main(){
    scanf("%d%d%lld%d%d",&n,&m,&q,&s,&t);
    tot=1;
    for(int i=0,x,y;i<m;i++){
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=2;i<=tot;i++){
        for(int j=H[P[i]];j;j=X[j]){
            if(j!=(i^1)){
                a.a[i][j]=1;
            }
        }
    }
    for(int i=H[s];i;i=X[i]){
        a.a[1][i]=1;
    }
    pow(q);
    for(int i=2;i<=tot;i++){
        ans[P[i]]=(ans[P[i]]+c.a[1][i])%mod;
    }
    printf("%d\n",ans[t]);
    return 0;
}
