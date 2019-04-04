#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000005];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=a[n+1]=0x7fffffff;
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]) ans+=a[i];
		if(a[i]>=a[i+1]) ans+=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}
