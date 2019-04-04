#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
struct N{
	int a[105];
}dp[1005];
int n,k;
N operator + (N a,N b){
	N c;
	memset(c.a,0,sizeof c.a);
	for(int i=0;i<=100;i++){
		c.a[i]+=a.a[i]+b.a[i];
		c.a[i+1]+=c.a[i]/10;
		c.a[i]%=10;
	}
	return c;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	dp[0].a[0]=1;
	for(int i=1;i<=k;i++){
		for(int j=i;j<=n;j++){
			dp[j]=dp[j]+dp[j-i];
		}
	}
	int top=100;
	while(top>0&&dp[n].a[top]==0) top--;
	while(top>=0){
		putchar(dp[n].a[top]+'0');
		top--;
	}
	return 0;
}
