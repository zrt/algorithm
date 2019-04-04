#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps(1e-10);

struct point{
	double x,y;
	friend bool operator < (const point&a,const point&b){
		if(fabs(a.x-b.x)>eps) return a.x<b.x;
		return a.y<b.y;
	}
}a[2005];

int n;
point stk[2005];
int top;

bool judge( point a,point b,point c ){
	return (a.x-b.x)*(c.y-b.y)-(a.y-b.y)*(c.x-b.x)<eps;
}

double Area(point a,point b,point c){
	return fabs((a.x-b.x)*(c.y-b.y)-(a.y-b.y)*(c.x-b.x))/2;
}

int main(){
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		while(top>1&&judge(stk[top-2],stk[top-1],a[i])) top--;
		stk[top++]=a[i];
	}
	int k=top;
	for(int i=n-2;i>=0;i--){
		while(top>k&&judge(stk[top-2],stk[top-1],a[i])) top--;
		stk[top++]=a[i];
	}
	top--;
//	printf("%d\n",top);
	int p,q;
	n=top;
	double ans=0;
	for(int i=0;i<top;i++){
		p=i;q=(i+2)%top;
		for(int j=(i+2)%top;(j+1)%n!=i;j=(j+1)%n){
			
			if(i==p) p=(p+1)%top;
			if(j==q) q=(q+1)%top;
			while((p+1)%n!=j&&Area(stk[i],stk[j],stk[p+1])>Area(stk[i],stk[j],stk[p])) p=(p+1)%top;
			while((q+1)%n!=i&&Area(stk[i],stk[j],stk[q+1])>Area(stk[i],stk[j],stk[q])) q=(q+1)%top;
			ans=max(ans,Area(stk[i],stk[j],stk[p])+Area(stk[i],stk[j],stk[q]));
		}
	}
	printf("%.3f\n",ans);
	return 0;
}
