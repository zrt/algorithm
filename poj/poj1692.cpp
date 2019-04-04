/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
int T;
int n,m;
int a[1500],b[1500];
int as[150],bs[150];
int dp[1500][1500];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int j=1;j<=m;j++){
			scanf("%d",&b[j]);
		}
		memset(as,-1,sizeof as);
	//	memset(bs,-1,sizeof bs);
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			memset(bs,-1,sizeof bs);
			for(int j=1;j<=m;j++){
				dp[i][j]=max(dp[i-1][j-1],max(dp[i][j-1],dp[i-1][j]));
				if(a[i]!=b[j]){
					if(~as[b[j]]&&~bs[a[i]]){
						dp[i][j]=max(dp[i][j],dp[as[b[j]]-1][bs[a[i]]-1]+2);
					}
				}
				bs[b[j]]=j;
			}
			as[a[i]]=i;
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				printf("%d ",dp[i][j]);
//			}
//			puts("");
//		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
