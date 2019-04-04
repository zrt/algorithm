#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int f[3005][3005];
int son[3005][3005],num[3005],x,y,w[3005][3005];
int siz[3005];
void dp(int x){
	f[x][0]=0;
	for(int i=1;i<=num[x];i++){
		int v=son[x][i];
		dp(v);
		siz[x]+=siz[v];
		for(int j=siz[x];j>0;j--){
			for(int k=1;k<=min(siz[v],j);k++){
				f[x][j]=max(f[x][j],f[x][j-k]+f[v][k]-w[x][i]);
			}
		}
	}
	
}
int main(){
	memset(f,0xe3,sizeof f);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-m;i++){
		int x,y;
		scanf("%d",&num[i]);
		for(int j=1;j<=num[i];j++){
			scanf("%d%d",&x,&y);son[i][j]=x;w[i][j]=y;
		}
	}
	for(int i=n-m+1;i<=n;i++){
		siz[i]=1;
		scanf("%d",&f[i][1]);
	}
	dp(1);
	for(int i=m;i>=0;i--){
		if(f[1][i]>=0){
			printf("%d\n",i);break;
		}
	}
	return 0;
}