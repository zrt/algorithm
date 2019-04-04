#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int H[200005],X[400005],P[400005],tot,E[400005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
LL mx[200005],pos[200005];
bool vis[200005];
int fa[200005];
int lis[200005],t;
void dfs(int x){
	mx[x]=0;pos[x]=x;
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa[x]) continue;
		fa[P[i]]=x;
		dfs(P[i]);
		if(mx[P[i]]+E[i]>mx[x]){
			mx[x]=mx[P[i]]+E[i];
			pos[x]=pos[P[i]];
		}
	}
}
LL dfs2(int x,int fa){
	LL mx=0;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa&&!vis[P[i]]){
			LL t=dfs2(P[i],x);
			mx=max(t+E[i],mx);
		}
	}
	return mx;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y,z;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	dfs(1);
	int root=pos[1];
	fa[root]=0;
	dfs(root);
	int ed=pos[root];
	while(ed) vis[ed]=1,lis[t++]=ed,ed=fa[ed];
	LL ans=mx[root];
	int l=0,r=t-1;
	for(int i=0;i<t;i++){
		int tmp=dfs2(lis[i],0);
		if(tmp==mx[lis[i]]) l=max(l,i);
		if(tmp==ans-mx[lis[i]]) r=min(r,i);
	}
	printf("%lld\n%d\n",ans,r-l);
	return 0;
}
