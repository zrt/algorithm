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
LL ans;
LL c,k;
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
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%lld%lld",&c,&k),c|k){
		if(k&1){
			ans=pow(c,k/2+1)*k;
		}else{
			ans=pow(c,k/2)*(k/2);
			ans+=pow(c,k/2+1)*(k/2);
		}
		for(int i=0;i<k;i++){
			ans+=pow(c,gcd(i,k));
		}
		printf("%lld\n",ans/(2*k));
	}
	return 0;
}
