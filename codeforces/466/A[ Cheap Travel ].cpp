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
int n,m,a,b;
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d%d%d",&n,&m,&a,&b);
    printf("%d\n",min(min(n*a,n/m*b+n%m*a),((n-1)/m+1)*b));
    
    return 0;
}
