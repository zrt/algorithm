#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL f[1000005];
int mindiv[1000005],p[1000000],tot;
int t[1000005];
int n;
int main(){
	scanf("%d",&n);
	f[1]=1;
	for(int i=2;i<=n;i++){
		if(!mindiv[i]){
			mindiv[i]=i;p[tot++]=i;f[i]=2;t[i]=1;
		}
		for(int j=0;p[j]*i<=n;j++){
			mindiv[p[j]*i]=p[j];
			t[p[j]*i]=1;
			if(mindiv[i]==p[j]){
				t[p[j]*i]=t[i]+1;
				f[p[j]*i]=f[i]/(t[i]+1)*(t[i]+2);
				break;
			}
			f[p[j]*i]=2*f[i];
		}
	}
	LL ans=0;
	for(int i=1;i<=n;i++) ans+=f[i];
	printf("%lld\n",ans);
	return 0;
}
