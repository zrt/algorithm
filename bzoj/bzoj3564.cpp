#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
struct point{
    double x,y;
}p[100005],o;
int n;
double r;
const double eps=1e-10;
inline double sqr(double x){
    return x*x;
}
inline double dis(point a,point b){
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
point geto(point a,point b,point c){
    double a1=b.x-a.x,b1=b.y-a.y;
    double c1=(sqr(a1)+sqr(b1))/2;
    double a2=c.x-a.x,b2=c.y-a.y;
    double c2=(sqr(a2)+sqr(b2))/2;
    double d=a1*b2-a2*b1;
    point o;
    o.x=a.x+(c1*b2-c2*b1)/d,o.y=a.y+(a1*c2-a2*c1)/d;    
    return o;
}
double rad_;
double P;
double cos_,sin_;
point trans(point a){
    point b;
    b.x=cos_*a.x+sin_*a.y;
    b.y=cos_*a.y-sin_*a.x;
    b.x/=P;
    return b;
}
int main(){
    srand(401794301);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
    random_shuffle(p+1,p+n+1);
    scanf("%lf%lf",&rad_,&P);
    rad_=rad_*acos(-1)/180;
    cos_=cos(rad_),sin_=sin(rad_);
    for(int i=1;i<=n;i++) p[i]=trans(p[i]);
    o=p[1];
    for(int i=1;i<=n;i++){
        if(dis(o,p[i])<r+eps) continue;
        o.x=(p[i].x+p[1].x)/2,o.y=(p[i].y+p[1].y)/2,r=dis(p[i],p[1])/2;
        for(int j=2;j<i;j++){
            if(dis(o,p[j])<r+eps) continue;
            o.x=(p[i].x+p[j].x)/2,o.y=(p[i].y+p[j].y)/2,r=dis(p[i],p[j])/2;
            for(int k=1;k<j;k++){
                if(dis(o,p[k])<r+eps) continue;
                o=geto(p[i],p[j],p[k]);
                r=dis(o,p[i]);
            }
        }
    }
    printf("%.3f\n",r);
    return 0;
}
