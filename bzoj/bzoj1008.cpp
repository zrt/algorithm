#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
long long m,n;
long long mod=100003;
long long qpow(long long a,long long b){
	long long ret=1;
	a%=mod;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld%lld",&m,&n);
	printf("%lld\n",(qpow(m,n)-m*qpow(m-1,n-1)%mod+mod)%mod);	
	return 0;
}
