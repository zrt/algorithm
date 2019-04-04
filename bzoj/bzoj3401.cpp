#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int h[100005];
int n;
int stk[100005];
int top;
int ans[100005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	for(int i=n;i>0;i--){
		while(top!=0&&h[stk[top-1]]<=h[i]) top--;
		if(top==0) ans[i]=0;
		else ans[i]=stk[top-1];
		stk[top++]=i;
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
