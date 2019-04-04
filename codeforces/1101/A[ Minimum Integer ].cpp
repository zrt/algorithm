#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int q;
int main(){
	cin >> q;
	int l,r,d;
	while(q--){
		cin >> l >> r >> d;
		if(d < l){
			cout<<d<<endl;
		}else{
			cout<<(r/d+1)*1LL*d<<endl;
		}
	}
	

	return 0;
}