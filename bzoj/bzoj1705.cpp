#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int dp[100005][105];
int h[100005];
int n,c;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=h[1];i<=100;i++) dp[1][i]=(h[1]-i)*(h[1]-i);
	for(int i=2;i<=n;i++){
		for(int j=h[i];j<=100;j++){
			for(int k=h[i-1];k<=100;k++){
				dp[i][j]=min(dp[i][j],dp[i-1][k]+(h[i]-j)*(h[i]-j)+c*abs(j-k));
			}
		}
	}
	int ans=1<<30;
	for(int i=h[n];i<=100;i++) ans=min(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}
