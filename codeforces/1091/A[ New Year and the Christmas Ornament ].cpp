#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

LL y,b,r;
int main(){
	cin >> y>>b>>r;
	LL x = min(y,min(b-1,r-2));
	cout << x*3+3<< endl;




	return 0;
}

