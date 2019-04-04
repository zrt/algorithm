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
LL dp[65537][16];
int n,K,s[16];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&K);
	for(int i=0;i<n;i++) scanf("%d",&s[i]);
	for(int i=0;i<n;i++) dp[1<<i][i]=1;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				for(int k=0;k<n;k++){
					if(!(i&(1<<k))&&abs(s[k]-s[j])>K){
						dp[i|(1<<k)][k]+=dp[i][j];
					}
				}
			}
		}
	}
	LL ans=0;
	for(int i=0;i<n;i++){
		ans+=dp[(1<<n)-1][i];
	}
	printf("%lld\n",ans);
	return 0;
}
