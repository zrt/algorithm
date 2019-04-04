/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<complex>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
typedef complex<double> Point;
typedef Point Vector;
Point P[10005];
int n;
Point read_point(){
	double x,y;
	scanf("%lf%lf",&x,&y);
	return Point(x,y);
}
bool cmp(Point A,Point B){
	if(real(A)!=real(B)) return real(A)<real(B);
	else return imag(A)<imag(B);
}
double Cross(Vector A,Vector B){
	return imag(conj(A)*B);
}
int stk[10005],top;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		P[i]=read_point();
	}
	sort(P,P+n,cmp);
	for(int i=0;i<n;i++){
		while(top>1&&Cross(P[stk[top-1]]-P[stk[top-2]],P[i]-P[stk[top-1]])<0) top--;
		stk[top++]=i;
	}
	int k=top;
	for(int i=n-2;i>=0;i--){
		while(top>k&&Cross(P[stk[top-1]]-P[stk[top-2]],P[i]-P[stk[top-1]])<0) top--;
		stk[top++]=i;
	}
	if(n>1) top--;
	double area=0;
	for(int i=2;i<top;i++){
		area+=Cross(P[stk[i]]-P[stk[i-1]],P[stk[i-1]]-P[stk[0]]);
	}
	area=-area/2;
	printf("%d",(int)(area/50));
	return 0;
}
