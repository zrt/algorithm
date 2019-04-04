#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
multiset<LL> s;
LL a[500005];
int n;
LL ans;
LL two;
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]),a[i]+=a[i-1];
    if(a[n]%3){
        puts("0");
        return 0;
    }
    LL part=a[n]/3;
    for(int i=n;i>=1;i--){
        if(a[i]==part){
            ans+=two;
        }
        if(i!=n&&a[i]==part*2) two++;
    }
    printf("%I64d\n",ans);
    return 0;
}
