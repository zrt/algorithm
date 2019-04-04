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
int n;
double p[130][130];
double dp[8][130];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d",&n),~n){
		for(int i=0;i<1<<n;i++){
			for(int j=0;j<1<<n;j++){
				scanf("%lf",&p[i][j]);
			}
		}
		memset(dp,0,sizeof dp);
		for(int i=0;i<1<<n;i++) dp[0][i]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<1<<n;j++){
				for(int k=0;k<1<<n;k++){
					if(((j>>(i-1))^1)==k>>(i-1)){
						dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];
					}
				}
			}
		}
		double maxx=-1;
		int maxpos=0;
		for(int i=0;i<1<<n;i++){
			if(dp[n][i]>maxx){
				maxx=dp[n][i];
				maxpos=i;
			}
		}
		printf("%d\n",maxpos+1);
	}
	return 0;
}
