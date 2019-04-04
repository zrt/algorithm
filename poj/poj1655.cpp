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
int H[20005],X[40005],P[40005],tot;
int n;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int dp[20005],maxx[20005];
void dfs(int x,int fa){
	dp[x]=1;
	maxx[x]=0;
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa) continue;
		dfs(P[i],x);
		maxx[x]=max(maxx[x],dp[P[i]]);
		dp[x]+=dp[P[i]];
	}
	maxx[x]=max(maxx[x],n-dp[x]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int tt;
	scanf("%d",&tt);
	while(tt--){
		tot=0;
		scanf("%d",&n);
		memset(H,0,sizeof H);
	//	memset(dp,0,sizeof dp);
	//	memset(maxx,0,sizeof maxx);
		for(int i=1,x,y;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,y);add(y,x);
		}
		dfs(1,-1);
		int minn=inf,minpos;
		for(int i=1;i<=n;i++){
			if(maxx[i]<minn){
				minn=maxx[i];
				minpos=i;
			}
		}
		printf("%d %d\n",minpos,minn);
	}
	return 0;
}
