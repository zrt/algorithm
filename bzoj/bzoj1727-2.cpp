#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
struct N{
    int id,a,b;
}a[250050];
int n;
bool cmp(N a,N b){
    return max(a.a+b.a+b.b,a.a+a.b+b.b)<max(b.a+a.b+b.b,b.a+a.a+a.b);
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        a[i].id=i;
        scanf("%d%d",&a[i].a,&a[i].b);
    }
    sort(a+1,a+n+1,cmp);
    int tima=0,timb=0;
    for(int i=1;i<=n;i++){
        tima+=a[i].a;
        timb=max(timb,tima);
        timb+=a[i].b;
    }
    printf("%d\n",timb);
    return 0;
}
