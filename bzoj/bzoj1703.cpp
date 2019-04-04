#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,m;
int H[1005],X[10005],P[10005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool calc[1005][1005];
bool vis[1005];
void dfs(int x,int y){
	vis[x]=1;
	calc[x][y]=1;
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			dfs(P[i],y);
		}
	}
}
int ans=0;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		dfs(i,i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!calc[i][j]&&!calc[j][i]) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
