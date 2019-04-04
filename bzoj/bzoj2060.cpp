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
int H[50005],X[100005],P[100005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int dp[50005][2];
int f[50005];
// 1.. | 0..
void dfs(int x,int fa){
	f[x]=fa;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa){
			dfs(P[i],x);
		}
	}
}
void d(int x,int fa){
	dp[x][1]++;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa){
			d(P[i],x);
		}
	}
	dp[f[f[x]]][1]+=max(dp[x][1],dp[x][0]);
	dp[f[x]][0]+=max(dp[x][1],dp[x][0]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	d(1,0);
	printf("%d",max(dp[1][1],dp[1][0]));
	return 0;
}
