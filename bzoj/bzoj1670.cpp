#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int n;
struct point{
	int x,y;
	friend bool operator < (point a,point b){
		if(a.x!=b.x) return a.x<b.x;
		return a.y<b.y;
	}
	point(int a=0,int b=0){
		x=a,y=b;
	}
}p[5005];
typedef point Vector;
Vector operator - (point a,point b){
	return Vector(a.x-b.x,a.y-b.y);
}
LL cross(Vector a,Vector b){
	return a.x*1LL*b.y-a.y*1LL*b.x;
}
point stk[5005];
int top;
double dis(point a,point b){
	return sqrt((a.x-b.x)*1LL*(a.x-b.x)+(a.y-b.y)*1LL*(a.y-b.y));
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		while(top>1&&cross(stk[top-1]-stk[top-2],p[i]-stk[top-1])<0) top--;
		stk[top++]=p[i];
	}
	int k=top;
	for(int i=n-1;i>=1;i--){
		while(top>k&&cross(stk[top-1]-stk[top-2],p[i]-stk[top-1])<0) top--;
		stk[top++]=p[i];
	}
	double ans=0;
	for(int i=0;i<top;i++){
		ans+=dis(stk[i],stk[(i+1)%top]);
	}
	printf("%.2f\n",ans);
	return 0;
}
