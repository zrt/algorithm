#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt

using namespace std;
typedef long long LL;
int n;
int qpow(int a,int b,int p){
	int ret=1;
	while(b){
		if(b&1) ret=ret*1LL*a%p;
		a=a*1LL*a%p;
		b>>=1;
	}
	return ret;
}
int f(int x){
	int ret=1;
	for(int i=2;i<=x;i++){
		ret=ret*1LL*i%9999991;
	}
	return ret;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	printf("%lld\n",qpow(n,n-2,9999991)*1LL*f(n-1)%9999991);
	return 0;
}
