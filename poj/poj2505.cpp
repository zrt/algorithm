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

int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	LL n;
	while(~scanf("%lld",&n)){
		bool ok;
		while(1){
			LL p=(n-1)/9+1;
			if(1>=p){
				ok=1;break;
			}else n=p;
			p=(n-1)/2+1;
			if(1>=p){
				ok=0;break;
			}else n=p;
		}
		if(ok){
			puts("Stan wins.");
		}else{
			puts("Ollie wins. ");
		}
	}
	
	return 0;
}
