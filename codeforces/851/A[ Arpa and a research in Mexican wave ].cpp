#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
LL n,k,t;
int main(){
	cin>>n>>k>>t;

	if(t<=k){
		cout<<t<<endl;
	}else if(t<=n){
		cout<<k<<endl;
	}else{
		cout<<n-(t-k)<<endl;
	}

	return 0;
}