#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
struct point{
	int x,y;
	friend bool operator < (point x,point y){
		return x.x<y.x;
	}
}p[1005];
struct line{
	int x,y;double k;
	friend bool operator < (line a,line b){
		return a.k<b.k;
	}
}l[500005];
int pos[1005],rank[1005];
int n,c;
double ans;
point operator -(point a,point b){
	static point ret;
	ret.x=a.x-b.x;
	ret.y=a.y-b.y;
	return ret;
}
double cross(point a,point b){
	return a.x*1.0*b.y-b.x*1.0*a.y;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	ans=1e200;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++) rank[i]=pos[i]=i;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			l[++c].x=i;l[c].y=j;
			l[c].k=(p[j].y-p[i].y)/(double)(p[j].x-p[i].x);
		}
	}
	sort(l+1,l+c+1);
	int a,b;
	for(int i=1;i<=c;i++){
		a=l[i].x;b=l[i].y;
		if(pos[a]>pos[b]) swap(a,b);
		if(pos[a]>1)ans=min(ans,fabs(cross(p[a]-p[b],p[rank[pos[a]-1]]-p[b])));
		if(pos[b]<n)ans=min(ans,fabs(cross(p[a]-p[b],p[rank[pos[b]+1]]-p[b])));
		swap(pos[a],pos[b]);
		swap(rank[pos[a]],rank[pos[b]]);
	}
	printf("%.2f\n",ans/2.0);
	return 0;
}
