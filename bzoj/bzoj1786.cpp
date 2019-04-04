#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
int a[10005];
typedef long long LL;
int bigger[10005][105];
int smaller[10005][105];
LL f[10005][105];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
		for(int j=1;j<=k;j++) bigger[i][j]=bigger[i-1][j]+(a[i-1]>j&&a[i-1]!=-1);
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=k;j++) smaller[i][j]=smaller[i+1][j]+(a[i+1]<j&&a[i+1]!=-1);
	int last=0;LL sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			LL mn=1LL<<60;
			for(int j=1;j<=k;j++){
				mn=min(f[last][j],mn);
				f[i][j]=mn+bigger[i][j]+smaller[i][j];
				//printf("%d %d %lld\n",i,j,f[i][j]);
			}
			last=i;
		}else sum+=bigger[i][a[i]];
	}
	LL ans=1LL<<60;
	for(int i=1;i<=k;i++) ans=min(ans,f[last][i]);
	printf("%lld\n",ans+sum);
	return 0;
}
