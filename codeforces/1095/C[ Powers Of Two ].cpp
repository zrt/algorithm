#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

LL n,k;
int cnt[60];
int main(){
	cin>>n>>k;
	int sum = 0;
	for(int i=32;i>=0;i--){
		if(n>>i&1) cnt[i] = 1, sum++;
	}
	for(int i=32;i>=1;i--){
		while(cnt[i]!=0 && sum < k){
			cnt[i-1] +=2;
			cnt[i] --;
			sum++;
		}
	}
	if(sum == k){
		puts("YES");
		for(int i=0;i<32;i++){
			if(cnt[i]!=0){
				for(int j=0;j<cnt[i];j++){
					cout<<(1<<i)<<' ';
				}
			}
		}
	}else{
		puts("NO");
	}

	return 0;
}