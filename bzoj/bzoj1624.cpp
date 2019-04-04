#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n;
int dis[105][105]; 
int m,a[10005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&dis[i][j]);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	long long ans=0;
	for(int i=2;i<=m;i++){
		ans+=dis[a[i-1]][a[i]];
	}
	printf("%lld\n",ans);
	
	return 0;
}
