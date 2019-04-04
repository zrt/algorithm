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
int times;
LL n,m;
void solve(int n,int m){
	if(n<m) swap(n,m);
	//n>=m
	if(n==0||m==0) return;
	times++;
	if(n/m>1) return;
	solve(m,n%m);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%lld%lld",&n,&m),n|m){
		times=0;
		solve(n,m);
		if(times%2){
			puts("Stan wins");
		}else{
			puts("Ollie wins");
		}
	}
	
	return 0;
}
