#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct N{
	double x,y,z;
}a[200005];
int n;
bool cmp(N a,N b){
	return a.z<b.z;
}
double sx,sy;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);
		a[i].z=atan2(a[i].y,a[i].x);
	}
	sort(a,a+n,cmp);
	int tot=0;
	for(int i=1;i<n;i++){
		if(fabs(a[i].z-a[tot].z)<=1e-8){
			a[tot].x+=a[i].x;
			a[tot].y+=a[i].y;
		}else{
			a[++tot]=a[i];
		}
	}
	n=tot+1;
	int j=0;
	double ans=0;
	for(int i=0;i<n;i++){
		if(i==j){
			sx+=a[j].x;
			sy+=a[j].y;
			j=(j+1)%n;
		}
		while(i!=j&&(sx+a[j].x)*(sx+a[j].x)+(sy+a[j].y)*(sy+a[j].y)>=sx*sx+sy*sy){
			sx+=a[j].x;
			sy+=a[j].y;
			j=(j+1)%n;
		}
		ans=max(ans,sx*sx+sy*sy);
		sx-=a[i].x;
		sy-=a[i].y;
	}
	printf("%.3f\n",ans);
	//终于明白了！
//	while(1);
	return 0;
}
