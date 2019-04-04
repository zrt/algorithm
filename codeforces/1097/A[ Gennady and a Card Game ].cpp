#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

char s[10];
char a[10][10];

int main(){
	scanf("%s",s);
	for(int i=0;i<5;i++){
		scanf("%s",a[i]);
	}
	bool flag = 0;
	for(int i=0;i<5;i++){
		if(a[i][0] == s[0] || a[i][1] == s[1]){
			flag = 1;
			break;
		}
	}
	if(flag){
		puts("YES");
	}else{
		puts("NO");
	}
	

	return 0;
}
