#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int m,n;
int a[305],b[305];
int f[305][305];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),a[i]+=a[i-1],b[i]+=b[i-1];
	memset(f,0x3f,sizeof f);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i]-a[i-j]>m||b[i]-b[i-j]>m) break;
			if(i==j){
				f[i][j]=f[0][0]+2;
				continue;
			}
			for(int k=i-j;k>=1;k--){
				// fij --> f[i-j][k]
				f[i][j]=min(f[i][j],f[i-j][k]+2);
				if(b[i-j]-b[i-j-k]+a[i]-a[i-j]<=m){
					f[i][j]=min(f[i][j],f[i-j][k]+1);
				}
			}
		}
	}
	int minn=inf;
	for(int i=1;i<=n;i++) minn=min(minn,f[n][i]);
	printf("%d\n",minn);
	return 0;
}
