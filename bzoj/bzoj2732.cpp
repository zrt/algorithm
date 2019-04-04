#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int x[100005],y[100005],y2[100005];
double eps=1e-15;
struct Point{
	double x,y;
	Point(double xx=0,double yy=0){
		x=xx,y=yy;
	}
};
typedef Point Vector;
double Cross(const Vector&a,const Vector&b){
	return a.x*b.y-a.y*b.x;
}
struct Line{
	Point p;Vector v;int id;
	long double ang;
	friend bool operator < (const Line&a,const Line&b){
		return a.ang<b.ang;
	}	
}a[210005];
Vector operator -(const Point&a,const Point&b){
	return Vector(a.x-b.x,a.y-b.y);
}
Vector operator * (const Vector&a,const double&t){
	return Vector(a.x*t,a.y*t);
}
Vector operator + (const Vector&a,const Vector&b){
	return Vector(a.x+b.x,a.y+b.y);
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
Point p[210005];
Line q[210005];
int banpingmianjiao(Line*L,int n,int lim){
	int h,t;
	//Point*p=new Point[n];
	//Line*q=new Line[n];
	int pos=1;
	while(pos<=n&&L[pos].id>lim) pos++;
	if(pos==n+1) return 0;
	q[h=t=0]=L[pos];
	pos++;
	while(pos<=n&&L[pos].id>lim) pos++;
	for(;pos<=n;){
		while(h<t&&!OnLeft(L[pos],p[t-1])) t--;
		while(h<t&&!OnLeft(L[pos],p[h]))   h++;
		q[++t]=L[pos];
		if(fabs(Cross(q[t].v,q[t-1].v))<eps){
			t--;
			if(OnLeft(q[t],L[pos].p)) q[t]=L[pos];
		}
		if(h<t)p[t-1]=Jiao(q[t-1],q[t]);
		pos++;
		while(pos<=n&&L[pos].id>lim) pos++;
	}
	while(h<t&&!OnLeft(q[h],p[t-1])) t--;
	if(t-h<=1) return 0;
	return 1;
}
bool judge(int x){// <=x
	if(banpingmianjiao(a,num,x)) return 1;
	else return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&x[i],&y[i],&y2[i]);
	num++;
	a[num].v=Vector(0,1);
	a[num].ang=atan2((long double)a[num].v.y,(long double)a[num].v.x);		
	num++;
	a[num].p=Point(0,1e100);
	a[num].v=Vector(-1,0);
	a[num].ang=atan2((long double)a[num].v.y,(long double)a[num].v.x);
	num++;
	a[num].p=Point(-1e100,1e100);
	a[num].v=Vector(0,-1);
	a[num].ang=atan2((long double)a[num].v.y,(long double)a[num].v.x);
	num++;
	a[num].p=Point(-1e100,0);
	a[num].v=Vector(1,0);
	a[num].ang=atan2((long double)a[num].v.y,(long double)a[num].v.x);
	for(int i=1;i<=n;i++){
		num++;
		a[num].p=Point(0,y[i]/(double)x[i]);
		a[num].v=Vector(x[i],-x[i]*1.0*x[i]);
		a[num].id=i;
		a[num].ang=atan2((long double)a[num].v.y,(long double)a[num].v.x);
		num++;
		a[num].p=Point(0,y2[i]/(double)x[i]);
		a[num].v=Vector(-x[i],x[i]*1.0*x[i]);
		a[num].id=i;
		a[num].ang=atan2((long double)a[num].v.y,(long double)a[num].v.x);
	}
	sort(a+1,a+num+1);
	int l=1,r=n+1;
	while(r-l>1){
		int mid=(l+r)/2;
		if(judge(mid)) l=mid;
		else r=mid;
	}
	printf("%d\n",l);	
	return 0;
}
