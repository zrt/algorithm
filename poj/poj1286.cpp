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
LL n;
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
LL pow(LL a,LL b){
	LL ret=1;
	while(b){
		if(b&1) ret*=a;
		a*=a;
		b>>=1;
	}
	return ret;
}
LL polya(LL n,LL c){
	LL ret=0;
	for(int i=0;i<n;i++){
		ret+=pow(c,gcd(n,i));
	}
	if(n&1){
		ret+=n*pow(c,n/2+1);
	}else{
		ret+=pow(c,n/2)*(n/2);
		ret+=pow(c,n/2+1)*(n/2);
	}
	return ret/n/2;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%lld",&n),(~n)){
		if(n==0) {
			puts("0");
			continue;
		}
		LL ans=0;
//		ans+=3*polya(n,1);
//		ans+=3*polya(n,2);
		ans+=polya(n,3);
		printf("%lld\n",ans);
	}
	return 0;
}
