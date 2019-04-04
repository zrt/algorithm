#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,b,mod;
int a[505];
typedef long long LL;
int f[505][505];
int main(){
    scanf("%d%d%d%d",&n,&m,&b,&mod);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<=b-a[i];k++){
                f[j+1][k+a[i]]=(f[j+1][k+a[i]]+f[j][k])%mod;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=b;i++) ans=(ans+f[m][i])%mod;
    printf("%d\n",ans);
    
    return 0;
}
