#include <cstdio>
#include <cstring>
#include <algorithm>
//by zrt
//problem:
using namespace std;
const int inf(0x3f3f3f3f) ;
const double eps(1e-10) ;
typedef long long LL;
int mod=1000000007;
int t[2][2]={{1,1},{-1,0}};
void mul(int a[2][2],int b[2][2]){
    static int c[2][2];
    memset(c,0,sizeof c);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                c[i][j]+=a[i][k]*1LL*b[k][j]%mod;
                while(c[i][j]<0) c[i][j]+=mod;
                if(c[i][j]>=mod) c[i][j]-=mod;
            }
        }
    }
    memcpy(a,c,sizeof c);
}
int x,y,n;
int a[2][2],b[2][2];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d%d",&x,&y,&n);
    while(x<0) x+=mod;
    while(y<0) y+=mod;
    x%=mod;y%=mod;  
    memcpy(b,t,sizeof t);
    if(n==1) printf("%d\n",x);
    else if(n==2) printf("%d\n",y);
    else{
        a[0][0]=y;
        a[0][1]=x;
        
        n=n-3;
        while(n){
            if(n&1) mul(b,t);
            mul(t,t);
            n>>=1;
        }
        mul(a,b);
        printf("%d\n",a[0][0]);
    }
    return 0;
}
