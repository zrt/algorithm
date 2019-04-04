#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n;
int a[100005];
int ans;
void check(int x){
	int mx = 0;
	int mn = 100005;
	
	for(int i=1;i<=n;i++){
		if(i==x) continue;
		mx = max(mx,a[i]);
		mn = min(mn,a[i]);
	}
	ans = min(ans,mx-mn);
}
int main(){
	scanf("%d",&n);
	int mx = 0;
	int mn = 100005;
	ans = 100005*100;
	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx = max(mx,a[i]);
		mn = min(mn,a[i]);
	}
	// printf("%d %d\n",mn,mx);
	for(int i=1;i<=n;i++){
		if(mx == a[i]){
			check(i);
			mx = -1;
		}
		if(mn == a[i]){
			check(i);
			mn = -1;
		}
	}

	printf("%d\n",ans);
	

	return 0;
}