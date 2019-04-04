#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int tt,n;
const int size=31269;
unsigned a[size],sum[size];
void dabiao(){
	a[1]=sum[1]=1;
	for(int i=2;i<size;i++){
		a[i]=a[i-1]+(int)log10((double) i)+1;
		sum[i]=sum[i-1]+a[i];
	}
}
int jisuan(int n){
	int i=lower_bound(sum,sum+size,n)-sum;
	int pos=n-sum[i-1];
	int len=0;
	for(i=1;len<pos;i++){
		len+=(int)log10((double)i)+1;
	}
	return (i-1)/(int)pow(10.0,len-pos)%10;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d",&tt);
	dabiao();
	while(tt--){
		scanf("%d",&n);
		printf("%d\n",jisuan(n));
	}
	return 0 ;
}
