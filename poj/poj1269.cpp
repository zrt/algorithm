/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<complex>
//by zrt
//problem:
using namespace std;
typedef long long ll;
typedef complex<double> Point;
typedef Point Vector;
double Dot(Vector A,Vector B){
	return real(conj(A)*B);
}
double Cross(Vector A,Vector B){
	return imag(conj(A)*B);
}
const double eps=1e-10;
int dcmp(double x){
	if(fabs(x)<eps) return 0;
	else if(x>0) return 1;
	else return -1;
}
int T;
double x,y,xx,yy,a,b,aa,bb;
bool judge0(){
	Vector v1=Point(xx,yy)-Point(x,y),v2=Point(a,b)-Point(x,y),v3=Point(aa,bb)-Point(x,y);
	if(dcmp(Cross(v1,v2))==0&&dcmp(Cross(v1,v3))==0) return true;
	else return false;
}
bool judge1(){
	if(dcmp((yy-y)*(aa-a)-(bb-b)*(xx-x))==0) return true;
	else return false;
}
Point J(){
	Point p1=Point(x,y),p2=Point(a,b);
	Vector v1=Point(xx,yy)-p1,v2=Point(aa,bb)-p2;
	Vector u=p1-p2;
	double t=Cross(v2,u)/Cross(v1,v2);
	return p1+t*v1;
}
void solve(){
	if(judge0()) puts("LINE");
	else if(judge1()) puts("NONE");
	else {
		Point ans=J();
		printf("POINT %.2f %.2f\n",real(ans),imag(ans));
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	puts("INTERSECTING LINES OUTPUT");
	while(T--){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x,&y,&xx,&yy,&a,&b,&aa,&bb);
		solve();
	}
	puts("END OF OUTPUT");
	return 0;
}
