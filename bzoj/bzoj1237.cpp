#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],b[100005];
long long f[100005];
long long inf=123456789876543LL;
long long merge(int x,int y){
	if(x==y) return inf;
	else return abs(x-y);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	f[1]=merge(a[1],b[1]);
	f[2]=min(f[1]+merge(a[2],b[2]),0LL+merge(a[1],b[2])+merge(a[2],b[1]));
	for(int i=3;i<=n;i++){
		f[i]=f[i-1]+merge(a[i],b[i]);
		f[i]=min(f[i],f[i-2]+merge(a[i-1],b[i])+merge(a[i],b[i-1]));
		f[i]=min(f[i],f[i-3]+merge(a[i-2],b[i-1])+merge(a[i-1],b[i])+merge(a[i],b[i-2]));
		f[i]=min(f[i],f[i-3]+merge(b[i-2],a[i-1])+merge(b[i-1],a[i])+merge(b[i],a[i-2]));
	}
	if(f[n]>=inf) puts("-1");
	else printf("%lld\n",f[n]);
	return 0;
}
