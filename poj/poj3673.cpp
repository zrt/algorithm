#include<iostream>
#include<cstdio>
#include<string>
//by zrt
//problem:
using namespace std;
string a,b;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	cin>>a>>b;long long sum=0LL;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			sum+=(a[i]-'0')*(b[j]-'0');
		}
	}
	cout<<sum;
	return 0;
}
