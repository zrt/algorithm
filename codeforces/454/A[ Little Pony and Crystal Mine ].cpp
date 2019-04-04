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
int n;
int main(){
	#ifdef LOCAL
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++){
		int num=(i-1);
		int num2=(n-num-num-1)/2;
		for(int i=0;i<num2;i++) printf("*");
		for(int i=0;i<num*2+1;i++) printf("D");
		for(int i=0;i<num2;i++) printf("*");
		puts("");
	}
	for(int i=1;i<=n;i++) printf("D");
	puts("");
	for(int i=n/2+2;i<=n;i++){
		int num=(n-i);
		int num2=(n-num-num-1)/2;
		for(int i=0;i<num2;i++) printf("*");
		for(int i=0;i<num*2+1;i++) printf("D");
		for(int i=0;i<num2;i++) printf("*");
		puts("");
	}
	return 0;
}
