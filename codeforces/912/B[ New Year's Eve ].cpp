#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
LL n,k;
int main(){
	cin>>n>>k;
	if(k==1) cout<<n<<endl;
	else {
		LL ans = 1;
		while (ans < n) ans = ans * 2 +1;
		cout<<ans<<endl;
	}
	return 0;
}