/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,q,fa[1005][11],st[1005][11],log,dep[1005];
int H[1005],P[2005],X[2005],E[2005],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
void dfs(int x){
	for(int i=H[x];i;i=X[i]){
		if(!dep[P[i]]){
			dep[P[i]]=dep[x]+1;
			fa[P[i]][0]=x;
			st[P[i]][0]=E[i];
			dfs(P[i]);
		}
	}
}
int ask(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int ret=0;
	for(int i=log;i>=0;i--){
		if(1<<i<=dep[x]-dep[y]){
			ret+=st[x][i];
			x=fa[x][i];
		}
	}
	if(x==y) return ret;
	for(int i=log;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			ret+=st[x][i]+st[y][i];
			x=fa[x][i];y=fa[y][i];
		}
	}
	return ret+st[x][0]+st[y][0];
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&q);
	int x,y,z;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(log=0;1<<log<=n;log++);log--;
	dep[1]=1;
	dfs(1);
	for(int i=1;i<=log;i++){
		for(int j=1;j<=n;j++){
			if(1<<i<=dep[j]){
				fa[j][i]=fa[fa[j][i-1]][i-1];
				st[j][i]=st[j][i-1]+st[fa[j][i-1]][i-1];
			}
		}
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",ask(x,y));
	}
	return 0;
}
