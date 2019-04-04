#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int stk[250005],top;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=0,x;i<n;i++){
		scanf("%*d%d",&x);
		while(top>0&&x<=stk[top-1]) {
			top--,ans++;
			if(stk[top]==x) ans--;
		}
		stk[top++]=x;
	}
	printf("%d\n",ans+top);
	return 0;
}
