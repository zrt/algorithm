#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p,f[160][160],son[160][160],num[160];
bool vis[160];
int x,y;
void dp(int x){
	f[x][1]=num[x];
	for(int i=1;i<=num[x];i++){
		int v=son[x][i];
		dp(v);
		for(int j=p;j>=1;j--){
			for(int k=1;k<j;k++){
				f[x][j]=min(f[x][j],f[x][j-k]+f[v][k]-1);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&p);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		son[x][++num[x]]=y;vis[y]=1;
	}
	int root;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			root=i;
			dp(i);break;
		}
	}
	int minn=0x7fffffff;
	for(int i=1;i<=n;i++){
		if(root==i){
			minn=min(minn,f[i][p]);
		}else{
			minn=min(minn,f[i][p]+1);
		}
	}
	printf("%d",minn);
	return 0;
}