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
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	int mx =0;
	for(int i=1;i<=n;i++) mx=max(mx,h[i]);
	int flag = 1;
	for(int i=1;i<=n;i++){
		if(top==0){
			stk[top++] = h[i];
		}else if(h[i]>stk[top-1]){
			flag = 0;
			break;
		}else if(h[i] == stk[top-1]){
			top --;
		}else if(h[i] < stk[top-1]){
			stk[top++] = h[i];
		}
	}
	
	

	if(flag && (top==0 || (top==1&&stk[0]==mx))) puts("YES");
	else puts("NO");

	return 0;
}