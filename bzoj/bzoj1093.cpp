#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
vector<int> v[100005],vv[100005];
int n,m,MOD,x,y;
int tim,dfn[100005],low[100005],stk[100005],top,cnt,siz[100005],belong[100005];
bool instack[100005];
void tarjan(int u){
	dfn[u]=low[u]=++tim;
	stk[top++]=u;instack[u]=1;
	for(int i=0;i<v[u].size();i++){
		if(!dfn[v[u][i]]){
			tarjan(v[u][i]);
			low[u]=min(low[u],low[v[u][i]]);
		}else if(instack[v[u][i]]){
			low[u]=min(low[u],dfn[v[u][i]]);
		}
	}
	if(low[u]==dfn[u]){
		int k;
		++cnt;
		do{
			k=stk[--top];
			instack[k]=0;
			belong[k]=cnt;
			siz[cnt]++;
		}while(k!=u);
	}
}
int in[100005],f[100005],g[100005];
queue<int> q;
bool vis[100005];
int main(){
	scanf("%d%d%d",&n,&m,&MOD);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			if(belong[i]!=belong[v[i][j]]){
				vv[belong[i]].push_back(belong[v[i][j]]);
				in[belong[v[i][j]]]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;i++) {
		g[i]=1;f[i]=siz[i];
		ans=max(ans,siz[i]);
	}
	for(int i=1;i<=cnt;i++){
		if(!in[i]){
			q.push(i);
		}
	}
	for(int i=1;i<=cnt;i++) sort(vv[i].begin(),vv[i].end());
	while(!q.empty()){
		int last=0;
		int k=q.front();q.pop();
		for(int i=0;i<vv[k].size();i++){
			in[vv[k][i]]--;
			if(!in[vv[k][i]]){
				q.push(vv[k][i]);
			}
			if(vv[k][i]==last) continue ;else last=vv[k][i];
			if(f[k]+siz[vv[k][i]]==f[vv[k][i]]){
				g[vv[k][i]]+=g[k];
				g[vv[k][i]]%=MOD;
			}else if(f[k]+siz[vv[k][i]]>f[vv[k][i]]){
				f[vv[k][i]]=f[k]+siz[vv[k][i]];
				if(f[vv[k][i]]>ans) ans=f[vv[k][i]];
				g[vv[k][i]]=g[k]%MOD;
			}
		}
	}
	int tot=0;
	for(int i=1;i<=cnt;i++){
		if(f[i]==ans) {
			tot+=g[i];
			tot%=MOD;
		}
	}
	printf("%d\n%d",ans,tot);
	return 0;
}
/*
3 7 99999999
3 2
1 2
1 3
3 1
2 3
1 3
3 1
*/
