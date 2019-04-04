#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int a[1000005],n;
int read(){
	static char x;
	static int num;
	while(x=getchar(),x<'0'||x>'9');
	num=x-'0';
	while(x=getchar(),x>='0'&&x<='9') num*=10,num+=x-'0';
	return num;
}
long long dp[1000005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dp[i]=max(a[i]-dp[i-1],dp[i-1]);
	}
	printf("%d\n",dp[n]);
	return 0;
}
