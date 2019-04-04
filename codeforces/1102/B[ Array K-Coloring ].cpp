#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

int k,n;
int cnt[5050];
int a[5050];
int ans[5050];
vector<int> v[5050];
/// 
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) cnt[a[i]]++,v[a[i]].push_back(i);
	bool flag = 0;
	for(int i=0;i<=5000;i++){
		if(cnt[i]>k){
			flag = 1;
		}
	}
	if(flag) puts("NO");
	else{
		int kk=0;
		for(int i=0;i<=5000;i++){
			for(int j=0;j<v[i].size();j++){
				ans[v[i][j]] = kk;
				kk++;
				kk%=k;
			}
		}
		puts("YES");
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]+1);
		}
	}

	return 0;
}
