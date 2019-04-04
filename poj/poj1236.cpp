#include<iostream>
#include<cstdio>
#include<vector>
//by zrt
//problem:
using namespace std;
vector<int> v[105],vv[105];
int n,x,y,z,in[105],out[105];
bool instack[105],mp[105][105];
int tim,cnt,point[105],dfn[105],low[105],stk[105],top;
void tarjan(int u){
	low[u]=dfn[u]=++tim;
	instack[u]=1;stk[top++]=u;
	for(int i=0;i<v[u].size();i++){
		if(!dfn[v[u][i]]){
			tarjan(v[u][i]);
			low[u]=min(low[u],low[v[u][i]]);
		}else if(instack[v[u][i]]) low[u]=min(low[u],dfn[v[u][i]]);
	}
	if(dfn[u]==low[u]){
		int k;
		cnt++;
		do{
			k=stk[--top];
			instack[k]=0;
			point[k]=cnt;
		}while(k!=u);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	while(scanf("%d",&x)==1&&x){
		v[i].push_back(x);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) for(int j=0;j<v[i].size();j++){
		if((point[i]!=point[v[i][j]])&&(!mp[point[i]][point[v[i][j]]])){
			mp[point[i]][point[v[i][j]]]=1;
			in[point[v[i][j]]]++;out[point[i]]++;
		}
	}
	int ans=0,anss=0;
	for(int i=1;i<=cnt;i++){
		if(!in[i]) ans++;if(!out[i]) anss++;
	}
	if(cnt==1){
		printf("1\n0");return 0;
	}
	printf("%d\n",ans);
	
	printf("%d",max(ans,anss));
	return 0;
}
