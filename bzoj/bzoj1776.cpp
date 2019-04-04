#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,k,root;
int H[200005],X[200005],P[200005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int fa[200005][19],log;
int belong[200005];
vector<int> v[100005];
int dfn[200005];
int dep[200005];
int tim;
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	dfn[x]=++tim;
	for(int i=H[x];i;i=X[i]){
		dfs(P[i]);
	}
}
int q[200005];
int cc;
int stk[200005];
int top;
int dp[200005];
bool cmp(int a,int b){
	return dfn[a]<dfn[b];
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int i;
	for(i=log;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	}
	if(x==y) return x;
	for(i=log;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
bool mark[200005];
int lc[200005];
int main(){
	#ifdef LOCAL
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&belong[i],&fa[i][0]);
		if(!fa[i][0]) root=i;
		else add(fa[i][0],i);
		v[belong[i]].push_back(i);
	}
	for(log=0;(1<<log)<=n;log++); log--;
	for(int i=1;i<=log;i++){
		for(int j=1;j<=n;j++){
			if(fa[j][i-1]){
				fa[j][i]=fa[fa[j][i-1]][i-1];
			}
		}
	}
	dfs(root);
//	memset(dp,128,sizeof dp);
//	minn=dp[0];
	
	for(int now=1;now<=k;now++){
//		puts("HAHAHAHAHA");
		top=0;cc=0;
		for(int j=0;j<v[now].size();j++){
			mark[v[now][j]]=1;
			q[cc++]=v[now][j];
		}
		sort(q,q+cc,cmp);
		int ans=0;
		stk[top++]=q[0];
		dp[0]=0;
		for(int i=1;i<cc;i++){
//			puts("#debug");
///			for(int i=0;i<top;i++) printf("%d ",stk[i]);
//			puts("");
//			for(int i=0;i<top;i++) printf("%d ",dp[i]);
//			puts("");
			if(top==1){
				stk[top++]=q[i];
				lc[top-1]=lca(stk[top-2],stk[top-1]);
				dp[top-1]=0;
			}else{
				int now=lca(q[i],stk[top-1]);
				if(dep[now]<=dep[lc[top-1]]){
					ans=max(ans,dp[top-1]+dep[stk[top-1]]-dep[lc[top-1]]*2+dp[top-2]+dep[stk[top-2]]);
					dp[top-2]+=dep[stk[top-2]]-dep[lc[top-1]];
					dp[top-2]=max(dp[top-2],dp[top-1]+dep[stk[top-1]]-dep[lc[top-1]]);
					stk[top-2]=lc[top-1];
					top--;
					i--;
					continue;
				}else{
					stk[top++]=q[i];
					lc[top-1]=lca(stk[top-2],stk[top-1]);
					dp[top-1]=0;
				}
			}
		}
//		puts("#debug");
//			for(int i=0;i<top;i++) printf("%d ",stk[i]);
//			puts("");
//			for(int i=0;i<top;i++) printf("%d ",dp[i]);
//			puts("");
		while(top>1){
//			puts("#debug");
//			for(int i=0;i<top;i++) printf("%d ",stk[i]);
//			puts("");
//			for(int i=0;i<top;i++) printf("%d ",dp[i]);
//			puts("");
			ans=max(ans,dp[top-1]+dep[stk[top-1]]-dep[lc[top-1]]*2+dp[top-2]+dep[stk[top-2]]);
			dp[top-2]+=dep[stk[top-2]]-dep[lc[top-1]];
			dp[top-2]=max(dp[top-2],dp[top-1]+dep[stk[top-1]]-dep[lc[top-1]]);
			stk[top-2]=lc[top-1];
			top--;
		}
//		puts("#debug");
//			for(int i=0;i<top;i++) printf("%d ",stk[i]);
//			puts("");
//			for(int i=0;i<top;i++) printf("%d ",dp[i]);
//			puts("");
		ans=max(ans,dp[0]);
		for(int i=0;i<cc;i++) mark[q[i]]=0;
		printf("%d\n",ans);
	}
	
	return 0;
}
