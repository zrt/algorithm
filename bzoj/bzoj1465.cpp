#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
//by zrt
//problem:
using namespace std;
long long a[1000000];
long long c[1000000];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    long long sum=0;
    for(int i=0;i<n;i++) {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    sum/=n;
    c[0]=0;
    for(int i=1;i<n;i++){
        c[i]=c[i-1]+a[i]-sum;
    }
    int mid=n/2;
    nth_element(c,c+mid,c+n);
    long long ans=0;
    for(int i=0;i<n;i++) ans+=abs(c[mid]-c[i]);
    printf("%lld",ans);
     
    return 0;
}
