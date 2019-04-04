#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int n,b[50005],q;
int sum[50005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+b[i];
	while(q--){
		int t;
		scanf("%d",&t);
		printf("%d\n",upper_bound(sum,sum+n+1,t)-sum);
	}
	return 0;
}
