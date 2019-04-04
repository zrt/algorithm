#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int tt;
int n;
long long V;
struct N{
	double S,h,b;
	friend bool operator < (N a,N b){
		return a.h+a.b<b.h+b.b;
	}
}a[50005];
long long sumv;
bool judge(double x){
	N tmp;
	tmp.h=x;
	tmp.b=0;
	int pos=lower_bound(a,a+n,tmp)-a;
	double v=0;
	for(int i=pos;i<n;i++){
		if(x<a[i].b) continue;
		else v+=min(x-a[i].b,a[i].h)*a[i].S;
	}
	for(int i=0;i<pos;i++){
		v+=a[i].h*a[i].S;
	}
	if(v>=V)return 1;
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		sumv=0;
		long long b,h,w,d;
		for(int i=0;i<n;i++){
			scanf("%lld%lld%lld%lld",&b,&h,&w,&d);
			a[i].S=w*d;
			a[i].b=b;
			a[i].h=h;
			sumv+=a[i].S*a[i].h;
		}
		scanf("%lld",&V);
		if(sumv<V){
			puts("OVERFLOW");
			continue;
		}
		
		sort(a,a+n);
		double l,r;
		l=0,r=1100000;
		for(int t=0;t<33;t++){
			double mid=(l+r)/2.0;
			if(judge(mid)){//>=
				r=mid;
			}else l=mid;
		}
		printf("%.2f\n",r);
	}
	
	return 0;
}
