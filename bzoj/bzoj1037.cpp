#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k;
const int mod = 12345678;
int dp[155][155][25][25];//前i男j女 男减女最大k 女减男最大l 方案数
void MOD(int&a){
	if(a>=mod) a-=mod;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	dp[0][0][0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int a=0;a<=k;a++)
				for(int b=0;b<=k;b++){
					MOD(dp[i+1][j][a+1][max(b-1,0)]+=dp[i][j][a][b]);
					MOD(dp[i][j+1][max(a-1,0)][b+1]+=dp[i][j][a][b]);
				}
	long long ans=0;
	for(int i=0;i<=k;i++) for(int j=0;j<=k;j++) ans+=dp[n][m][i][j];
	printf("%lld\n",ans%mod);
	return 0;
}
