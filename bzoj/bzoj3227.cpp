#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
int n;
int f[21][5005][2];// high num black|red max
int g[21][5005][2];//min
int mn,mx;
int main(){
	scanf("%d",&n);
	memset(f,235,sizeof f);
	memset(g,0x3f,sizeof g);
	mx=0x80808080;
	mn=0x3f3f3f3f;
	f[0][0][0]=0;f[0][1][1]=1;
	g[0][0][0]=0;g[0][1][1]=1;
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k*2+1<=j;k++){
				f[i][j][0]=max(f[i-1][k][0]+f[i-1][j-k-1][0],f[i][j][0]);
				f[i][j][0]=max(f[i-1][k][1]+f[i-1][j-k-1][0],f[i][j][0]);
				f[i][j][0]=max(f[i-1][k][0]+f[i-1][j-k-1][1],f[i][j][0]);
				f[i][j][0]=max(f[i-1][k][1]+f[i-1][j-k-1][1],f[i][j][0]);
				
				g[i][j][0]=min(g[i-1][k][0]+g[i-1][j-k-1][0],g[i][j][0]);
				g[i][j][0]=min(g[i-1][k][1]+g[i-1][j-k-1][0],g[i][j][0]);
				g[i][j][0]=min(g[i-1][k][0]+g[i-1][j-k-1][1],g[i][j][0]);
				g[i][j][0]=min(g[i-1][k][1]+g[i-1][j-k-1][1],g[i][j][0]);
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=0;k*2+1<=j;k++){
				f[i][j][1]=max(f[i][k][0]+f[i][j-k-1][0]+1,f[i][j][1]);
				g[i][j][1]=min(g[i][k][0]+g[i][j-k-1][0]+1,g[i][j][1]);
			}
		}
	}
	for(int i=0;i<=20;i++){
		mx=max(mx,max(f[i][n][0],f[i][n][1]));
		mn=min(mn,min(g[i][n][0],g[i][n][1]));
	}
	printf("%d\n%d\n",mn,mx);
	return 0;
}
