#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL f[89];
LL n;
LL dp[89][2];
int idx[89],m;
int main(){
	scanf("%lld",&n);
	f[1]=1,f[2]=2;
	for(int i=3;i<=88;i++) f[i]=f[i-1]+f[i-2];
	for(int i=88;i>=1;i--) if(f[i]<=n&&n) idx[m++]=i,n-=f[i];
	reverse(idx,idx+m);
	dp[0][1]=1;
	dp[0][0]=(idx[0]-1)/2;
	for(int i=1;i<m;i++){
		dp[i][1]=dp[i-1][0]+dp[i-1][1];
		dp[i][0]=(idx[i]-idx[i-1])/2*dp[i-1][0]+(idx[i]-idx[i-1]-1)/2*dp[i-1][1];
	}
	printf("%lld\n",dp[m-1][0]+dp[m-1][1]);
	return 0;
}
