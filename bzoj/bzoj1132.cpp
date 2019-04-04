#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
struct N{
	int x,y;
}a[3005],b[3005];
bool cmp(const N &a,const N &b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
bool cmp2(const N&a,const N&b){
	return a.x*b.y-a.y*b.x<0;
}
int n;
LL ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<n;i++){
		sort(a+i,a+n+1,cmp);
		for(int j=i+1;j<=n;j++){
			a[j].x-=a[i].x;
			a[j].y-=a[i].y;
		}
		sort(a+i+1,a+n+1,cmp2);
		LL sumx(0),sumy(0);
		for(int j=i+1;j<=n;j++){
			ans+=a[j].x*sumy-a[j].y*sumx;
			sumx+=a[j].x;
			sumy+=a[j].y;
		}
	}
	ans=abs(ans);
	if(ans%2){
		printf("%lld.5\n",ans/2);
	}else{
		printf("%lld.0\n",ans/2);
	}
//	while(1);
	return 0;
}
