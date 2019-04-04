#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
LL n,s;
LL calcmn(LL n, LL k){
	if(k==1){
		return n*(n+1)/2;
	}
	LL num = 1;
	LL sum = 0;
	LL sumd = 0;
	LL dep = 1;
	for(;;){
		LL x = n - sum;
		if(x<= num){
			sum += x;
			sumd += dep*x;
			break;
		}else{
			sum += num;
			sumd+=num*dep;
			dep++;
			num = num*k;
		}
	}
	return sumd;
}
bool check(LL k, LL n, LL s){
	if(n*(n+1)/2 < s) return false;
	if(calcmn(n,k) <= s) return true;
	else return false;
}

LL num[100005];
LL K;
LL tot = 0;

void dfs(int x,int dep){
	LL now = ++tot;
	if(now!=1) 
		printf("%d ",x);
	for(int i=1;i<=K;i++){
		if(num[dep+1]>0){
			num[dep+1]--;
			dfs(now,dep+1);
		}else{
			break;
		}
	}
}


int main(){
	cin >> n >> s;
	if(n*(n+1)/2 < s){
		puts("No");
		exit(0);
	}
	LL L = 0, R = n+1;
	// L bukexing , R kexing
	while(R-L>1){
		LL mid = (L+R)/2;
		if(check(mid,n,s))  R=mid;
		else L=mid;
	}
	if(R== n+1){
		puts("No");
		exit(0);
	}
	puts("Yes");
	K=R;
	LL now = (n*(n+1))/2;
	for(int i=1;i<=n;i++) num[i] = 1;
	int cur = 2;

	int last = n;
	while(now > s){
		if(num[cur-1]*R == num[cur]){
			cur++;
			continue;
		}
		LL mxs = last-cur;
		if(now-mxs >= s){
			now -= mxs;
			num[last] --;
			num[cur] ++;
		}else{
			num[last- (now-s)] ++;
			num[last] -- ;
			break;
		}
		last--;
	}

	num[1]--;
	dfs(0,1);

	return 0;
}
