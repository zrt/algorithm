#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long LL;
LL a[100005],n,k;
LL maxx=0;
LL l,r;
bool judge(LL x){
    LL sum=0;
    LL cnt=0;
    for(int i=1;i<=n;i++){
        if(sum+a[i]>x){
            sum=a[i];
            cnt++;
            if(cnt>k) return 0;
        }else{
            sum+=a[i];
        }
    }
    if(sum)cnt++;
    if(cnt<=k) return 1;
    else return 0;
}
LL sum;
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        maxx=max(maxx,a[i]);
        sum+=a[i];
    }
    l=maxx-1,r=sum;
    while(r-l>1){
        int m=(l+r)>>1;
        if(judge(m)){
            r=m;
        }else l=m;
    }
    printf("%lld\n",r);
    return 0;
}
