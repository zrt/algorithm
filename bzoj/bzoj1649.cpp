#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,l,b;
int inf=0x7f3f3f3f;
struct N{
	int l,r,f,c;
}a[10005];
bool cmp(N a,N b){
	if(a.r!=b.r)return a.r<b.r;
	return a.l<b.l;
}
int dp[1005][1005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&l,&n,&b);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i].l,&a[i].r,&a[i].f,&a[i].c);
		a[i].r+=a[i].l;
	}
	sort(a+1,a+n+1,cmp);
	memset(dp,128,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=a[i].c;j<=b;j++){
			dp[a[i].r][j]=max(dp[a[i].r][j],dp[a[i].r][j-1]);
			dp[a[i].r][j]=max(dp[a[i].r][j],dp[a[i].l][j-a[i].c]+a[i].f);
		}
	}
	int maxx=-inf;
	for(int i=1;i<=b;i++){
		maxx=max(maxx,dp[l][i]);
	}
	if(maxx==-inf) puts("-1");
	else printf("%d\n",maxx);
	return 0;
}
