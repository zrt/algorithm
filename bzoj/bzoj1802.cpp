#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[1005];
typedef long long LL;
LL ans1,ans2;
LL f[1005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bool ok=0;
	for(int i=2;i<n;i++) if(a[i]&a[i+1]) ok=1;
	if(ok){
		memset(f,0x3f,sizeof f);
		for(int i=2;i<=n;i++) if(a[i]) f[i]=1;
		for(int k=1;k<=n;k++){
			for(int i=n;i>=2;i--) f[i]=min(f[i],f[i+1]+f[i+2]);
			for(int i=2;i<=n;i++) f[i]=min(f[i],f[i-1]+f[i-2]);
		}
		for(int i=2;i<=n;i+=2) ans2+=f[i];
	}else{
		for(int i=2;i<=n;i+=2){
			if(a[i]) ans2++;else ans1++;
		}
	}
	printf("%lld\n%lld\n",ans1,ans2);
	
	return 0;
}
