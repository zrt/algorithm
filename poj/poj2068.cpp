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
int dp[22][9000];
int n,S;
int b[45];
int dfs(int x,int S){
	if(dp[x][S]!=-1) return dp[x][S];
	for(int i=1;i<=b[x];i++){
		int t=S-i;
		if(t<0) break;
		int nxt;
		if(x+1>=n<<1) nxt=0;
		else nxt=x+1;
		if(!dfs(nxt,t)) return dp[x][S]=1;
	}
	return dp[x][S]=0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d",&n,&S),n){
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n<<1;i++) scanf("%d",&b[i]),dp[i][0]=1;
		printf("%d\n",dfs(0,S));
	}
	
	return 0;
}
