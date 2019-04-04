#include<cstdio>
#include<vector>
using namespace std;
int H[20005],X[200005],P[200005],tot;
bool used[200005];
void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
vector<int> v[20005],son[20005];
bool vis[20005];
int fa[20005];
void dfs(int u){
	vis[u]=1;
	for(int i=H[u];i;i=X[i]){
		if(!vis[P[i]]){
			used[i]=used[i^1]=1;
			son[u].push_back(P[i]);
			fa[P[i]]=u;
			dfs(P[i]);
		}
	}
}
bool dfs2(int u){
	int siz=son[u].size();
	for(int i=0;i<siz;i++){
		if(dfs2(son[u][i])){// not use
			v[u].push_back(son[u][i]);
		}
	}
	siz=v[u].size();
	bool flag=0;
	if(siz&1){
		siz--;
		printf("%d %d %d\n",fa[u],u,v[u][siz]);flag=1;
	}
	for(int i=0;i<siz;i+=2){
		printf("%d %d %d\n",v[u][i],u,v[u][i+1]);
	}
	if(flag) return 0;
	else return 1;
}
int main(){
	int n,m,x,y;tot=1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if(!used[j]){
				used[j]=used[j^1]=1;
				v[i].push_back(P[j]);
			}
		}
	}
	dfs2(1);
	return 0;
}