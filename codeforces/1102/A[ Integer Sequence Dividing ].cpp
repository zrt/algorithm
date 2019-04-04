#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

LL n;

/// 
int main(){
	cin >> n;
	if((n*(n+1)/2)&1){
		puts("1");
	}else{
		puts("0");
	}

	return 0;
}
