#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
long long a[]={2,3,5,7,11,13,17,19,23};
int tt;
long long n;
long long ans;
long long mulmod(long long a,long long b,long long p){
	return (a * b - (long long)((long double)a / p * b + 1e-3) * p + p) % p; 
}
long long qpow(long long a,long long b,long long p){
	long long ret=1;
	while(b>0){
		if(b&1) ret=mulmod(ret,a,p);
		a=mulmod(a,a,p);
		b>>=1;
	}
	return ret;
}
bool test(long long n,long long a,long long d){
	long long s=0;
	if(n<2) return 0;
	if(!(n&1)) return 0;
	while(!(d&1)) s++,(d>>=1);
	long long r=qpow(a,d,n);
	if(r==1) return 1;
	for(int i=0;i<s;i++){
		if(r==n-1) return 1;
		r=mulmod(r,r,n);
	}
	return 0;
}
bool check(long long n){
	if(n<2) return 0;
	if(n==2) return 1;
	for(int i=0;i<9;i++){
		if(n==a[i]) return 1;
		if(!test(n,a[i],n-1)) return 0;
	}
	return 1;
}
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
long long pol(long long n,long long c){
	long long i=1,k=2,x,y,d;
	x=rand()%n;
	y=x;
	while(1){
		i++;
		x=(mulmod(x,x,n)+c)%n;
		if(y==x) return n;
		d=gcd(x>y?(x-y):(y-x),n);
		if(d!=1&&d!=n) return d;
		if(i==k){
			k<<=1;
			y=x;
		}
	}
}
void find(long long n){
	if(check(n)){
		if(n<ans) ans=n;
		return;
	}
	long long p=n;
	while(p==n) p=pol(p,rand()%(n-1)+1);
	find(p);
	find(n/p);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%lld",&n);
		if(check(n)){
			puts("Prime");
		}else{
			ans=n;
			find(n);
			printf("%lld\n",ans);
		}
	}
	
	return 0;
}