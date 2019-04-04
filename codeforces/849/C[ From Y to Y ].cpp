#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int k;
char s[10000005];
int main(){
	scanf("%d",&k);
	int sum=0;
	for(char i='a';i<='z';i++){
		int tmp=0;
		while(sum+tmp <= k){
			sum+=tmp;
			tmp++;
			putchar(i);
		}
	}
	puts("");
	return 0;
}