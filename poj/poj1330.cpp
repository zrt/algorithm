/*
ID: zrtdrea1
PROG:
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<algorithm> 
//by zrt
//problem:
using namespace std;
int H[10005],X[10005],P[10005],tot;
int dep[10005];bool in[10005];
int fa[10005];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int n,x,y;
void dfs(int x){
	for(int i=H[x];i;i=X[i]){
		dep[P[i]]=dep[x]+1;
		fa[P[i]]=x;
		dfs(P[i]);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	while(~scanf("%d",&n)){
		memset(H,0,sizeof H);tot=0;
		memset(in,0,sizeof in);
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,y);in[y]=1;
		}
		int root;
		for(int i=1;i<=n;i++){
			if(!in[i]){
				root=i;break;
			}
		}
		scanf("%d%d",&x,&y);
		dep[root]=1;
		dfs(root);
		if(dep[x]<dep[y]) swap(x,y);
		while(dep[x]>dep[y]) x=fa[x];
		while(x!=y){
			x=fa[x];y=fa[y];
		}
		printf("%d\n",x);
	}
	
	return 0;
}
