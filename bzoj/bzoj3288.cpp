#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int mindiv[1000005],prime[100005],tot;
int phi[1000005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!mindiv[i]) mindiv[i]=i,prime[tot++]=i,phi[i]=i-1;
		for(int j=0;j<tot&&prime[j]*1LL*i<=n;j++){
			mindiv[prime[j]*i]=prime[j];
			if(prime[j]==mindiv[i]) {
				phi[prime[j]*i]=phi[i]*prime[j];
				break;
			}
			phi[prime[j]*i]=phi[i]*phi[prime[j]];
		}
	}
	long long ans=1;
	for(int i=2;i<=n;i++) ans=ans*phi[i]%1000000007;
	printf("%lld\n",ans);
	return 0;
}
