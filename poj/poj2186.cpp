#include<cstdio>
#include<vector>
using namespace std;

vector<int> v[10005];
int n,m,cnt,tim,x,y;
int dfn[10005],low[10005],instack[10005],stk[10005],indegree[10005],siz[10005],top,in[10005],point[10005];
void tj(int u){
	dfn[u]=low[u]= ++tim;
	instack[u]=1;
	stk[top++]=u;
	for(int i=0;i<v[u].size();i++){
		if(!dfn[v[u][i]]){
			tj(v[u][i]);
			low[u]=min(low[u],low[v[u][i]]);
		}else if(instack[v[u][i]]){
			low[u]=min(low[u],dfn[v[u][i]]);
		}
	}
	if(dfn[u]==low[u]){
		cnt++;
		int j;
		do{
			j=stk[top-1];--top;
			instack[j]=0;
			point[j]=cnt;
			siz[cnt]++;
		}while(j!=u);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tj(i);
		}
	}
	int ans=0,tot=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			if(point[i]!=point[v[i][j]]){
				in[point[i]]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(!in[i]){
			ans=siz[i];tot++;
		}
	}
	if(tot>1) ans=0;
	printf("%d",ans);
	return 0;
}