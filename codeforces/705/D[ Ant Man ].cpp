#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long LL;
#define int long long

int n,s,e;

int x[5005],a[5005],b[5005],c[5005],d[5005];
LL dp[5005][5005];
LL inf;

signed main(){

    scanf("%I64d%I64d%I64d",&n,&s,&e);
    for(int i=1;i<=n;i++) scanf("%I64d",&x[i]);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%I64d",&b[i]);
    for(int i=1;i<=n;i++) scanf("%I64d",&c[i]);
    for(int i=1;i<=n;i++) scanf("%I64d",&d[i]);

    if(s>e){
        s=n-s+1;
        e=n-e+1;
        reverse(x+1,x+n+1);
        reverse(a+1,a+n+1);
        reverse(b+1,b+n+1);
        reverse(c+1,c+n+1);
        reverse(d+1,d+n+1);
        for(int i=1;i<=n;i++) swap(a[i],b[i]);
        for(int i=1;i<=n;i++) swap(c[i],d[i]);
    }
    //s left e right
    //dp[][]
    memset(dp,0x3f,sizeof dp);
    dp[1][0]=0;
    inf=dp[0][0];

    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j==0&&i!=1) continue;
            if(dp[i][j]!=inf){
                if(i==s){
                    /*
                        i==s
                        1 ->| 2 |-> 3 |<- 4 <-|
                    */
                    //2
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+d[i]+(j+1)*abs(x[i+1]-x[i]));
                    //4
                    if(j>=2) dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+c[i]+(j-1)*abs(x[i+1]-x[i]));

                    
                }else if(i==e){
                    /*
                        i==e
                        1 ->| 2 |-> 3 |<- 4 <-|
                    */
                    //1
                    if(j>=2 || e == n) dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+a[i]+(j-1)*abs(x[i+1]-x[i]));
                    //3
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+b[i]+(j+1)*abs(x[i+1]-x[i]));
                    
                    
                }else{
                    //i!=s i!=e
                    /*
                        1 > 2 v 3 < 4 ^
                    */
                    //1
                    if(j>=3) dp[i+1][j-2]=min(dp[i+1][j-2],dp[i][j]+a[i]+c[i]+(j-2)*(abs(x[i+1]-x[i])));
                    if(j==2&&(i==n)) dp[i+1][j-2]=min(dp[i+1][j-2],dp[i][j]+a[i]+c[i]);
                    //2
                    if(j>0) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i]+d[i]+j*abs(x[i+1]-x[i]));
                    //4
                    if(j>1) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+b[i]+c[i]+j*abs(x[i+1]-x[i]));
                    //3
                    dp[i+1][j+2]=min(dp[i+1][j+2],dp[i][j]+d[i]+b[i]+(j+2)*abs(x[i+1]-x[i]));
                    
                }
            }
        }
    }
    printf("%I64d\n",dp[n+1][0]);


    return 0;
}