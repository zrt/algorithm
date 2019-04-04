#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
//by zrt

using namespace std;
typedef long long LL;
double eps=1e-12;
struct Point{
	double x,y;
	Point(double xx=0,double yy=0){
		x=xx;y=yy;
	}
}dian[1000];
typedef Point Vector;
double Cross(Vector A,Vector B){
	return A.x*B.y-A.y*B.x;
}
struct Line{
	Point P;Vector v;
	double ang;
	Line(){}
	Line(Point Px,Vector vx){
		P=Px;v=vx;ang=atan2(v.y,v.x);
	}
	friend bool operator < (Line A,Line B){
		return A.ang<B.ang;
	}
}L[350];
Vector operator - (Point A,Point B){
	return Vector(A.x-B.x,A.y-B.y);
}
Vector operator * (Vector A,double t){
	return Vector(A.x*t,A.y*t);
}
Vector operator + (Vector A,Vector B){
	return Vector(A.x+B.x,A.y+B.y);
}
bool OnLeft(Line L,Point p){
	return Cross(L.v,p-L.P)>0;
}
Point GetIntersection(Line a,Line b){
	Vector u=a.P-b.P;
	double t=Cross(b.v,u)/Cross(a.v,b.v);
	return a.P+a.v*t;
}
int banpingmianjiao(Line*L,int n,Point*poly){
	sort(L,L+n);
	int h,t;
	Point*p=new Point[n];
	Line*q=new Line[n];
	q[h=t=0]=L[0];
	for(int i=1;i<n;i++){
		while(h<t&&!OnLeft(L[i],p[t-1])) t--;
		while(h<t&&!OnLeft(L[i],p[h])) h++;
		q[++t]=L[i];
		if(fabs(Cross(q[t].v,q[t-1].v))<eps){
			t--;
			if(OnLeft(q[t],L[i].P)) q[t]=L[i];
		}
		if(h<t) p[t-1]=GetIntersection(q[t],q[t-1]);
	} 
	while(h<t&&!OnLeft(q[h],p[t-1])) t--;
	if(t-h<=1) return 0;
	p[t]=GetIntersection(q[t],q[h]);
	int m=0;
	for(int i=h;i<=t;i++) poly[m++]=p[i];
	return m;
}
int n,m;
char s[10];
int tot;
int check(Line l){
	int tot1=0;
	int tot2=0;
	for(int i=0;i<tot;i++){
		if(OnLeft(l,dian[i])) tot1++;
		else tot2++;
		if(tot1&&tot2) return 0;
		if(fabs(Cross(l.v,dian[i]-l.P))<eps) return 0;
	}
	if(tot1) return 1;
	else return -1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	L[tot++]=Line(Point(0.01,0),Vector(0,-1));
	L[tot++]=Line(Point(100,0),Vector(0,1));
	L[tot++]=Line(Point(0,0.01),Vector(1,0));
	L[tot++]=Line(Point(0,100),Vector(-1,0));
	L[tot++]=Line(Point(0,0),Vector(-1,-100));
	L[tot++]=Line(Point(0,0),Vector(100,1));
	Point up(0,1e20);
	for(int i=0;i<n;i++){
		double j1,j2,j3,b1,b2,b3;
		scanf("%s%lf%lf%lf%lf%lf%lf",s,&j1,&j2,&j3,&b1,&b2,&b3);
		double a=j1-b1,b=j2-b2,c=j3-b3;
		if(s[0]=='B') a=-a,b=-b,c=-c;
		if(fabs(a)<eps&&fabs(b)<eps) continue;
		if(fabs(a)<eps){
			if(b>0){
				L[tot++]=Line(Point(0,-c/b),Vector(1,0));
			}else L[tot++]=Line(Point(0,-c/b),Vector(-1,0));
			continue;
		}
		if(fabs(b)<eps){
			if(a>0){
				L[tot++]=Line(Point(-c/a,0),Vector(0,-1));
			}else L[tot++]=Line(Point(-c/a,0),Vector(0,1));
			continue;
		}
		if(b*up.y+c>0){//shangmian
			L[tot++]=Line(Point(0,-c/b),Point(1,(-c-a)/b)-Point(0,-c/b));
		}else{//xiamian
			L[tot++]=Line(Point(0,-c/b),Point(0,-c/b)-Point(1,(-c-a)/b));
		}
	}
	tot=banpingmianjiao(L,tot,dian);
	for(int i=0;i<m;i++){
		double j1,j2,j3,b1,b2,b3;
		scanf("%lf%lf%lf%lf%lf%lf",&j1,&j2,&j3,&b1,&b2,&b3);
		double a=j1-b1,b=j2-b2,c=j3-b3;
		if(fabs(a)<eps&&fabs(b)<eps){
			if(fabs(c)<eps){
				puts("U");
			}else if(c>0) puts("J");
			else puts("B");
			continue;
		}
		int k;
		if(fabs(a)<eps){
			if(b>0){
				k=check(Line(Point(0,-c/b),Vector(1,0)));
			}else k=check(Line(Point(0,-c/b),Vector(-1,0)));
			if(k==1){
				puts("J");
			}else if(k==0){
				puts("U");
			}else puts("B");
			continue;
		}
		if(fabs(b)<eps){
			if(a>0){
				k=check(Line(Point(-c/a,0),Vector(0,-1)));
			}else k=check(Line(Point(-c/a,0),Vector(0,1)));
			if(k==1){
				puts("J");
			}else if(k==0){
				puts("U");
			}else puts("B");
			continue;
		}
		if(b*up.y+c>0){//shangmian
			k=check(Line(Point(0,-c/b),Point(1,(-c-a)/b)-Point(0,-c/b)));
		}else{//xiamian
			k=check(Line(Point(0,-c/b),Point(0,-c/b)-Point(1,(-c-a)/b)));
		}
		if(k==1){
			puts("J");
		}else if(k==0){
			puts("U");
		}else puts("B");
	}
	return 0;
}
