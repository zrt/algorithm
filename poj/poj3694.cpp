#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int H[100005],P[450505],X[450505],f[100005],p[100005],dep[100005];
bool vis[100005];
int n,m,q,cas,tot,x,y,ans;
void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int get(int x){
	return x==p[x]?x:p[x]=get(p[x]);
}
void unio(int x,int y){
	x=get(x);y=get(y);
	while(x!=y){
		if(dep[x]<dep[y]) swap(x,y);
		int fa=get(f[x]);
		p[x]=fa;
		x=fa;
		ans--;
	}
}
void dfs(int u,int fe){
	vis[u]=1;
	dep[u]=dep[f[u]]+1;
	for(int i=H[u];i;i=X[i]){
		if(fe==i) continue;
		if((!vis[P[i]])&&get(u)!=get(P[i])){
			f[P[i]]=u;
			dfs(P[i],i^1);
		}else{
			unio(u,P[i]);
		}
	}
}
int main(){
//	freopen("out.txt","w",stdout);
//	bool F=1;
	while(scanf("%d%d",&n,&m)==2&&(n||m)){
		
		printf("Case %d:\n",++cas);
		memset(H,0,sizeof H);tot=1;ans=n-1;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++){
			p[i]=i;
		}
		for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
			add(x,y);add(y,x);
		}
		dep[1]=0;
		dfs(1,-1);
		int q;
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			scanf("%d%d",&x,&y);
			unio(x,y);
			printf("%d\n",ans);
		}
		putchar('\n');
	}
	
	return 0;
}
