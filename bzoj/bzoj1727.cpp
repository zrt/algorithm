#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
struct N{
	int a,b;
}a[25005];
int n;
bool cmp(N a,N b){
	return min(a.b,b.a)>min(b.b,a.a);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].a,&a[i].b);
	}
	sort(a+1,a+n+1,cmp);
	int tima=0,timb=0;
	for(int i=1;i<=n;i++){
		tima+=a[i].a;
		timb=max(timb,tima);
		timb+=a[i].b;
	}
	printf("%d\n",timb);
	return 0;
}
