#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[1005],b[1005],c[1005];
int f[1005][1005],g[1005][1005];
// number from 1
int q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	memset(f,0x80,sizeof f);
	memset(g,0x80,sizeof g);
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=1000;j++) f[i][j]=f[i-1][j];
		int num=c[i];
		int v,w;
		for(int k=1;k<=num;num-=k,k<<=1){
			v=k*a[i],w=k*b[i];
			for(int j=1000;j>=v;j--){
				f[i][j]=max(f[i][j],f[i][j-v]+w);
			}
		}
		if(num){
			int k=num;
			v=k*a[i],w=k*b[i];
			for(int j=1000;j>=v;j--){
				f[i][j]=max(f[i][j],f[i][j-v]+w);
			}
		}
	}
	g[n+1][0]=0;
	for(int i=n;i>=1;i--){
		int num=c[i];
		int v,w;
		for(int j=0;j<=1000;j++) g[i][j]=g[i+1][j];
		for(int k=1;k<=num;num-=k,k<<=1){
			v=k*a[i],w=k*b[i];
			for(int j=1000;j>=v;j--){
				g[i][j]=max(g[i][j],g[i][j-v]+w);
			}
		}
		if(num){
			int k=num;
			v=k*a[i],w=k*b[i];
			for(int j=1000;j>=v;j--){
				g[i][j]=max(g[i][j],g[i][j-v]+w);
			}
		}
	}
	for(int i=0;i<=n;i++) for(int j=1;j<=1000;j++) f[i][j]=max(f[i][j],f[i][j-1]);
	for(int i=1;i<=n+1;i++) for(int j=1;j<=1000;j++) g[i][j]=max(g[i][j],g[i][j-1]);
		
	scanf("%d",&q);
	for(int i=0,d,e;i<q;i++){
		scanf("%d%d",&d,&e);
		int ans=0x80808080;d++;
		for(int j=0;j<=e;j++){
			//if(f[d-1][j]<0||g[d+1][e-j]<0) continue;
			ans=max(ans,f[d-1][j]+g[d+1][e-j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
