#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int n,t;
struct N{
	int l,r;
	friend bool operator < (N a,N b){
		return a.l<b.l;
	}
}a[25005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	bool ok=1;
	sort(a+1,a+1+n);
	int p=1;
	int ans=0;
	for(int i=1;i<=t;i++){
		int mx=-1;
		while(a[p].l<=i) mx=max(mx,a[p].r),p++;
		if(mx==-1) {
			ok=0;
			break;
		}
		ans++;
		i=mx;
	}
	if(ok) printf("%d\n",ans);
	else puts("-1");
	return 0;
}
