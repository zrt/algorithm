#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
//by zrt
//problem:
using namespace std;
set<int> a[10005];
int h[10005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n,H,r;
	scanf("%d%*d%d%d",&n,&H,&r);
	for(int i=1,x,y;i<=r;i++){
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		if(a[x].count(y)) continue;
		a[x].insert(y);
		h[x+1]--;
		h[y]++;
	}
	int sum=H;
	for(int i=1;i<=n;i++){
		sum+=h[i];
		printf("%d\n",sum);
	}
	return 0;
}
