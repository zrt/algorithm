#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
const int MAXN=80005;
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
N stk[MAXN];
int top;
int see[MAXN];
int n;
int h[MAXN];
int inf=1<<30;
typedef long long LL;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	stk[top++]=N(n+1,inf);
	for(int i=n;i>=1;i--){
		while(stk[top-1].w<h[i]) top--;
		see[i]=stk[top-1].x;
		stk[top++]=N(i,h[i]);
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		ans+=see[i]-i-1;
	}
	printf("%lld\n",ans);
	return 0;
}
