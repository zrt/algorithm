/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,a[30005];
int stk[30005],top;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		if(top==0||stk[top-1]<=a[i]){
			stk[top++]=a[i];
		}else{
			*upper_bound(stk,stk+top,a[i])=a[i];
		}
	}
	int ans=top;
	top=0;
	for(int i=n-1;i>=0;i--){
		if(top==0||stk[top-1]<=a[i]){
			stk[top++]=a[i];
		}else{
			*upper_bound(stk,stk+top,a[i])=a[i];
		}
	}
	ans=max(ans,top);
	printf("%d\n",n-ans);
	return 0;
}
