#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt

using namespace std;
typedef long long LL;
int n,m;
int to[100005],cc;
int w[100005];
int H[100005],X[2*100005],P[100005*2],tot;
inline void add(int x,int y){P[++tot]=y;X[tot]=H[x];H[x]=tot;}
int now;
int ls[2000005],rs[2000005],sum[2000005];
int dep[100005];
inline int get(){
	return ++now;
}
int fa[100005][18];
int tree[100005];
int lg;
int insert(int o,int l,int r,int w){
	int p=get();
	if(l==r){
		sum[p]=sum[o]+1;
		return p;
	}
	int mid=(l+r)>>1;
	if(w<=mid){
		sum[p]=sum[o]+1;
		ls[p]=insert(ls[o],l,mid,w);
		rs[p]=rs[o];
	}else{
		sum[p]=sum[o]+1;
		ls[p]=ls[o];
		rs[p]=insert(rs[o],mid+1,r,w);
	}
	return p;
}
void dfs(int x){
	tree[x]=insert(tree[fa[x][0]],1,cc,lower_bound(to+1,to+cc+1,w[x])-to);
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa[x][0]){
			fa[P[i]][0]=x;
			dep[P[i]]=dep[x]+1;
			dfs(P[i]);
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=lg;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=lg;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];y=fa[y][i];
		}
	}
	return fa[x][0];
}
int ask(int u,int v,int p,int lc,int l,int r,int k){
	if(l==r) return l;
	int mid=(l+r)>>1;
	int a=sum[ls[u]]+sum[ls[v]]-sum[ls[p]]-sum[ls[lc]];
	if(a>=k) return ask(ls[u],ls[v],ls[p],ls[lc],l,mid,k);
	else return ask(rs[u],rs[v],rs[p],rs[lc],mid+1,r,k-a);
}
int ask(int u,int v,int k){
	return ask(tree[u],tree[v],tree[fa[lca(u,v)][0]],tree[lca(u,v)],1,cc,k);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(lg=0;(1<<lg)<=n;lg++);lg--;
	for(int i=1;i<=n;i++) scanf("%d",&w[i]),to[++cc]=w[i];
	sort(to+1,to+cc+1);
	cc=unique(to+1,to+cc+1)-(to+1);
	for(int i=1,x,y;i<n;i++){scanf("%d%d",&x,&y);add(x,y);add(y,x);}
	dep[1]=1;
	dfs(1);
	for(int j=0;j<=lg;j++){
		for(int i=1;i<=n;i++){
			if(fa[i][j]){
				fa[i][j+1]=fa[fa[i][j]][j];
			}
		}
	}
	int lastans=0;
	bool f=1;
	while(m--){
		int u,v,k;
		scanf("%d%d%d",&u,&v,&k);
		u^=lastans;
		lastans=to[ask(u,v,k)];
		if(f) f=0;else puts("");
		printf("%d",lastans);
	}
	return 0;
}
