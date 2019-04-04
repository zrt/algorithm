#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;

LL n,k;

LL a,b;
LL x,y;
LL gcd(LL a,LL b){
	return b == 0?a:gcd(b,a%b);
}
void solve(LL n,LL k, LL a,LL b){
	for(int i=0;i<=n;i++){
		LL nb = i*k + b;
		LL l = nb-a;
		// printf("# %lld %lld %lld\n",l,a,nb);
		l = (l%(n*k) + n*k )%(n*k);
		if (l==0) l = n*k;
		LL g = n*k/gcd(n*k, l);
		// printf("## %lld %lld\n",l,g);
		x = min(x, g);
		y = max(y, g);
	}
}
int main(){
	cin>>n>>k;
	cin>>a>>b;
	x = n*k;
	y = 0;

	solve(n,k,a,b);
	solve(n,k,-a,b);
	solve(n,k,a,-b);
	solve(n,k,-a,-b);

	cout<<x<<" "<<y<<endl;


	return 0;
}
