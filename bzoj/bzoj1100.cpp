#include <cstdio>
#include <cstring>
#include <algorithm>
#include<cmath>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-5) ;
const int inf(0x7fffffff) ;
#define MAXN 100500
int tt;
int n;
int x[MAXN],y[MAXN];
int r[4*MAXN];
struct N{
	bool type;
	double a;
	int c;
	friend bool operator == ( N a,N b){
		return a.type==b.type&&fabs(a.a-b.a)<eps&&a.c+b.c!=0;
	}
};
N a[4*MAXN];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		int ans(0);
		for(int i=0;i<n;i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		for(int i=0;i<n;i++){// bian
			a[i<<1|1].type=1;
			a[i<<1|1].c=1;
			a[i<<1|1].a=(x[i]-x[(i+1)%n])*1LL*(x[i]-x[(i+1)%n])+(y[i]-y[(i+1)%n])*1LL*(y[i]-y[(i+1)%n]);
		}
		for(int i=0,x1,y1,x2,y2;i<n;i++){
			a[i<<1].type=0;
			x1=x[(i+1)%n]-x[i];
			y1=y[(i+1)%n]-y[i];
			x2=x[((i-1+n)%n)]-x[i];
			y2=y[((i-1+n)%n)]-y[i];
			long long sinp=x1*1LL*y2-x2*1LL*y1;
			if(sinp+eps>0) a[i<<1].c=1;
			else a[i<<1].c=-1; 
			a[i<<1].a=fabs(sinp)/sqrt(x1*1LL*x1+y1*1LL*y1)/sqrt(x2*1LL*x2+y2*1LL*y2);
		}
		int lim=2*n;
		for(int i=0;i<lim;i++){
			a[i+lim]=a[i];
		}
		lim<<=1;
		int mx(-1),id(-1);
		for(int i=0;i<lim;i++){
		//	printf("#%d %d %.3f\n",i,a[i].type,a[i].a);
			r[i]=0;
			if(i<mx){
				r[i]=min(mx-i,r[id-(i-id)]);
			}
			while(i+r[i]<lim&&i-r[i]>=0&&a[i+r[i]]==a[i-r[i]]) r[i]++;
			if(i+r[i]>mx){
				mx=i+r[i];
				id=i;
			}
			if((r[i]<<1)-1>n<<1){
				ans++;
			}
		}
		printf("%d\n",ans>>1);
	}
	return 0 ;
}
