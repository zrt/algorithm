#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int tt;
int main(){
	scanf("%d",&tt);
	int l,r;
	while(tt--){
		scanf("%d%d",&l,&r);
		printf("%d %d\n",l,2*l);
	}

	return 0;
}