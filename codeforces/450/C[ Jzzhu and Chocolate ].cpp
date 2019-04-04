#include <cstdio>
#include <cstring>
#include <algorithm>
//by zrt
//problem:
using namespace std;
const int inf(0x3f3f3f3f) ;
const double eps(1e-10) ;
typedef long long LL;
LL n,m,k;
long long ans=0;
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    if(n-1+m-1<k){
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(i>k+1) break;
        LL a=n/i,b=n/a;
        b=min(b,k+1);
        LL c=k-(b-1)+1;
        ans=max(ans,a*(m/(c)));
        i=b;
    }
    printf("%I64d\n",ans);
    return 0;
}
