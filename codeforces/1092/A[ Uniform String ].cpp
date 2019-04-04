#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n;
int tt;
int main(){
	scanf("%d",&tt);
	while(tt--){
		int a,b;
		scanf("%d%d",&a,&b);
		int now = 0;
		for(int i=0;i<a;i++){
			putchar('a'+now);
			now++;
			now%=b;
		}
		puts("");
	}



	return 0;
}
