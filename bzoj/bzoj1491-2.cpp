#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int d[105][105];
long long g[105][105];
double ans[105];
int n,m;
int main(){
	memset(d,0x3f,sizeof d);
	scanf("%d%d",&n,&m);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		d[x][y]=d[y][x]=z;
		g[x][y]=g[y][x]=1;
	}
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					g[i][j]=g[i][k]*g[k][j];
				}else if(d[i][j]==d[i][k]+d[k][j]){
					g[i][j]+=g[i][k]*g[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int s=1;s<=n;s++){
			if(s==i) continue;
			for(int t=1;t<=n;t++){
				if(t==i) continue;
				if(d[s][i]+d[i][t]==d[s][t]){
					ans[i]+=g[s][i]*g[i][t]/(double)g[s][t];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%.3f\n",ans[i]);
	}
	return 0;
}
