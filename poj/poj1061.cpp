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
LL x0,y0,m,n,L;
void exgcd(LL a,LL b,LL& x,LL& y,LL& d){
	if(b){
		exgcd(b,a%b,x,y,d);
		x-=(a/b)*y;
		swap(x,y);
	}else{
		d=a;x=1;y=0;
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld%lld%lld%lld%lld",&x0,&y0,&m,&n,&L);
	LL x,y,a,b,c;
	a=m-n;
	b=L;
	c=y0-x0;
	LL gcd;
	exgcd(a,b,x,y,gcd);
	if(c%gcd){
		puts("Impossible");
		goto ed;
	}else{
		x=c/gcd*x;
		x=(x%L+L)%L;
		printf("%lld\n",x);
	}
	ed:return 0;
}
