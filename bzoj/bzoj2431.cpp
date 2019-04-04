//f[i][j]=Σf[i-1][j-k] 0<=k<=i-1
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=10000;
int f[1005][1005];
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	f[1][0]=1;
	for(int i=2;i<=n;i++){
		f[i][0]=1;
		for(int j=1;j<=i-1;j++){
			f[i][j]=(f[i][j-1]+f[i-1][j])%mod;
		}
		for(int j=i;j<=k;j++){
			f[i][j]=((f[i][j-1]+f[i-1][j]-f[i-1][j-i])%mod+mod)%mod;
		}
	}
	printf("%d\n",f[n][k]);
	return 0;
}
