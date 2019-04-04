#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int x[1005],y[1005];
double w[105];
int v0;
double rho;
double f[2][105][105];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lf",&w[i]);
	scanf("%d%lf",&v0,&rho);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	memset(f[0],0xc2,sizeof f[0]);
	for(int i=1;i<=n;i++) f[0][i][i]=0;
	for(int i=1;i<=m;i++) f[0][x[i]][y[i]]=w[y[i]];
	double t=rho;
	int p=0;
	for(int tt=0;tt<70;tt++){
		p^=1;
		memset(f[p],0xc2,sizeof f[p]);
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[p][i][j]=max(f[p][i][j],f[p^1][i][k]+f[p^1][k][j]*t);
				}
			}
		}
		t*=t;
	}
	double ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[p][v0][i]);
	printf("%.1f\n",ans*rho+w[v0]);
	return 0;
}
