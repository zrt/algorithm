#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define double long double
struct Point{
	double x,y;
	Point(double a=0,double b=0){
		x=a,y=b;
	}
	void read(){
		#undef double
		double xx,yy;
		scanf("%lf%lf",&xx,&yy);
		x=xx,y=yy;
		#define double long double
	}
};
typedef Point Vector;
struct Tr{
	Point p[3];
	void read(){
		for(int i=0;i<3;i++) p[i].read();
	}
}a[105];
double p[100000];//x
int tot;
int n;
const double eps=1e-15;
Vector operator - (Point a,Point b){
	return Vector(a.x-b.x,a.y-b.y);
}
Vector operator * (Vector a,double t){
	return Vector(a.x*t,a.y*t);
}
Vector operator + (Vector a,Vector b){
	return Vector(a.x+b.x,a.y+b.y);
}
double Cross(Vector a,Vector b){
	return a.x*b.y-a.y*b.x;
}
Point Jiao(Point p,Vector v,Point q,Vector u){
	Vector a=p-q;
	double t=Cross(u,a)/Cross(v,u);
	return p+v*t;
}
void Get(Point x1,Point x2,Point y1,Point y2){
	if(x1.x>x2.x) swap(x1,x2);
	if(y1.x>y2.x) swap(y1,y2);
	Point t=Jiao(x1,x2-x1,y1,y2-y1);
	double a=Cross(y1-x1,x2-x1)*Cross(y2-x1,x2-x1);
	double b=Cross(x1-y1,y2-y1)*Cross(x2-y1,y2-y1);
	if(t.x>=x1.x&&t.x<=x2.x&&t.x>=y1.x&&t.x<=y2.x&&a<0&&b<0){
		p[tot++]=t.x;
	}
}
void Get(const Tr&a,const Tr&b){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			Get(a.p[i],a.p[(i+1)%3],b.p[j],b.p[(j+1)%3]);
		}
	}
}
bool equ(double a,double b){
	if(fabs(a-b)<eps) return 1;
	return 0;
}
double ans;
struct N{
	int type;
	double x;
	N(int a=0,double b=0){
		type=a,x=b;
	}
	friend bool operator < (const N&a,const N&b){
		return a.x<b.x;
	}
};
N list[100005];int t;

bool solve(Point x,Point y,double k,double&ans){
	if(x.x>y.x) swap(x,y);
	if(x.x>k) return 0;
	if(y.x<k) return 0;
	ans=x.y+(y.y-x.y)*(k-x.x)/(y.x-x.x);
	return 1;
}
void solve(Tr a,double x){
	double mn=1e200,mx=-1e200,tmp;
	bool ok=0;
	for(int i=0;i<3;i++){
		if(solve(a.p[i],a.p[(i+1)%3],x,tmp)){
			ok=1;
			mx=max(mx,tmp);
			mn=min(mn,tmp);
		}
	}
	
	if(ok){
		list[t++]=N(+1,mn);
		list[t++]=N(-1,mx);
	}
}
double Length(double x){
	t=0;
	for(int i=1;i<=n;i++){
		solve(a[i],x);
	}
	sort(list,list+t);
	double ret=0;
	int k=0;
	for(int i=0;i<t;i++){
		if(k) ret+=list[i].x;
		k+=list[i].type;
		if(k) ret-=list[i].x;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i].read();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			Get(a[i],a[j]);
		}
		for(int j=0;j<3;j++){
			p[tot++]=a[i].p[j].x;
		}
	}
	sort(p,p+tot);
	tot=unique(p,p+tot,equ)-p;
	for(int i=1;i<tot;i++){
		ans+=(p[i]-p[i-1])*Length((p[i]+p[i-1])/2);
	}
	#undef double
	printf("%.2f\n",(double)ans);
	return 0;
}
