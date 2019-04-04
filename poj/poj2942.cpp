#include<iostream>
#include<cstdio>
#include<cstring>
//by zrt
//problem:
//ps.想了一上午 
using namespace std;
int n,m,x,y;
int H[1505],P[1500005],X[1500005],tot;
inline void add(int x,int y){
	P[++tot]=y,X[tot]=H[x],H[x]=tot;
}
bool map[1505][1505];
int dfn[1505],tim,low[1505];
int stk[1500005],top;
int cnt,siz[1005];
int cc[1505][1505];
void tarjan(int u,int fa){
	dfn[u]=low[u]=++tim;
	for(int i=H[u];i;i=X[i]){
		if(i==fa) continue;
		int v=P[i];
		if(!dfn[v]){
			stk[top++]=i;
			tarjan(v,i^1);
			low[u]=min(low[v],low[u]);
			if(low[v]>=dfn[u]){
				cnt++;
				cc[cnt][++siz[cnt]]=u;
				int k;
				do{
					k=stk[--top];
					cc[cnt][++siz[cnt]]=P[k];
				}while(k!=i);
			}
		}else low[u]=min(low[u],dfn[v]);
	}
//	if(low[u]==dfn[u]) top--; 
}
int belong[1005];
int color[1005];
bool isok[1005];
bool dfs(int u){
	int to=3-color[u];
	for(int i=H[u];i;i=X[i]){
		int v=P[i];
		if(belong[v]!=belong[u]) continue;
		if(!color[v]){
			color[v]=to;
			if(dfs(v)) return true;
		}else if(color[v]!=to) return true;
	}
	return false;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d",&n,&m)==2&&n){
		memset(belong,0,sizeof belong);
		memset(isok,0,sizeof isok);
		memset(H,0,sizeof H);tot=1;
		memset(map,0,sizeof map);
		memset(dfn,0,sizeof dfn);tim=0;
		memset(siz,0,sizeof siz); 
		cnt=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			map[x][y]=map[y][x]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(!map[i][j]) {
					add(i,j);add(j,i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				tarjan(i,0);
				if(top>0){
					cnt++;
					cc[cnt][++siz[cnt]]=i;
					while(top>0){
						cc[cnt][++siz[cnt]]=P[stk[--top]];
					}
				}
				top=0;
			}
		}
		for(int i=1;i<=cnt;i++){
			if(siz[i]>=3){
				for(int j=1;j<=siz[i];j++){
					color[cc[i][j]]=0;
					belong[cc[i][j]]=i;
				}
				color[cc[i][1]]=1;
				if(dfs(cc[i][1])){
					for(int j=1;j<=siz[i];j++){
						isok[cc[i][j]]=1;
					}
				}
			}
		}
		int tot=0;
		for(int i=1;i<=n;i++){
			if(!isok[i]){
				tot++;
			}
		}
		printf("%d\n",tot);
	}
	return 0;
}
