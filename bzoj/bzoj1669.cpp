/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm> 
//by zrt
//problem:
using namespace std;
int stk[5005],top;
int a[5005],n;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		if(top==0||a[i]>stk[top-1]){
			stk[top++]=a[i];
		}
		else {
			*lower_bound(stk,stk+top,a[i])=a[i];
		}
	}
	printf("%d\n",top);
	return 0;
}
