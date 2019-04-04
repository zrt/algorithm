#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int f,v;
int a[105][105];
int dp[105][105];// 前i个花瓶，第j个花在第i个盆里最大值。
// dp[i][j]=max dp[i-1][k]+a[j][i] 

int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d",&f,&v);
	for(int i=1;i<=f;i++){
		for(int j=1;j<=v;j++){
			scanf("%d",&a[i][j]);
		}
	}
	memset(dp,128,sizeof dp);
	for(int i=0;i<=v;i++) dp[i][0]=0;
	for(int i=1;i<=v;i++){
		for(int j=1;j<=f;j++){
			dp[i][j]=max(dp[i-1][j-1]+a[j][i],dp[i-1][j]);
		}
	}
//	int ans=-inf;
	printf("%d\n",dp[v][f]);
	return 0 ;
}
