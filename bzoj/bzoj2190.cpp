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
LL phi[40005];
int mindiv[40005],prime[40005],tot;
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
	printf("%lld\n",phi[n-1]*2+(n>1?1:0));
	return 0;
}
