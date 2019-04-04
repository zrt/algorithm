#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long LL;
LL n;
struct N{
	LL t,d;
	N(LL a=0,LL b=0){
		t=a,d=b;
	}
	friend bool operator < (N a,N b){
		return b.d*a.t<a.d*b.t;
	}
}a[100005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].t,&a[i].d);
	}
	// a zai b qian mian xu yao man zu
	// (b.d)*a.t< (a.d)*b.t
	sort(a+1,a+n+1);
	LL sum=0;
	LL tim=0;
	for(int i=1;i<=n;i++){
		sum+=a[i].d*tim;
		tim+=a[i].t*2;
	}
	printf("%lld\n",sum);
	return 0;
}
