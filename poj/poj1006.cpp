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
LL p,e,i,d;
void exgcd(LL a,LL b,LL& x,LL& y,LL& d){
	if(b){
		exgcd(b,a%b,x,y,d);
		x-=a/b*y;
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
	int kase=0;
	LL x,y,gcd;
	while(scanf("%lld%lld%lld%lld",&p,&e,&i,&d),(~p)){
		exgcd(28,-23,x,y,gcd);
		x=(p-e)*x;
		LL x0=e-28*x;
		exgcd(28*23,-33,x,y,gcd);
		x=(x0-i)*x;
		x=x0-28*23*x;
		x-=d;
		x=(x%21252+21252)%21252;
		if(x==0) x+=21252;
		printf("Case %d: the next triple peak occurs in %lld days.\n",++kase,x);
	}
	
	return 0;
}
