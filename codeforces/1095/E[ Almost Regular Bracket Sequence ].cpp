#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n;
int ans;
char s[1000005];
int a[1000005];
int mn[1000005];
int mnr[1000005];
void solve(){
	// l->r
	int cntl=0;
	int cntr=0;
	for(int i=1;i<=n;i++){
		if(s[i] == '(') cntl++;
		if(s[i] == ')') cntr++;
		a[i] = cntl - cntr;
		mn[i] = min(a[i],mn[i-1]);
	}
	mnr[n] = a[n];
	for(int i=n-1;i>=1;i--) mnr[i] = min(mnr[i+1],a[i]);
	// a[i..n] -= 2
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			if(mn[i-1] >= 0){
				if(mnr[i]>=2){
					ans++;
				}
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int cntl = 0;
	int cntr = 0;
	for(int i=1;i<=n;i++){
		if(s[i] == '(') cntl++;
		if(s[i] == ')') cntr++;
	}
	if(cntl == cntr +2){
		// l->r
		solve();
	}else if(cntl+2 == cntr){
		reverse(s+1,s+n+1);
		for(int i=1;i<=n;i++){
			if(s[i] == '(') s[i]=')';
			else s[i] = '(';
		}
		solve();
	}else{
		puts("0");
	}

	

	

	return 0;
}