#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
typedef double ld;
void read(int&x){scanf("%d",&x);}
void read(long double&x){double xx;scanf("%lf",&xx);x=xx;}
void read(char*s){scanf("%s",s);}

ld a,b,c,d;
void calc(ld&mn,ld&mx,ld a,ld b,ld x){
    // a-x,a+x * b-x,b+x// max
    mn=min(min((a-x)*(b-x),(a-x)*(b+x)),min((a+x)*(b-x),(a+x)*(b+x)));
    mx=max(max((a-x)*(b-x),(a-x)*(b+x)),max((a+x)*(b-x),(a+x)*(b+x)));
}
bool judge(ld x){
    ld mn1,mn2,mx1,mx2;
    calc(mn1,mx1,a,d,x);
    calc(mn2,mx2,b,c,x);
    if(mn1>mx2||mx1<mn2) return 0;
    else return 1;
}
int main(){
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    ld l=0,r=1e10;
    for(int i=0;i<=1000;i++){
        ld mid=(l+r)/2;
        if(judge(mid)) r=mid;
        else l=mid;
    }
    printf("%.10f\n",l);
    return 0;
}
