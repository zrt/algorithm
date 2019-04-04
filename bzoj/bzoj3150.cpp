#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
typedef long double ld;
ld p[105][105],a[105][105],x[105];
char s[105];
void Gauss(int n){
	for(int i=1;i<n;i++){
		ld mx=-1;int pos;
		for(int j=i;j<n;j++){
			if(fabs(a[j][i])>mx){
				pos=j;mx=fabs(a[j][i]);
			}
		}
		for(int j=i;j<=n;j++) swap(a[i][j],a[pos][j]);
		for(int j=i+1;j<n;j++){
			if(fabs(a[j][i])>1e-12){
				ld f=a[j][i]/a[i][i];
				for(int k=i;k<=n;k++) a[j][k]-=a[i][k]*f;
			}
		}
	}
	for(int i=n-1;i>0;i--){
		for(int j=i+1;j<n;j++){
			if(fabs(a[i][j])>1e-12){
				a[i][n]-=x[j]*a[i][j];
			}
		}
		x[i]=a[i][n]/a[i][i];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		double t;
		for(int j=1;j<=n;j++){
			scanf("%lf",&t);
			p[i][j]=t;
		}
	}
	for(int i=1;i<n;i++){//n+1 changshu
		a[i][i]=1;
		for(int j=1;j<=n;j++){
			if(i!=j){
				a[i][i]-=p[i][j]/(n-1);
				a[i][j]-=p[i][j]/(n-1);
			}
		}
	}
	for(int i=1;i<=n;i++) a[n][i]=1;
	a[n][n+1]=1;
	Gauss(n+1);
	for(int i=0;i<m;i++){
		ld ans=0;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			if(s[i]=='1') ans+=x[i];
		}
		printf("%.8f\n",(double)ans);
	}
	return 0;
}
