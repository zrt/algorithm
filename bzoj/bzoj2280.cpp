#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef double ld;
int n,m;
struct Point{
	ld x,y;
	void read(){
		double a,b;
		scanf("%lf%lf",&a,&b);
		x=a,y=b;
	}
}a[100005],p[100005],o,ans[100005];
ld R;
int Ans;
const ld eps=1e-10;
ld dist(Point x,Point y){
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
ld sqr(ld x){
	return x*x;
}

Point geto(Point a,Point b,Point c){
	ld A=a.x*a.x-b.x*b.x+a.y*a.y-b.y*b.y;
	ld B=c.x*c.x-b.x*b.x+c.y*c.y-b.y*b.y;
	Point ret;
	ret.x=(A*(c.y-b.y)-B*(a.y-b.y))/((b.x-c.x)*(a.y-b.y)-(b.x-a.x)*(c.y-b.y))/2;
	ret.y=(A*(c.x-b.x)-B*(a.x-b.x))/((b.y-c.y)*(a.x-b.x)-(b.y-a.y)*(c.x-b.x))/2;
	return ret;
}


void calc(int n){
	random_shuffle(p+1,p+n+1);
	o=p[1];R=0;
//	printf("# %d\n",n);
	long long tot=0;
	for(int i=1;i<=n;i++){
		if(dist(o,p[i])<=R+eps) continue;
		o.x=(p[1].x+p[i].x)/2,o.y=(p[1].y+p[i].y)/2,R=dist(o,p[i]);
		for(int j=2;j<i;j++){
			if(dist(o,p[j])<=R+eps) continue;
			o.x=(p[j].x+p[i].x)/2,o.y=(p[j].y+p[i].y)/2,R=dist(p[i],p[j])/2;
			for(int k=1;k<j;k++){
				tot++;
				if(dist(p[k],o)<=R+eps) continue;
				o=geto(p[i],p[j],p[k]);
				R=dist(p[i],o);
			}
		}
	}
//	printf("%lld\n",tot);
}
bool Judge(int l,int r,ld mx){
	for(int i=l;i<=r;i++) p[i-l+1]=a[i];
	calc(r-l+1);
	//printf("%.2f\n",R);
	if(R<=mx) return 1;
	else return 0;
}
bool print;
bool judge(ld x){
	int now=1;
	int cnt=0;
//	printf("%.2f\n",x);
	while(now<=n){
		//printf("%d\n",now);
		int lg=0;
		for(;now+(1<<lg)-1<=n&&Judge(now,now+(1<<lg)-1,x);lg++);lg--;
	//	printf("%d\n",lg);
		int l=now+(1<<lg)-1,r=min(now+(1<<(lg+1)),n+1);
		while(r-l>1){
			int mid=(l+r)/2;
			if(Judge(now,mid,x)) l=mid;
			else r=mid;
		}
		if(print){
			Judge(now,l,x);
			ans[Ans++]=o;
		}
		cnt++;
		now=l+1;
		if(cnt>m){
			return 0;
		}
	}
//	printf("%d\n",cnt);
	return 1;
}
int main(){
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	srand(401794301);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) a[i].read();
	ld l=0,r=4000000;
	for(int i=0;i<=50;i++){
		ld mid=(l+r)/2;
	//	printf("%d %.10f\n",i,mid);
		if(judge(mid)) r=mid;
		else l=mid;
	}
	printf("%.10f\n",(double)r);
	print=1;
	judge(r+1e-10);
	printf("%d\n",Ans);
	for(int i=0;i<Ans;i++){
		printf("%.10f %.10f\n",(double)ans[i].x,(double)ans[i].y);
	}
	return 0;
}
