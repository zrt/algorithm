#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
int main(){
    int n,a,b,c,d;
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    LL sum=0;
    LL mn=1,mx=n;
    for(int i=1;i<=n;i++){
        LL summn=0,summx=4*n;
        LL sum1=a+b+i,sum2=a+c+i,sum3=c+d+i,sum4=b+d+i;
        summn=max(summn,1+sum1);
        summn=max(summn,1+sum2);
        summn=max(summn,1+sum3);
        summn=max(summn,1+sum4);
        summx=min(summx,n+sum1);
        summx=min(summx,n+sum2);
        summx=min(summx,n+sum3);
        summx=min(summx,n+sum4);
        if(summx>=summn)
            sum+=summx-summn+1;

    }
    printf("%I64d\n",sum);

    return 0;
}