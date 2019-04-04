#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
double f[55][55];
const double eps=1e-10;
double tmp=1;
void solve(){
	for(int i=1;i<n;i++){
		double tmp=0;
		int pos=0;
		for(int j=i;j<n;j++){
			if(fabs(f[j][i])>tmp){
				tmp=fabs(f[j][i]);
				pos=j;
			}
		}
		if(!pos) return;
		for(int j=i;j<n;j++) swap(f[pos][j],f[i][j]);
		if(fabs(f[i][i])<eps) return;
		for(int j=i+1;j<n;j++){
			if(fabs(f[j][i])<eps) continue;
			double F=f[j][i]/f[i][i];
			for(int k=i;k<n;k++) f[j][k]-=F*f[i][k];
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lf",&f[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]>1-eps) f[i][j]-=eps;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++) tmp*=1-f[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=f[i][j]/(1-f[i][j]);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) f[i][i]-=f[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
//			printf("%.3f ",f[i][j]);
		}
//		puts("");
	}
	solve();
	double ans=1;
	for(int i=1;i<n;i++){
		ans*=f[i][i];
	}
//	printf("%.10f\n",tmp);
	printf("%.10f\n",fabs(ans)*tmp);
	return 0;
}
/*
	3
	0 0.1 0.99
	0.1 0 0.3
	0.99 0.3 0

-0.540 0.111 0.429 
0.111 -0.111 0.000 
0.429 0.000 -0.429 
0.0300000000



*/
