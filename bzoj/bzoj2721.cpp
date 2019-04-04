#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int mod=1e9+7;
int n;
int mindiv[1000005],prime[100005],tot;
int num[1000005];
void calc(int x){
	while(x!=1){
		num[mindiv[x]]++;
		x/=mindiv[x];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		if(!mindiv[i]) mindiv[i]=i,prime[tot++]=i;
		for(int j=0;prime[j]*1LL*i<=n;j++){
			mindiv[prime[j]*i]=prime[j];
			if(prime[j]==mindiv[i]) break;
		}
	}
	for(int i=1;i<=n;i++){
		calc(i);
	}
	LL ans=1;
	for(int i=2;i<=n;i++){
		ans=ans*(num[i]*2+1)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
