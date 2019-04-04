#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
int n;
int a[300005];
long long ans = 0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i*2<=n;i++){
		ans += (a[i]+a[n-i+1])*1LL*(a[i]+a[n-i+1]);
	}
	cout<<ans;
	
	return 0;
}
