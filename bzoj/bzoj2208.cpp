#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int H[2005],X[4005000],P[4005000],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
char s[2500];
int n;
int ans;
bool vis[2500];
void dfs(int x){
	vis[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]) dfs(P[i]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++){
			if(s[j]=='1') add(i,j);
		}
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		dfs(i);
		for(int j=1;j<=n;j++) if(vis[j]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
