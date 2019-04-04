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
int n,k;
double baoli(int x){
	double ans=0;
	for(int i=1;i<=x;i++){
		ans+=log((double)i);
	}
	ans/=log((double)k);
	return ceil(ans+eps);
}
double pi=acos(-1.0);
double e=exp(1);
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(~scanf("%d%d",&n,&k)){
		if(n<1000) printf("%.0f\n",baoli(n));
		else printf("%.0f\n",ceil((0.5*log(2*pi*n)+n*log(n)-n*log(e))/log((double)k)));
	}
	
	return 0;
}
