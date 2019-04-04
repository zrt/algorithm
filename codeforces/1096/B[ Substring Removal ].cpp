#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL p = 998244353 ;

int n;
char s[200005];
bool samel[200005];
bool samer[200005];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	LL l = 0;
	LL ans = 0;
	while(l<n && s[n-l] == s[n]) l++;
	l++;
	ans += l;
	if(s[n]!=s[1]) l = 1;
	for(int i=2;i<=n;i++){
		l = min(l, n-i+1LL);
		// printf("%d %I64d\n",i,l);
		ans = (ans +l)%p;
		if(i!=1 && s[i]!=s[i-1]) break;
	}
	printf("%I64d\n",ans);



	return 0;
}