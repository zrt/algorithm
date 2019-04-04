#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=500;
const double eps = 1e-8;
int n,m,s,t;
int N;
double a[MAXN][MAXN],p[MAXN][MAXN];
int d[MAXN],g[MAXN][MAXN];
void Gauss(int n){
	for(int k=0;k<n;k++){
		int p=k;
		while(p<n&&fabs(a[p][k])<eps) p++ ;
		if(p==n) continue;
		if(p!=k)
			for(int i=0;i<=n;i++) swap(a[p][i],a[k][i]);
		double tmp=a[k][k];
		for(int i=0;i<=n;i++) a[k][i]/=tmp;
		for(int i=0;i<n;i++)
			if(i!=k) {
				double t=a[i][k];
				for(int j=0;j<=n;j++) a[i][j]-=t*a[k][j];
			}
	}
	
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);s--,t--;
	for(int i=0,x,y;i<m;i++) scanf("%d%d",&x,&y),x--,y--,d[x]++,d[y]++,g[x][y]=g[y][x]=1;
	for(int i=0;i<n;i++){
		scanf("%lf",&p[i][i]);
		for(int j=0;j<n;j++) if(g[j][i]) p[i][j]=(1-p[i][i])/d[i];
	}
	N=n*n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			a[i*n+j][i*n+j]=-1;
			if(i!=j){
				for(int k=0;k<n;k++){
					for(int l=0;l<n;l++)
						a[k*n+l][i*n+j]+=p[i][k]*p[j][l];
				}
			}
		}
	a[s*n+t][N]=-1;
	Gauss(N);
	for(int i=0;i<n;i++) printf ("%.10f ",a[i*n+i][N]);
	return 0;
}