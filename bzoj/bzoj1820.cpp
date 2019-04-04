#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int d[205][205];
int f[2][205][205];
int m=0;
int a[1005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&d[i][j]);
		}
	}
	//f i j k j<=k
	a[0]=3;
	m=1;
	while(~scanf("%d",&a[m])) m++;m--;
	memset(f,0x3f,sizeof f);
	f[0][1][2]=0;
	for(int i=1;i<=m;i++){
		memset(f[i&1],0x3f,sizeof f[i&1]);
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				f[i&1][j][k]=min(f[i&1][j][k],f[(i&1)^1][j][k]+d[a[i-1]][a[i]]);
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(a[i-1]<=k)f[i&1][a[i-1]][k]=min(f[i&1][a[i-1]][k],f[(i&1)^1][j][k]+d[j][a[i]]);
				else f[i&1][k][a[i-1]]=min(f[i&1][k][a[i-1]],f[(i&1)^1][j][k]+d[j][a[i]]);
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(a[i-1]<=j)f[i&1][a[i-1]][j]=min(f[i&1][a[i-1]][j],f[(i&1)^1][j][k]+d[k][a[i]]);
				else f[i&1][j][a[i-1]]=min(f[i&1][j][a[i-1]],f[(i&1)^1][j][k]+d[k][a[i]]);
			}
		}
	}
	int ans=0x7fffffff;
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) ans=min(ans,f[m&1][i][j]);
	printf("%d\n",ans);
	return 0;
}
