#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
typedef long double ld;
int f[105][105][15];
int a[105][3];
int sum[105][3];
int n,m,K;
#undef int
int main(){
	#define int long long
	scanf("%lld%lld%lld",&n,&m,&K);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++) a[i][2]=-5276700;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			sum[i][j]=sum[i-1][j]+a[i][j];
		}
	}
	memset(f,128,sizeof f);
	f[0][0][0]=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			f[i][j][0]=0;
			for(int k=1;k<=K;k++){
				if(i>0)f[i][j][k]=max(f[i-1][j][k],f[i][j][k]);
				if(j>0)f[i][j][k]=max(f[i][j-1][k],f[i][j][k]);
			}
			//lianglie
			for(int k=1;k<=K;k++){
				for(int l=1;l<=i;l++){
					f[i][j][k]=max(f[i][j][k],f[i-l][j][k-1]+sum[i][1]-sum[i-l][1]);
				}
				for(int l=1;l<=j;l++){
					f[i][j][k]=max(f[i][j][k],f[i][j-l][k-1]+sum[j][2]-sum[j-l][2]);
				}
				if(i==j){
					for(int l=1;l<=i;l++){
						f[i][j][k]=max(f[i][j][k],f[i-l][j-l][k-1]+sum[i][1]-sum[i-l][1]+sum[j][2]-sum[j-l][2]);
					}
				}
			}
		}
	}
	//printf("%d %d %d\n",f[2][0][1],f[2][3][2],f[0][3][1]);
	printf("%lld\n",f[n][n][K]);
	return 0;
}
