#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,w;
typedef long long LL;
LL f[40][1010],ans;
int main(){
	while(~scanf("%d%d",&n,&w),~n){
		memset(f,0,sizeof f);
		ans=0;
		for(int i=1,x;i<=n;i++){
			int a=0,b=0;
			scanf("%d%d",&a,&x);
			while(~a&1) a>>=1,++b;
			for(int j=1000;j>=a;j--) f[b][j]=max(f[b][j],f[b][j-a]+x);
		}
		for(int i=0;i<=30;i++){
			for(int j=1;j<=1000;j++){
				f[i][j]=max(f[i][j],f[i][j-1]);
			}
		}
		for(int i=1;i<=min(1000,w);i++) ans=max(ans,f[0][i]);
		for(int i=1;i<=30&&(1<<i)<=w;i++){
			for(int j=min(1000,w>>i);~j;j--){
				for(int k=0;k<=j;k++){
					f[i][j]=max(f[i][j],f[i][j-k]+f[i-1][min(k+k+((w>>i-1)&1),1000)]);  
				}
				ans=max(ans,f[i][j]);
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
