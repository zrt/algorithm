#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int mod=5000011;
int n,k;
int dp[100005];

int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;i++){
		if(i<=k) dp[i]=i+1;
		else dp[i]=(dp[i-1]+dp[i-k-1])%mod;
	}
	printf("%d\n",dp[n]);
	return 0;
}
