#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
double X1,Y1,x2,y2,vm,t,vx,vy,wx,wy;
double sqr(double x){
    return x*x;
}
bool judge(double T){
    double x,y;
    x=X1,y=Y1;
    if(T>t){
        x+=vx*t;
        y+=vy*t;
        x+=(T-t)*wx;
        y+=(T-t)*wy;
        double dis=sqrt(sqr(x-x2)+sqr(y-y2));
        return dis/vm<=T;
    }else{
        x+=vx*T;
        y+=vy*T;
        double dis=sqrt(sqr(x-x2)+sqr(y-y2));
        return dis/vm<=T;
    }
}
int main(){
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&X1,&Y1,&x2,&y2,&vm,&t,&vx,&vy,&wx,&wy);
    double l=0,r=1e50;
    for(int tt=0;tt<=1000;tt++){
        double mid=(l+r)/2.;
        if(judge(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    printf("%.15f\n",l);
    
    return 0;
}