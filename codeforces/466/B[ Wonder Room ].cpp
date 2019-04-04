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
long long n,a,b;
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%I64d%I64d%I64d",&n,&a,&b);
    if(a*b>=6*n){
        printf("%I64d\n%I64d %I64d\n",a*b,a,b);
    }else{
        n*=6;
        LL MAX=(n-1)/b+1;
        LL ans=1LL<<62;
        LL pos;
        for(LL i=a;i<=MAX;i++){
            LL c=(n-1)/i+1;
            if(c<b) break;
            if(i*c<ans){
                ans=i*c;
                pos=i;
            }
            if(i>n-1) break; 
            i= (n-1)/((n-1)/i);
        }
        printf("%I64d\n%I64d %I64d\n",ans,pos,(n-1)/pos+1);     
    }
    
    return 0;
}
