/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
long long f[105],ff[105];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n,k,d;
    int mod=1e9+7;
    f[0]=ff[0]=1;
    scanf("%d%d%d",&n,&k,&d);
//  for(int i=1;i<=k;i++) f[i]=1;
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=min(k,i);j++){
            f[i]+=f[i-j];
            if(f[i]>=mod) f[i]-=mod;
        }
    }
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=min(d-1,i);j++){
            ff[i]+=ff[i-j];
            if(ff[i]>=mod) ff[i]-=mod;
        }
    }
    printf("%I64d\n",(f[n]-ff[n]+mod)%mod);
    return 0;
}
