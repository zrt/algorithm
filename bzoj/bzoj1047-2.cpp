#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x3fffffff) ;
int a,b,n;
int s[1005][1005];
int maxx[1005][1005];
int minn[1005][1005];
struct N{
	int x,w;
}q[1005];
int h,t;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d%d",&a,&b,&n);
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			scanf("%d",&s[i][j]);
		}
	}
	//maxx hang
	for(int i=1;i<=a;i++){
		h=t=0;
		for(int j=1;j<=b;j++){
			while(h!=t&&q[t-1].w<=s[i][j]) t--;
			q[t].w=s[i][j];q[t].x=j;t++;
			while(h!=t&&q[h].x<=j-n) h++;
			maxx[i][j]=q[h].w;
		}
	}
	//minn hang
	for(int i=1;i<=a;i++){
		h=t=0;
		for(int j=1;j<=b;j++){
			while(h!=t&&q[t-1].w>=s[i][j]) t--;
			q[t].w=s[i][j];q[t].x=j;t++;
			while(h!=t&&q[h].x<=j-n) h++;
			minn[i][j]=q[h].w;
		}
	}
	
	//maxx square
	for(int j=1;j<=b;j++){
		h=t=0;
		for(int i=1;i<=a;i++){
			while(h!=t&&q[t-1].w<=maxx[i][j]) t--;
			q[t].w=maxx[i][j];q[t].x=i;t++;
			while(h!=t&&q[h].x<=i-n) h++;
			maxx[i][j]=q[h].w;
		}
	}
	//minn square
	for(int j=1;j<=b;j++){
		h=t=0;
		for(int i=1;i<=a;i++){
			while(h!=t&&q[t-1].w>=minn[i][j]) t--;
			q[t].w=minn[i][j];q[t].x=i;t++;
			while(h!=t&&q[h].x<=i-n) h++;
			minn[i][j]=q[h].w;
		}
	}
	int ans=inf;
	for(int i=n;i<=a;i++){
		for(int j=n;j<=b;j++){
			ans=min(ans,maxx[i][j]-minn[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0 ;
}
