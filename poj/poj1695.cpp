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
int tt;
int n;
int d[35][35];
int dp[35][35][35];//i>=j>=k
int to[3];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				scanf("%d",&d[i][j]);
			}
		}
		memset(dp,0x3f,sizeof dp);
		dp[1][1][1]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					//now i,j,k
					to[0]=i+1,to[1]=j+1,to[2]=k+1;
					for(int z=0;z<3;z++){
						dp[to[z]][j][k]=min(dp[to[z]][j][k],dp[i][j][k]+d[i][to[z]]);
						dp[i][to[z]][k]=min(dp[i][to[z]][k],dp[i][j][k]+d[j][to[z]]);
						dp[i][j][to[z]]=min(dp[i][j][to[z]],dp[i][j][k]+d[k][to[z]]);
					}
				}
			}
		}
		int ans=inf;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans=min(ans,dp[n][i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0 ;
}
