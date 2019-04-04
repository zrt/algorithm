#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
double dp[2][10005];
//chou hou i zhang pai r zhang hong pai qi wang
int R,B;

int main(){
//	freopen("red.in","r",stdin);
//	freopen("red.out","w",stdout);
	scanf("%d%d",&R,&B);
	int n=R+B;
	int now=1;
	for(int i=1;i<=n;i++){
		dp[now][0]=0;
		for(int j=1;j<i&&j<=R;j++){
			dp[now][j]=max((dp[now^1][j-1]+1)*(j/(double)(i))+(dp[now^1][j]-1)*((i-j)/(double)(i)),0.0);
		}
		dp[now][i]=i;
		now^=1;
	}
	now^=1;
	double ans=((long long)(dp[now][R]*1000000))/1000000.0;
	printf("%.6f\n",ans);
	return 0;
}
