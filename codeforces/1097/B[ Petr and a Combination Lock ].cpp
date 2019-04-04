#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n;
int a[25];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	bool flag = 0;
	for(int i=0;i<(1<<n);i++){
		int sum = 0;
		for(int j=0;j<n;j++){
			if(i>>j&1){
				sum += a[j];
			}else{
				sum -= a[j];
			}
		}
		if(sum%360 == 0) flag = 1;
	}

	if(flag){
		puts("YES");
	}else{
		puts("NO");
	}
	

	return 0;
}
