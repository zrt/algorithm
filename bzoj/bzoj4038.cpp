#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int n;
LL a[3005];
LL f[3005][3005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			f[i][j+1]=min(f[i][j+1],f[i-1][j]+(i-1+j)*1LL*a[i]);
			f[i][j]=min(f[i][j],f[i-1][j]+(i-1+j+(n-i)*3)*1LL*a[i]);
		}
	}
	LL ans=~0ULL>>1;
	for(int i=0;i<=n;i++) ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
//	while(1);
	return 0;
}
