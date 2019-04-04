#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;

const int mod = 998244353;

LL n;

LL f[1000005];
LL fac[1000005];
int main(){
	fac[0] = 1;
	for(int i=1;i<=1000000;i++) fac[i] = fac[i-1]*i%mod;
	cin>>n;
	f[1] = 1;
	for(int i=2;i<=n;i++){
		f[i] = (f[i-1]*i%mod + (fac[i-1] -1+mod)%mod*i%mod)%mod; 
	}
	cout<<f[n]<<endl;

	return 0;
}

