#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL p = 998244353 ;

int tt;
int main(){
	scanf("%d",&tt);
	while(tt--){
		int n;
		scanf("%d",&n);
		// -1
		if(n<90){
			int ans = 3;
			while (ans * n % 180){
				ans++;
			}
			printf("%d\n",ans);
		}else{
			n = 180-n;

			int ans = 3;
			while (ans * n % 180 !=0 || ans*n<=180){
				ans++;
			}
			printf("%d\n",ans);
		}

	}


	return 0;
}