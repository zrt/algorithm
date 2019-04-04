#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int f[105][105];
long long g[105][105];
double I[105];
int main(){
	memset(f,0x3f,sizeof f);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		f[x][y]=f[y][x]=z;
		g[x][y]=g[y][x]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]+f[j][k]<f[i][j]){
					f[i][j]=f[i][k]+f[k][j];
					g[i][j]=g[i][k]*g[k][j];
				}else if(f[i][k]+f[j][k]==f[i][j]){
					g[i][j]+=g[i][k]*g[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int k=1;k<=n;k++){
				if(i==k) continue;
				if(f[j][i]+f[i][k]==f[j][k]){
					I[i]+=g[j][i]*g[i][k]/(double)(g[j][k]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%.3f\n",I[i]);
	return 0;
}
