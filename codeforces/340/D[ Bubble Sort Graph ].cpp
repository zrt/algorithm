#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n;
int a[100005];
int stk[100005],top;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(top==0) stk[top++]=a[i];
		else if(a[i]>stk[top-1]){
			stk[top++]=a[i];
		}else{
			*lower_bound(stk,stk+top,a[i])=a[i];
		}
	}
	printf("%d\n",top);
	return 0;
}
