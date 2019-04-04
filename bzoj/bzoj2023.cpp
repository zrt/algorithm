#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int mod=1000000;
int dp[2][100005];
int num[100005];
int sum[100005];
int solve(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t,a,s,b;
	scanf("%d%d%d%d",&t,&a,&s,&b);
	dp[0][0]=1;
	int x;
	for(int i=0;i<a;i++) scanf("%d",&x),num[x]++;
	for(int i=1;i<=t;i++){
		sum[0]=dp[(i-1)&1][0];
		for(int j=1;j<=b;j++) sum[j]=(sum[j-1]+dp[(i-1)&1][j])%mod;
		for(int j=0;j<=b;j++){
			if(j<=num[i]) dp[i&1][j]=sum[j];
			else dp[i&1][j]=(sum[j]-sum[j-num[i]-1])%mod;
		}
	}
	int ans=0;
	for(int i=s;i<=b;i++) ans=(ans+dp[t&1][i])%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}
int _=solve();
int main(){
	return 0;
}
