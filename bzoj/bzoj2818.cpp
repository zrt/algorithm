#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
LL phi[10000007];
int mindiv[10000007],prime[10000007],tot;
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
		for(int j=0;prime[j]*i<=n;j++){
			mindiv[prime[j]*i]=prime[j];
			if(mindiv[i]==prime[j]){
				phi[prime[j]*i]=prime[j]*phi[i];
				break;
			}
			phi[prime[j]*i]=phi[prime[j]]*phi[i];
		}
	}
	for(int i=2;i<=n;i++) phi[i]+=phi[i-1];
	LL ans=0;
	for(int i=0;i<tot;i++){
		ans+=phi[n/prime[i]]*2-1;
	}
	printf("%lld\n",ans);
	return 0;
}
