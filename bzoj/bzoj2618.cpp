#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int dcmp(double x){
	if(fabs(x)<eps) return 0;
	if(x>0) return 1;else return -1;
}
struct point{
	double x,y;
	point (double a=0,double b=0){
		x=a,y=b;
	}
};
typedef point Vector;
struct line{
	point p;
	Vector v;
	double ang;
	line(){}
	line(point P,Vector V){
		p=P;v=V;
		ang=atan2(V.y,V.x);
	}
	friend bool operator < (line a,line b){
		return a.ang<b.ang;
	}
};
point tmp[55];
line lines[550];
int n,m,tot;
line q[1500];int h,t;
point p[1500];
double Cross(point a,point b){
	return a.x*b.y-a.y*b.x;
}
Vector operator - (point a,point b){
	return Vector(a.x-b.x,a.y-b.y);
}
point operator + (point a,Vector b){
	return point(a.x+b.x,a.y+b.y);
}
Vector operator * (Vector a,double k){
	return Vector(a.x*k,a.y*k);
}
point Jiao(line a,line b){
	Vector c=b.p-a.p;
	return b.p+b.v*(Cross(c,a.v)/Cross(a.v,b.v));
}
bool OnLeft(point p,line l){
	return Cross(l.v,p-l.p)>0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%lf%lf",&tmp[i].x,&tmp[i].y);
		}
		for(int i=0;i<m;i++){
			lines[++tot]=line(tmp[i],tmp[(i+1)%m]-tmp[i]);
		}
	}
	sort(lines+1,lines+tot+1);
	q[0]=lines[1];
	for(int i=2;i<=tot;i++){
		while(h<t&&!OnLeft(p[t-1],lines[i])) --t;
		while(h<t&&!OnLeft(p[h],lines[i])) ++h;
		q[++t]=lines[i];
		if(fabs(Cross(q[t].v,q[t-1].v))<eps){
			t--;
			if(OnLeft(lines[i].p,q[t])) q[t]=lines[i]; 
		}
		if(h<t) p[t-1]=Jiao(q[t-1],q[t]);
	}
	while(h<t&&!OnLeft(p[t-1],q[h])) t--;
	p[t]=Jiao(q[t],q[h]);
	double ans=0;
	if(t-h<=1) {
		puts("0.000");
		goto ed;
	}
	for(int i=h;i<t;i++){
		ans+=Cross(p[i],p[i+1]);
	}
	ans+=Cross(p[t],p[h]);
	printf("%.3f\n",fabs(ans)/2.0);
	ed:return 0;
}
