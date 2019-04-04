#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int m,n;
double ms[100005];
double a[100005];
double f[100005];
double pw(double x,int p){
    double ret=1;
    while(p){
        if(p&1) ret*=x;
        x*=x;
        p>>=1;
    }
    return ret;
}
int main(){
    #ifdef LOCAL
//  freopen("in.txt","r",stdin);
//  freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d",&m,&n);
    double ans=0;
    for(int i=1;i<=m;i++){
        ans+=(pw(i/(double)m,n)-pw((i-1)/(double)m,n))*i;
    }
    printf("%.13f\n",ans);
    return 0;
}
