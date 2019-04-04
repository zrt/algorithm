#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
long long p,q; 
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld%lld",&p,&q);
	if(p==q){
		printf("%lld\n",(1+((p-1)/2))*((p-1)/2));
	}else{
		printf("%lld\n",(p-1)*(q-1)/4);
	}
	return 0;
}
