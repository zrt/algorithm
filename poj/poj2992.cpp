#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,k;
int mindiv[505],prime[100],tot;
int cnt[505][100];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	for(int i=2;i<=500;i++){
		if(!mindiv[i]) mindiv[i]=i,prime[tot++]=i;
		for(int j=0;j<tot&&prime[j]*i<=500;j++){
			mindiv[prime[j]*i]=prime[j];
			if(prime[j]==mindiv[i]) break;
		}
	}
	for(int i=1;i<=500;i++){
		for(int j=0;j<tot&&prime[j]<=i;j++){
			cnt[i][j]+=cnt[i-1][j];
			int tmp=i;
			while(tmp%prime[j]==0) cnt[i][j]++,tmp/=prime[j];
		}
	}
	while(~scanf("%d%d",&n,&k)){
		//cnt[n]-cnt[k]-cnt[n-k]
		long long ans=1;
		for(int i=0;i<tot;i++){
			ans*=cnt[n][i]-cnt[k][i]-cnt[n-k][i]+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
