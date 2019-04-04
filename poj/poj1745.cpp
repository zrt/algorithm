#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
bool dp[10005][105];
int n,k;
int a[10005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	dp[0][0]=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=(a[i]%k+k)%k;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			dp[i][j]|=dp[i-1][(j-a[i]+k+k)%k]|dp[i-1][(j+a[i])%k];//+
		}
	}
	if(dp[n][0]){
		puts("Divisible");
	}else{
		puts("Not divisible");
	}
	return 0;
}
