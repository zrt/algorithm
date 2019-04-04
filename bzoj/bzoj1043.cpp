#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
//by zrt
//problem:
using namespace std;
int n,cc;
struct N{
	double r,x,y;
}a[1005];
struct A{
	double l,r;
	A(double a=0,double b=0){
		l=a,r=b;
	}
}Q[4006000];
const double eps= 1e-10;

/*

void calc(int x,int y){
	double yuanxinju=sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y));
	if(a[x].r+a[y].r<yuanxinju+eps) return ;// 相离
	if(abs(a[x].r-a[y].r)>=yuanxinju-eps) {
		if(a[x].r<a[y].r)Q[cc++]=A(-3.14159265358,3.14159265358);
		return;
	}
	
	double p=(a[x].r*a[x].r-a[y].r*a[y].r+yuanxinju*yuanxinju)/(2.0*yuanxinju);
	double px=a[y].x-a[x].x,py=a[y].y-a[x].y;
	double qx,qy;
	qx=-py;
	qy=px;
	
	px=px*p/yuanxinju;
	py=py*p/yuanxinju;
	double q=sqrt(a[x].r*a[x].r-p*p);
	
	qx=qx*q/yuanxinju;
	qy=qy*q/yuanxinju;
	double L,R;
	L=atan2(py-qy,px-qx);
	R=atan2(py+qy,px+qx);
	if(L<=R){
		Q[cc++]=A(L,R);
	}else{
		Q[cc++]=A(L,3.14159265358);
		Q[cc++]=A(-3.14159265358,R);
	}
}

*/

void calc(int x,int y){
	double yuanxinju=sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y));
	if(a[x].r+a[y].r<yuanxinju+eps) return ;// 相离
	if(abs(a[x].r-a[y].r)>=yuanxinju-eps) {
		if(a[x].r<a[y].r)Q[cc++]=A(-3.14159265358,3.14159265358);
		return;
	}
	double angle=atan2(a[y].y-a[x].y,a[y].x-a[x].x);
	// c^2=a^2+b^2-2*a*b*cosc
	double cosc=((a[x].r*a[x].r)+yuanxinju*yuanxinju-a[y].r*a[y].r)/(2*a[x].r*yuanxinju);
	double delta=acos(cosc);
	double L,R;
	L=angle-delta;
	R=angle+delta;
	if(L<-3.14159265358){
		Q[cc++]=A(L+3.14159265358*2,3.14159265358);
		L=-3.14159265358;
	}
	if(R>3.14159265358){
		Q[cc++]=A(-3.14159265358,R-3.14159265358*2);
		R=3.14159265358;
	}
	Q[cc++]=A(L,R);
}
bool cmp(A x,A y){
	return x.l<y.l;
}
int main(){
//	freopen("disc.in","r",stdin);
//	freopen("disc.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&a[i].r,&a[i].x,&a[i].y);
	}
	double ans=0;
	for(int i=n;i>=1;i--){
		cc=0;
		for(int j=i+1;j<=n;j++){
			calc(i,j);
		}
		double k=0;
		sort(Q,Q+cc,cmp);
		double pos=-10;
		for(int j=0;j<cc;j++){
			pos=max(pos,Q[j].l);
			if(pos>=Q[j].r) continue;
			k+=Q[j].r-pos;
			pos=Q[j].r;
		}
		ans+=2*3.14159265358*a[i].r-k*a[i].r;
	}
	printf("%.3f\n",ans);
	return 0;
}
