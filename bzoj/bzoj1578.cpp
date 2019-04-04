#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int f[500005];
int s,d,m;
int a[55][56];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&s,&d,&m);
	for(int i=1;i<=s;i++){
		for(int j=1;j<=d;j++){
			scanf("%d",&a[j][i]);
		}
	}
	int ans=m;
	for(int i=2;i<=d;i++){
		for(int j=0;j<=ans;j++) f[j]=j;
		for(int j=1;j<=s;j++){
			if(a[i][j]<=a[i-1][j]) continue;
			for(int k=a[i-1][j];k<=ans;k++){
				f[k]=max(f[k],f[k-a[i-1][j]]+a[i][j]);
			}
		}
		for(int i=ans;i>=0;i--) ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	
	return 0;
}
