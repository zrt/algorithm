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
	puts("100000 13");
	for(int i=0;i<100000;i++){
		putchar('a'+rand()%26);
	}
	puts("");
	return 0;
}
