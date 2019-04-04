#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct point{
	double x,y;
}p[305],r1,r2;
int n;
double dist(const point&a,const point&b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void print(point a){
	printf("%.3f %.3f\n",a.x,a.y);
}
int ans,tot;
point calc1(const point &a,const point &b){
	point r,p,q;
	p.x=b.x-a.x;
	p.y=b.y-a.y;
	double l=sqrt(p.x*p.x+p.y*p.y);
	p.x/=l;
	p.y/=l;
	q.x=-p.y;
	q.y=p.x;
	p.x=(b.x+a.x)/2;
	p.y=(b.y+a.y)/2;
	double k=sqrt(1-dist(a,b)/4);
	p.x=p.x+q.x*k;
	p.y=p.y+q.y*k;
	return p;
}
point calc2(const point &a,const point &b){
	point r,p,q;
	p.x=b.x-a.x;
	p.y=b.y-a.y;
	double l=sqrt(p.x*p.x+p.y*p.y);
	p.x/=l;
	p.y/=l;
	q.x=-p.y;
	q.y=p.x;
	p.x=(b.x+a.x)/2;
	p.y=(b.y+a.y)/2;
	double k=-sqrt(1-dist(a,b)/4);
	p.x=p.x+q.x*k;
	p.y=p.y+q.y*k;
	return p;
}
int main(){
	while(~scanf("%d",&n),n){
		ans=1;
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(dist(p[i],p[j])>4) continue;
				r1=calc1(p[i],p[j]);
				r2=calc2(p[i],p[j]);
				tot=0;
				for(int k=0;k<n;k++){
					if(dist(r1,p[k])<=1+1e-4) tot++;
				}
				ans=max(ans,tot);
				tot=0;
				for(int k=0;k<n;k++){
					if(dist(r2,p[k])<=1+1e-4) tot++;
				}
				ans=max(ans,tot);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}