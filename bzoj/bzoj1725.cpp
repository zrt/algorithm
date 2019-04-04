#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long LL;
LL dp[13][4097];
int map[13];// can not use
LL m,n;
LL mod=1000000000;
bool judge(int x){
	for(int i=1;i<m;i++){
		if(x&(1<<i)){
			if((x&(1<<(i-1)))||(x&(1<<(i+1)))) return 0;
		}
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=0,x;j<m;j++){
			scanf("%d",&x);
			if(!x) map[i]|=1<<j;
		}
	}
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<m);j++){
			if(!dp[i][j]) continue;
			for(int k=0;k<(1<<m);k++){
				if(judge(k)&&(!(k&map[i+1]))&&!(k&j)){
					dp[i+1][k]+=dp[i][j];
					if(dp[i+1][k]>=mod) dp[i+1][k]-=mod;
				}
			}
		}
	}
	LL ans=0;
	for(int i=0;i<(1<<m);i++){
		ans+=dp[n][i];
		if(ans>=mod) ans-=mod;
	}
	printf("%lld\n",ans);
	return 0;
}
