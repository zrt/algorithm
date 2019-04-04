#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;

int n;
LL ans[2000005];
int cnt = 0;

void calc(int d){
	int nd = n/d;
	// 0 .. 
	LL t = (n+2-d)*1LL*(nd)/2;
	ans[cnt++] = t;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i*i<=n;i++){
		if(n%i == 0){
			int a = i;
			int b = n/i;
			calc(a);
			if(a==b) continue;
			calc(b);
		}
	}
	sort(ans,ans+cnt);
	// printf("%d\n",cnt);
	cnt = unique(ans,ans+cnt)-ans;
	for(int i=0;i<cnt;i++){
		printf("%I64d ",ans[i]);
	}





	return 0;
}

