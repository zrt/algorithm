#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n;
int a[200005][2];
int ans[200005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	ans[1] = 1;
	ans[2] = a[1][0];
	ans[3] = a[1][1];
	bool flag = 1;
	for(int i=2;i+2<=n;i++){
			// printf("%d %d %d %d\n",i, a[ans[i]][0] , ans[i+1], a[ans[i]][1]);
		if (ans[i+1]!= a[ans[i]][0] && ans[i+1]!= a[ans[i]][1]){
			flag = 0;
			break;
		}
		ans[i+2] = a[ans[i]][0] ^ ans[i+1] ^ a[ans[i]][1];
	}
	// printf("%d %d %d\n",
	// 	flag,
	// 	((a[n-1][0] == ans[n] && a[n-1][1] == 1) ||(a[n-1][1] == ans[n] && a[n-1][0] == 1)) ,
	// 	((a[n][0] == 1 && a[n][1] == ans[2]) ||(a[n-1][1] == 1 && a[n-1][0] == ans[2]))
	// 	);
	if(flag &&((a[ans[n-1]][0] == ans[n] && a[ans[n-1]][1] == 1) ||(a[ans[n-1]][1] == ans[n] && a[ans[n-1]][0] == 1)) 
		&& ((a[ans[n]][0] == 1 && a[ans[n]][1] == ans[2]) ||(a[ans[n]][1] == 1 && a[ans[n]][0] == ans[2]))){

		// puts("ok");
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
	}else{
		ans[1] = 1;
		ans[2] = a[1][1];
		ans[3] = a[1][0];
		for(int i=2;i+2<=n;i++){
			ans[i+2] = a[ans[i]][0] ^ ans[i+1] ^ a[ans[i]][1];
		}
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
	}

	

	

	return 0;
}