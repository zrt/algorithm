#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int a[2005],b[2005],c[2005];
int f[2005][2005];
// f[i][j]=min f[i-1][k] (k<=j) + abs(c[j]-a[i])
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	b[0]=-1;
	sort(b+1,b+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]!=b[i-1]){
			c[++cnt]=b[i];
		}
	}
	m=cnt;// 1...m
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		f[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=f[i-1][j]+abs(c[j]-a[i]);
		}
		for(int j=1;j<=m;j++){
			f[i][j]=min(f[i][j],f[i][j-1]);
		}
	}
	printf("%d\n",f[n][m]);
	return 0;
}