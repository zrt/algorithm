#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
LL a,b,x,y,z;
int main(){
	cin>>a>>b>>x>>y>>z;
	cout<<max(0LL,2*x+y-a)+max(0LL,y+3*z-b)<<endl;
	return 0;
}