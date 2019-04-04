#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int tt;
struct point{
	int x,y,z;
}p[200005],tmp[200005];
int n;
bool cmp(const point&a,const point&b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
bool cmp2(const point&a,const point&b){
	return a.y<b.y;
}
double solve(int l,int r){
	if(l==r) return 1e100;
	int mid=(l+r)/2;
	double ans=1e100;
	ans=min(solve(l,mid),solve(mid+1,r));
	int tot=0;
	for(int i=mid;i>=l;i--){
		if(p[mid].x-p[i].x<=ans) tmp[tot++]=p[i];
		else break;
	}
	for(int i=mid+1;i<=r;i++){
		if(p[i].x-p[mid+1].x<=ans) tmp[tot++]=p[i];
		else break;
	}
	sort(tmp,tmp+tot,cmp2);
	for(int i=0;i<tot;i++){
		for(int j=i+1;j<tot&&tmp[j].y-tmp[i].y<=ans;j++){
			if(tmp[i].z^tmp[j].z){
				ans=min(ans,sqrt((tmp[i].x-tmp[j].x)*1LL*(tmp[i].x-tmp[j].x)+(tmp[i].y-tmp[j].y)*1LL*(tmp[i].y-tmp[j].y)));
			}
		}
	}
	return ans;
}
int main(){
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
			p[i].z=0;
		}
		for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i+n].x,&p[i+n].y);
			p[i+n].z=1;
		}
		sort(p+1,p+2*n+1,cmp);
		printf("%.3f\n",solve(1,2*n));
	}
	return 0;
}