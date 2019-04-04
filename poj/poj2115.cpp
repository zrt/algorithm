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
LL k,a,b,c;
void exgcd(LL a,LL b,LL &d,LL &x,LL &y){
	if(!b){
		d=a;x=1,y=0;
	}else{
		exgcd(b,a%b,d,x,y);
		x-=a/b*y;
		swap(x,y);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%lld%lld%lld%lld",&a,&b,&c,&k),k|a|b|c){
		LL C=b-a;
		LL A=c;
		LL B=1LL<<(k);
		LL d;
		LL x,y;
		exgcd(A,B,d,x,y);
		if(C%d){
			puts("FOREVER");
		}else{
			x=C/d*x%B;
			x=(x%(B/d)+B/d)%(B/d);
			printf("%lld\n",x);
		}
	}
	return 0;
}
