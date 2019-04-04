#include<cstdio>
#include<cstring>
#include<algorithm>

//by zrt
//problem:
using namespace std;
int n,b;
int a[100006];
int sum[100006];
int cnt[200006];
int zero=100000;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&b);
	int pos;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int d;
		if(a[i]>b) d=1;
		else if(a[i]<b)d=-1;
		else d=0,pos=i;
		sum[i]=sum[i-1]+d;
	}
	int ans=0;
	for(int i=0;i<pos;i++){
		cnt[sum[i]+zero]++;
	}
	for(int i=pos;i<=n;i++){
		ans+=cnt[sum[i]+zero];
	}
	printf("%d\n",ans);
	return 0;
}
