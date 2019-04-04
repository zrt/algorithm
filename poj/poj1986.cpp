#include<cstdio>
#include<cstring>
using namespace std;
int H[40005];const int MAX=100005;int P[MAX],E[MAX],X[MAX],tot;
int n,m;
int anc[40005][20];
int dep[40005];
int w[40005];
bool vis[40005];
int log;
void dfs(int x){
	vis[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(vis[P[i]]) continue;
		dep[P[i]]=dep[x]+1;
		anc[P[i]][0]=x;
		w[P[i]]=E[i]+w[x];
		dfs(P[i]);
	}
}
int ask(int a,int b){
	if(dep[a]<dep[b]) a^=b^=a^=b;
	if(dep[a]>dep[b]){
		for(int i=log;i>=0;i--){
			if(dep[anc[a][i]]>=dep[b]){
				a=anc[a][i];
			}
		}
	}
	if(a==b) return a;
	for(int i=log;i>=0;i--){
		if(anc[a][i]!=anc[b][i]){
			a=anc[a][i];b=anc[b][i];
		}
	}
	return anc[a][0];
}
int main(){
//	freopen("in.txt","r",stdin);
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
        memset(anc,-1,sizeof anc);
	int x,y,z;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%*s",&x,&y,&z);
		P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
		P[++tot]=x;X[tot]=H[y];H[y]=tot;E[tot]=z;
	//	vis[y]=1;
	}
	int root;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			root=i;
			dep[root]=1;
			dfs(root);
			for(log=0;1<<log<=n;log++);log--;
			for(int i=0;i<log;i++){
				for(int j=1;j<=n;j++){
					if(~anc[j][i]) {
						anc[j][i+1]=anc[anc[j][i]][i];
					}
				}
			}
		}
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",w[x]+w[y]-(w[ask(x,y)]<<1));
	}
	return 0;
}