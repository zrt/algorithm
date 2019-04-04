#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,w,h,s,t;
int sum[105][105];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d",&n),n){
		memset(sum,0,sizeof sum);
		scanf("%d%d",&w,&h);
		for(int i=0,x,y;i<n;i++){
			scanf("%d%d",&x,&y);
			sum[x][y]++;
		}
		for(int i=1;i<=w;i++){
			for(int j=2;j<=h;j++){
				sum[i][j]+=sum[i][j-1];
			}
		}
		for(int i=2;i<=w;i++){
			for(int j=1;j<=h;j++){
				sum[i][j]+=sum[i-1][j];
			}
		}
		int ans=0;
		scanf("%d%d",&s,&t);
		for(int i=s;i<=w;i++){
			for(int j=t;j<=h;j++){
				int tmp=sum[i][j]-sum[i-s][j]-sum[i][j-t]+sum[i-s][j-t];
				if(tmp>ans) ans=tmp;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
