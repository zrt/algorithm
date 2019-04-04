#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[300005];
int H[300005],X[600005],P[600005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int fa[300005][25];
int dep[300005];
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa[x][0]) continue;
		fa[P[i]][0]=x;
		dfs(P[i]);
	}
}
int sum[300005];
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=23;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=23;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];y=fa[y][i];
		}
	}
	return fa[x][0];
}
void solve(int x,int y){
	int z=lca(x,y);
	//printf("%d %d %d\n",x,y,z);
	sum[z]--;sum[fa[z][0]]--;
	sum[x]++;sum[fa[y][0]]++;
	//sum[y]++;
}
void dfs2(int x){
	for(int i=H[x];i;i=X[i]){
		if(fa[x][0]!=P[i]){
			dfs2(P[i]);
			sum[x]+=sum[P[i]];
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1);
	for(int j=0;j<=23;j++){
		for(int i=1;i<=n;i++){
			fa[i][j+1]=fa[fa[i][j]][j];
		}
	}
	for(int i=1;i<n;i++){
		solve(a[i],a[i+1]);
	}
	//for(int i=1;i<=n;i++) printf("%d\n",sum[i]);
		//puts("HHHH");
	dfs2(1);
	for(int i=1;i<=n;i++) printf("%d\n",sum[i]);
	return 0;
}
