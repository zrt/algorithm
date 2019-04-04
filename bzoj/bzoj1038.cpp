#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
const double eps=1e-10;
int x[305],y[305];
struct Point{
	double x,y;
	Point(double xx=0,double yy=0){
		x=xx;y=yy;
	}
};
typedef Point Vector;
Vector operator - (const Point&a,const Point&b){
	return Vector(a.x-b.x,a.y-b.y);
}
Vector operator * (const Vector a,double t){
	return Vector(a.x*t,a.y*t);
}
Vector operator + (const Vector&a,const Vector&b){
	return Vector(a.x+b.x,a.y+b.y);
}
struct Line{
	Point p;Vector v;
	long double ang;
	Line(){}
	Line(const Point&pp,const Vector&vv){
		p=pp,v=vv;
		ang=atan2((long double)v.y,(long double)v.x);
	}
	friend bool operator < (const Line&a,const Line&b){
		return a.ang<b.ang;
	}
}L[1000];
double Cross(const Vector& a,const Vector& b){
	return a.x*b.y-a.y*b.x;
}
bool OnLeft(const Line&a,const Point&b){
	return Cross(a.v,b-a.p)>-eps;
}
Point Jiao(const Line&a,const Line&b){
	Vector u=a.p-b.p;
	double t=Cross(b.v,u)/Cross(a.v,b.v);
	return a.p+a.v*t;
}
int num;
Point p[1000];
Line q[1000];
int h,t;
bool banpingmianjiao(int n){
	sort(L,L+n);
	q[h=t=0]=L[0];
	for(int i=1;i<n;i++){
		while(h<t&&!OnLeft(L[i],p[t-1])) t--;
		while(h<t&&!OnLeft(L[i],p[h])) h++;
		q[++t]=L[i];
		if(fabs(Cross(q[t].v,q[t-1].v))<eps){
			t--;
			if(!OnLeft(L[i],q[t].p)) q[t]=L[i];
		}
		if(h<t) p[t-1]=Jiao(q[t],q[t-1]);
	}
	while(h<t&&!OnLeft(q[h],p[t-1])) t--;
	if(t-h<=1) return 0;
	return 1;
}
bool judge(double h){
	for(int j=1;j<n;j++){
		num=0;
		L[num++]=Line(Point(x[j],y[j]),Vector(0,-1));
		L[num++]=Line(Point(x[j+1],y[j+1]),Vector(0,1));
		for(int i=1;i<n;i++){
			L[num++]=Line(Point(x[i],y[i]),Point(x[i+1],y[i+1])-Point(x[i],y[i]));
		}
		L[num++]=Line(Point(x[j+1],y[j+1]+h),Point(x[j],y[j])-Point(x[j+1],y[j+1]));
		if(banpingmianjiao(num)) return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&y[i]);
	}
	double l=0,r=1e10;
	double mid;
	for(int tt=0;tt<=64;tt++){
		mid=(l+r)/2;
		if(judge(mid)) r=mid;
		else l=mid;
	}
	printf("%.3f\n",r+eps);
	return 0;
}
