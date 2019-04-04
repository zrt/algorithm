#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
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
	double sqrt5=sqrt(5.0);
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		if(a>b) swap(a,b);
		int j=b-a;
		int tmp=(int)(j*(1+sqrt5)/2.0);
		if(tmp==a) puts("0");
		else puts("1");
	}
	return 0;
}
