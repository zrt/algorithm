/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
double a[15][15];
double sigma[15];
int n;
double d[15][15];
double inf=1e100;
double ans[15];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		for(int j=0;j<n;j++){
			scanf("%lf",&a[i][j]);
			sigma[i]+=(a[i][j])*(a[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d[i][j]=2*(a[i][j]-a[i+1][j]);
		}
		d[i][n]=sigma[i]-sigma[i+1];
	}
	for(int i=0;i<n;i++){
		int maxx;double maxn=-1;
		for(int j=i;j<n;j++){
			if(fabs(d[j][i])>maxn) maxn=fabs(d[j][i]),maxx=j;
		}
		for(int j=i;j<=n;j++) swap(d[i][j],d[maxx][j]);
		double f;
		for(int j=i+1;j<n;j++){
			f=d[j][i]/d[i][i];
			for(int k=i;k<=n;k++){
				d[j][k]-=d[i][k]*f;
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>i;j--){
			d[i][n]-=d[i][j]*ans[j];
		}
		ans[i]=d[i][n]/d[i][i];
	}
	printf("%.3f",ans[0]);
	for(int i=1;i<n;i++){
		printf(" %.3f",ans[i]);
	}
	return 0;
}
