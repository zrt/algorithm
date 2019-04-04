#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long h,a,b,k,tt;
int main(){
	while(scanf("%lld%lld%lld%lld",&h,&a,&b,&k),a|b|h|k){
		printf("Case #%lld: ",++tt);
		if(h<=a){
			puts("YES");
		}else if(h<=a*k-b*(k-1)){
			puts("YES");
		}else if(h-a*k+b*(k+1)<h){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}
