#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
typedef long double ld;
void read(int&x){scanf("%d",&x);}
void read(long double&x){double xx;scanf("%lf",&xx);x=xx;}
void read(LL&x){scanf("%lld",&x);}
void read(char*s){scanf("%s",s);}

int n,R;
struct Point{
	ld x,y;
	Point (ld a=0,ld b=0){
		x=a,y=b;
	}
}p[105],o;
Point operator + (Point a,Point b){
	return Point(a.x+ b.x,a.y+b.y);
}
Point operator -(Point a,Point b){
	return Point(a.x-b.x,a.y-b.y);
}
Point operator * (Point a,ld b){
	return Point(a.x*b,a.y*b);
}
ld dot(Point a,Point b){
	return a.x*b.x+a.y*b.y;
}
ld ans;
ld sqr(ld x){
	return x*x;
}
ld dis(Point a,Point b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
ld cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}
const ld PI=acos(-1);
ld calc2(Point a,Point b){
	ld l=0,r=1;
	Point p;
	for(int i=0;i<=60;i++){
		ld mid=(l+r)/2.;
		p=a+((b-a)*mid);
		if(dis(p,o)>R) l=mid;else r=mid;
	}
	return fabs(cross(p,b))/2+R*R*.5*fabs(atan2(a.y,a.x)-atan2(p.y,p.x));
}
ld calc3(Point a,Point b){
	ld l=0,r=1;
	Point c;
	for(int i=0;i<=60;i++){
		ld mid=(l+r)/2.;
		c=a+((b-a)*mid);
		if(dot(o-c,a-c)>0) r=mid;else l=mid;
	}
	return calc2(a,c)+calc2(b,c);
}
ld calc(Point a,Point b){
	ld sign;
	if(atan2(a.y,a.x)>atan2(b.y,b.x)){
		sign=-1;
	}else sign=1;
	if(dis(a,o)<=R&&dis(b,o)<=R){
//		puts("CASE 1");
		return fabs(cross(a,b))*sign/2;
	}else if(dis(a,o)>R&&dis(b,o)>R&&(fabs(cross(a,b))/dis(a,b))>R){
//		puts("CASE 2");
		return (R*R*.5*fabs(atan2(a.y,a.x)-atan2(b.y,b.x))*sign);
	}else if(dis(a,o)>R&&dis(b,o)<=R){
//		puts("CASE 3");
		return calc2(a,b)*sign;
	}else if(dis(a,o)<=R&&dis(b,o)>R){
//		puts("CASE 4");
		return calc2(b,a)*sign;
	}else{
//		puts("CASE 5");
		return calc3(a,b)*sign;
	}
}
int main(){
	while(~scanf("%d%d",&n,&R)){
		for(int i=0;i<n;i++) read(p[i].x),read(p[i].y);
		ans=0;
		for(int i=0;i<n;i++){
//			ld lastans=ans;
			ans+=calc(p[i],p[(i+1)%n]);
//			printf("%.10f\n",(double)(ans-lastans));
		}
		printf("%.9f\n",(double)ans);
	}
	return 0;
}
