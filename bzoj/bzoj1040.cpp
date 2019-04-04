#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int H[2000006],X[4000006],P[4000006];
typedef long long LL;
LL val[2000006];
bool vis[2000006];
int tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int n;
int pre[2000006];
bool oncircle[2000006];
int cc;
int circle[2000006];
LL sum[2000006][2];
bool found;
LL dp[2000006][2];//1 chose 0 unchose
LL _c;
void Dp(int x,int fa){
	vis[x]=1;
	dp[x][1]=val[x];
	dp[x][0]=0;
	for(int i=H[x];i;i=X[i]){
		if(!oncircle[P[i]]&&P[i]!=fa){
			Dp(P[i],x);
			dp[x][1]+=dp[P[i]][0];
			dp[x][0]+=max(dp[P[i]][0],dp[P[i]][1]);
		}
	}
}
void dfs(int x,int fa){
	vis[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(i==fa) continue;
		if(!vis[P[i]]){
			pre[P[i]]=x;
			dfs(P[i],i^1);
			if(found) return;
		}else{
			// find a circle
			cc=0;
			int k=x;
			do{
				circle[cc++]=k;
				oncircle[k]=1;
				k=pre[k];
			}while(k!=P[i]);
			circle[cc++]=k;
			oncircle[k]=1;
			for(int i=0;i<cc;i++){
				Dp(circle[i],-1);
			}
			//chose first
			sum[0][0]=dp[circle[0]][0];
			sum[0][1]=max(dp[circle[0]][0],dp[circle[0]][1]);
			for(int i=1;i<cc;i++){
				sum[i][0]=max(sum[i-1][0],sum[i-1][1])+dp[circle[i]][0];
				sum[i][1]=sum[i-1][0]+max(dp[circle[i]][1],dp[circle[i]][0]);
			}
			_c=max(_c,sum[cc-1][0]);
			sum[0][0]=sum[0][1]=dp[circle[0]][0];
			for(int i=1;i<cc;i++){
				sum[i][0]=max(sum[i-1][0],sum[i-1][1])+dp[circle[i]][0];
				sum[i][1]=sum[i-1][0]+max(dp[circle[i]][1],dp[circle[i]][0]);
			}
			_c=max(_c,max(sum[cc-1][0],sum[cc-1][1]));
			found=1;
			return;
		}
	}
}
LL solve(int x){
	pre[x]=-1;
	found=0;
	_c=0;
	dfs(x,-1);
	return _c;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	tot=1;
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%lld%d",&val[i],&x);
		add(x,i);
		add(i,x);
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans+=solve(i);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
