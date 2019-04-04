#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n;
char s[1000];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);

	int cnt = 0;
	for(int i=1;i<=n;i++){
		cnt ++;
		putchar(s[i]);
		i+=(cnt-1);
	}
	
	

	return 0;
}