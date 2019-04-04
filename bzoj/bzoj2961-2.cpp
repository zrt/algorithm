#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double ld;
const ld eps=1e-8;
int n;

struct Point{
	ld x,y;
	void read(){
		double xx,yy;
		scanf("%lf%lf",&xx,&yy);
		x=xx,y=yy;
	}
}o;

struct N{
	int t;
	Point p;
}a[550000];

bool no[550000];
Point up[550000],down[550000],p[550000];
ld upk[550000],downk[550000];
bool cmp(const Point&a,const Point&b){
	if(fabs(a.x-b.x)>eps) return a.x<b.x;
	return a.y<b.y;
}
int t1,t2;
bool judge(const Point &a,const Point &b,const Point &c){
	ld x1=a.x-b.x,y1=a.y-b.y;
	ld x2=c.x-b.x,y2=c.y-b.y;
	return x1*y2-x2*y1>=-eps;
}
ld sqr(ld x){
	return x*x;
}
ld dis(const Point&a,const Point &b){
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}
bool check(const Point&a,const Point&b){
	return dis(b,a)>dis(o,a);
}
void solve(int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	solve(l,mid),solve(mid+1,r);
	int t=0;
	for(int i=l;i<=mid;i++){
		if(a[i].t==0){
			p[t++]=a[i].p;
		}
	}
	bool ok=0;
	for(int i=mid+1;i<=r;i++){
		if(a[i].t==1){
			ok=1;break;
		}
	}
	if(!ok) return;
	sort(p,p+t,cmp);
	if(!t) return;
	t1=t2=0;
	for(int i=t-1;i>=0;i--){
		while(t1>1&&judge(up[t1-2],up[t1-1],p[i])) t1--;
		up[t1++]=p[i];
	}
	for(int i=0;i<t;i++){
		while(t2>1&&judge(down[t2-2],down[t2-1],p[i])) t2--;
		down[t2++]=p[i];
	}
	for(int i=0;i<t1-1;i++){
		upk[i]=(up[i+1].y-up[i].y)/(up[i+1].x-up[i].x);
	}
	for(int i=0;i<t2-1;i++){
		downk[i]=(down[i+1].y-down[i].y)/(down[i+1].x-down[i].x);
	}
	for(int i=mid+1;i<=r;i++){
		if(a[i].t==1&&!no[i]){
			ld nowk=-a[i].p.x/a[i].p.y;
			
			if(a[i].p.y>=0){
				//down
				int L=0,R=t2-1;
				while(R-L>1){
					int MID=(L+R)>>1;
					if(nowk>downk[MID]) L=MID;
					else R=MID;
				}
				// L and L+1
				if(check(down[L],a[i].p)) no[i]=1;
				if(L+1<t2&&check(down[L+1],a[i].p)) no[i]=1;
			}else{
				//up
				int L=0,R=t1-1;
				while(R-L>1){
					int MID=(L+R)>>1;
					if(nowk<upk[MID]) L=MID;else R=MID; 
				}
				//L and L+1
				if(check(up[L],a[i].p)) no[i]=1;
				if(L+1<t1&&check(up[L+1],a[i].p)) no[i]=1;
			}
		}
	}
	
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].t);
		a[i].p.read();
	}
	solve(1,n);
	bool ok=1;
	for(int i=1;i<=n;i++){
		if(a[i].t==1){
			if(no[i]||ok) puts("No");
			else puts("Yes");
		}else ok=0;
	}
	return 0;
}
