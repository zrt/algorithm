#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n;
int h[200005];
int stk[200005],top;


int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]),h[i]%=2;
	for(int i=1;i<=n;i++){
		if(top==0 || stk[top-1] != h[i]){
			stk[top++] = h[i];
		}else{
			top--;
		}
	}
	
	

	if(top<=1) puts("YES");
	else puts("NO");

	return 0;
}