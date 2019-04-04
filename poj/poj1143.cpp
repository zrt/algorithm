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
int dp[(1<<20)+2]; // true win //false lose
int num[25];
int n;
int kase;
int mark[25];
int ans[25],top;
int update(int st,int pos){// 从st中去掉pos 
	for(int k=1;;k++){
		if(num[pos]*k>20) break;
		if(mark[num[pos]*k]!=-1) st&=~(1<<mark[num[pos]*k]);
		for(int i=0;i<n;i++){
			if(st&(1<<i)){
				if(num[i]-num[pos]*k>1&&(mark[num[i]-num[pos]*k]==-1||(!(st&(1<<mark[num[i]-num[pos]*k]))))){
					st&=~(1<<i);
				}
			}
		}
	}
	return st;
}
//如果一个状态的后继状态都是必胜状态,那么它是必败状态。如果一个状态的后继状态中存在必败状态,那么它是必胜状态。 
bool dfs(int st){
	if(dp[st]!=-1) return dp[st];
	for(int i=0;i<n;i++){
		if(st&(1<<i)){
			if(!dfs(update(st,i))) return (dp[st]=true);
		}
	}
	return (dp[st]=false);
}
int begin;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	while(scanf("%d",&n),n){
		memset(dp,-1,sizeof dp);
		memset(mark,-1,sizeof mark);
		begin=0;top=0;
		for(int i=0;i<n;i++) scanf("%d",&num[i]),begin|=1<<i,mark[num[i]]=i;
//		printf("%d#%d\n",begin,update(begin,1));
		printf("Test Case #%d\n",++kase);
		for(int i=0;i<n;i++){
			if(!dfs(update(begin,i))) ans[top++]=i;
		}
		if(top){
			printf("The winning moves are:");
			for(int i=0;i<top;i++) printf(" %d",num[ans[i]]);
			puts("\n");
		}else{
			puts("There's no winning move.\n");
		}
	}
	return 0 ;
}
