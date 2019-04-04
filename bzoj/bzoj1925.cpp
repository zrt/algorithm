#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,p;
int dp[4205][2];
int c[2][4205];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&p);
	dp[0][0]=1;
	dp[0][1]=1;
	dp[1][0]=1;
	dp[1][1]=1;
	c[1][0]=1;
	for(int i=2;i<=n;i++){
		int q=i&1;
		c[q][0]=1;
		for(int j=1;j<i;j++){
			c[q][j]=(c[q^1][j-1]+c[q^1][j])%p;
		}
		for(int j=1;j<=i;j++){
			if((i-j)&1) dp[i][0]+=dp[i-j][0]*1LL*dp[j-1][0]%p*c[q][j-1]%p,dp[i][0]%=p;
			else dp[i][1]+=dp[i-j][1]*1LL*dp[j-1][0]%p*c[q][j-1]%p,dp[i][1]%=p;
		}
	}
	printf("%d\n",(dp[n][0]+dp[n][1])%p);
	return 0;
}
