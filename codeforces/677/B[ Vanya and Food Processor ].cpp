#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a[100005];
int main(){
    LL n,h,k;
    scanf("%I64d%I64d%I64d",&n,&h,&k);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    LL rem=0;
    LL ans=0;
    int p=1;
    while(p<=n){
        while(p<=n&&rem+a[p]<=h) rem+=a[p],p++;
        if(rem<k){
            if(rem>0){
                rem=0;
                ans++;
            }
        }else{
            ans+=rem/k;
            rem%=k;
        }
    }
    if(rem>0) ans++;
    printf("%I64d\n",ans);

    return 0;
}