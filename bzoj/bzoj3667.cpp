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
int a[]={2,3,5,7,11,13,17,19,23} ;
LL mulmod(LL a,LL b,LL p){
	/*
	LL ret=0;
	while(b){
		if(b&1) ret+=a,ret%=p;
		a=(a<<1)%p;
		b>>=1;
	}
	return ret;
	*/
//	return a*b%p;
	return (a * b - (long long)((long double)a / p * b + 1e-3) * p + p) % p; 
}
LL powmod(LL a,LL b,LL p){
	LL ret=1;
	while(b){
		if(b&1) ret=mulmod(ret,a,p);
		a=mulmod(a,a,p);
		b>>=1;
	}
	return ret;
}
bool test(LL n,LL a,LL d){
	LL s=0;
	if(n<2) return 0;
	if(!(n&1)) return 0;
	while(!(d&1)) s++,d>>=1;
	if(powmod(a,d,n)==1) return 1;
	for(int i=0;i<=s-1;i++){
		if(powmod(a,powmod(2,i,n)*d,n)==n-1) return 1;
	}
	return 0;
}
bool check(LL n){
	if(n<2) return 0;
	if(n==2) return 1;
	for(int i=0;i<=8;i++){
		if(n==a[i]) return 1;
		if(!test(n,a[i],n-1)) return 0;
	}
	return 1;
}
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
LL ans;
LL rho(LL n,LL c){
//	printf("%lld %lld\n",n,c);
	LL i=1,k=2,x,y,d,p;
	if(!(n&1)) return 2;
	y=x=rand()%n;
	while(1){
		i++;
		x=(mulmod(x,x,n)+c)%n;
		if(x==y) return n;
		if(y>x) p=y-x;else p=x-y;
		d=gcd(p,n);
		if(d!=1&&d!=n) return d;
		if(i==k){
			k<<=1;
			y=x;
		}
	}
}
void find(LL n){
//	printf("%lld\n",n);
	if(check(n)){
		if(n>ans) ans=n;
		return;
	}else{
		LL p=n;
		while(p>=n) p=rho(p,rand()%(n-1)+1);
		find(p);
		find(n/p);
	}
}
int tt;
LL n;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%lld",&n);
		if(check(n)) puts("Prime");
		else if(n==1) puts("1");
		else{
			ans=0;
			find(n);
			printf("%lld\n",ans);
		}
	}
	
	return 0;
}
