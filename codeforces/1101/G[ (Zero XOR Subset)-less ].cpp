#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;

int n;
int a[200005];
int s[200005];
int ok[200005];
int p[200005];
bool add(int x){
	for(int i=0;i<31;i++){
		if(x>>i&1){
			if(ok[i]){
				x ^= p[i];
			}else{
				ok[i] = 1;
				p[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i], s[i] = s[i-1]^a[i];
	int ans = 0;

	for(int i=1;i<=n;i++){
		if(add(s[i])){
			ans++;
		}
		// if(s[i] == 0) flag = 1;
	}
	if(s[n] == 0) cout<<-1;
	else cout<<ans;
	// return 0;
}