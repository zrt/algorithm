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
#include<iostream>
#include<complex>
//by zrt
//problem:
using namespace std;
typedef long long ll;
int T;
typedef complex<double> Point;
typedef Point Vector;
double Dot(Vector A,Vector B){
	return real(conj(A)*B);
}
double Cross(Vector A,Vector B){
	return imag(conj(A)*B);
}
const double eps=1e-8;
int dcmp(double x){
	if(fabs(x)<eps) return 0;
	else if(x>0) return 1;
	else return -1;
}
double a1,b1,a2,b2,m1,n1,m2,n2;
Point A,B,M,N;
bool SegJ(){
	double c1=Cross(B-M,N-M),c2=Cross(A-M,N-M),
			c3=Cross(M-A,B-A),c4=Cross(N-A,B-A);
	if(dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0) return true;
	return false;
	
}
bool OnSeg(Point P,Point A,Point B){
	return dcmp(Cross(A-P,B-P))==0&&dcmp(Dot(A-P,B-P)<0);
}
bool operator == (Point A,Point B){
	return dcmp(real(A)-real(B))==0&&dcmp(imag(A)-imag(B))==0;
}
bool XJ(){
	if(SegJ()) return true;
	if(OnSeg(A,M,N)||OnSeg(B,M,N)||OnSeg(M,A,B)||OnSeg(N,A,B)||A==M||A==N||B==M||B==N) return true;
	return false;
}
Point J(){
	Vector v1=B-A,v2=N-M,u=A-M;
	double t=Cross(v2,u)/Cross(v1,v2);
	return A+t*v1;
}
Point xJ(Point A,Vector v1,Point M,Vector v2){
	Vector u=A-M;
	double t=Cross(v2,u)/Cross(v1,v2);
	return A+t*v1;
}
int main(){
	#ifdef LOCAL
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a1,&b1,&a2,&b2,&m1,&n1,&m2,&n2);
		A=Point(a1,b1);B=Point(a2,b2);M=Point(m1,n1);N=Point(m2,n2);
	//	cout<<M<<' '<<N<<' ';
		if(dcmp(b1-b2)==0||dcmp(n1-n2)==0) {
			puts("0.00");continue;
		}
		if(XJ()){
			Point p=J();
			int minx,miny=1e9;
			bool ok=1,isa=0;
			if(b1>imag(p)&&b1<miny) minx=a1,miny=b1,ok=0,isa=1;
			if(b2>imag(p)&&b2<miny) minx=a2,miny=b2,ok=0,isa=1;
			if(n1>imag(p)&&n1<miny) minx=m1,miny=n1,ok=0,isa=0;
			if(n2>imag(p)&&n2<miny) minx=m2,miny=n2,ok=0,isa=0;
			if(ok){
				puts("0.00");continue;
			}
			Point Low=Point(minx,miny);
			Vector v(1,0);
			//
		//	cout<<Low<<' ';
			if(isa){
				if(imag(M)>imag(N)){
					if(M==p){
						puts("0.00"); continue;
					}
				}else{
					if(N==p){
						puts("0.00");continue;
					}
				}
				Vector v(0,1);
			//	cout<<M<<' '<<N<<' ';
				if(dcmp(real(M)-real(N))==0) goto pppp;
				Point m=xJ(Low,v,N,M-N);
			//	cout<<m<<' '<<Low<<'\n'<<M<<' '<<N<<'\n';
				if(dcmp(imag(Low)-imag(m))>0) goto pppp;
			//	cout<<Low<<' '<<m;
		//		double _a=Cross(N-m,M-m),_b=dcmp(Dot(N-m,M-m));
				if(OnSeg(m,N,M)||m==M||m==N){
					puts("0.00");continue;
				}
			}else{
				if(imag(A)>imag(B)){
					if(A==p){
						puts("0.00"); continue;
					}
				}else{
					if(B==p){
						puts("0.00");continue;
					}
				}
				Vector v(0,1);
				Point m=xJ(Low,v,A,B-A);
				if(dcmp(real(A)-real(B))==0) goto pppp;
				if(dcmp(imag(Low)-imag(m))>0) goto pppp;
				if(OnSeg(m,A,B)||m==A||m==B){
					 puts("0.00");continue;
				}
			}
			//
			pppp:;
			Point a=xJ(Low,v,N,M-N);
			Point b=xJ(Low,v,A,B-A);
			printf("%.2f\n",fabs(Cross(b-a,p-a))/2+eps);
		}else{
			puts("0.00");continue;
		}
	}
	return 0;
}
