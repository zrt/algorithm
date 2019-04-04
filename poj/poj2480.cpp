#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int mindiv[100005],prime[100005],tot;
LL phi(LL x){
	LL ret=x;
	LL sqr=sqrt(x+0.5);
	for(int i=0;prime[i]<=sqr;i++){
		if(x%prime[i]==0){
			ret-=ret/prime[i];
			while(x%prime[i]==0) x/=prime[i];
		}
	}
	if(x>1) ret-=ret/x;
	return ret;
}
LL ans;
LL x;
LL sqr;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	for(int i=2;i<=100000;i++){
		if(!mindiv[i]){
			mindiv[i]=i;
			prime[tot++]=i;
		}
		for(int j=0;prime[j]*i<=100000;j++){
			mindiv[prime[j]*i]=prime[j];
			if(prime[j]==mindiv[i]) break;
		}
	}
	while(~scanf("%lld",&x)){
		sqr=sqrt(x+0.5);
		ans=0;
		for(int i=1;i<=sqr;i++){
			if(x%i==0){
				if(i==sqr){
					if(i*1LL*i==x){
						ans+=i*phi(i);
					}else ans+=i*phi(x/i)+x/i*phi(i);
				}else{
					ans+=i*phi(x/i)+x/i*phi(i);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
