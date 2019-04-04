#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int lastans;
int H[80005],X[160005],P[160005],tot;
int to[80005],cc;
int ls[10000500],rs[10000500],sum[10000500],num;
int stk[10000500],top;
int getnew(){
	if(top>0){
		ls[stk[top-1]]=rs[stk[top-1]]=sum[stk[top-1]]=0;
		return stk[--top];
	}
	return ++num;
}
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int f[80005],siz[80005];
int w[80005];
bool vis[80005];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int tt;
int fa[80005][21],rt[80005];
int dep[80005];
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
int insert(int o,int l,int r,int pos){
	int p=getnew();
	sum[p]=sum[o]+1;
	if(l==r) return p;
	int mid=(l+r)>>1;
	if(pos<=mid) ls[p]=insert(ls[o],l,mid,pos),rs[p]=rs[o];
	else rs[p]=insert(rs[o],mid+1,r,pos),ls[p]=ls[o];
	return p;
}
void dfs(int x){
	rt[x]=insert(rt[fa[x][0]],1,80000,w[x]);
	vis[x]=1;
	siz[x]=1;dep[x]=dep[fa[x][0]]+1;
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			fa[P[i]][0]=x;f[P[i]]=x;
			dfs(P[i]);
			siz[x]+=siz[P[i]];
		}
	}
}
char s[10];
int x,y,k;
int ask(int o1,int o2,int o3,int o4,int l,int r,int k){
	if(l==r) return l;
	int sl=sum[ls[o1]]+sum[ls[o2]]-sum[ls[o3]]-sum[ls[o4]];
//	printf("%d %d %d\n",l,r,sl);
	int mid=(l+r)>>1;
	if(k<=sl) return ask(ls[o1],ls[o2],ls[o3],ls[o4],l,mid,k);
	else return ask(rs[o1],rs[o2],rs[o3],rs[o4],mid+1,r,k-sl);
}
void ask(int x,int y,int k){
	int z=lca(x,y);
//	printf("%d\n",k);
	lastans=to[ask(rt[x],rt[y],rt[z],rt[fa[z][0]],1,80000,k)];
	return;
}
int list[80005],t;
void del(int x,int f){
	list[t++]=x;
	fa[x][0]=f;
	stk[top++]=rt[x];
	rt[x]=0;dep[x]=0;
	for(int i=H[x];i;i=X[i]){
		if(f!=P[i]){
			del(P[i],x);
		}
	}
}
void mk(int x,int fa){
	rt[x]=insert(rt[fa],1,80000,w[x]);
	dep[x]=dep[fa]+1;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa) mk(P[i],x);
	}
}
void link(int x,int y){
	if(siz[get(x)]<siz[get(y)]) swap(x,y);
	// x <-- y
	t=0;int yy=get(y);siz[get(x)]+=siz[yy];f[yy]=x;
	del(y,x);
	for(int j=1;j<=20;j++){
		for(int i=0;i<t;i++){
			fa[list[i]][j]=fa[fa[list[i]][j-1]][j-1];
		}
	}
	mk(y,x);
	add(x,y);
	add(y,x);
}
int main(){
	scanf("%*d%d%d%d",&n,&m,&tt);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++) scanf("%d",&w[i]),to[i]=w[i];
	sort(to+1,to+n+1);
	cc=unique(to+1,to+n+1)-(to+1);
	for(int i=1;i<=n;i++) w[i]=lower_bound(to+1,to+cc+1,w[i])-to;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i);
	}
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	while(tt--){
		scanf("%s%d%d",s,&x,&y);
		x^=lastans;y^=lastans;
		if(s[0]=='Q'){
			scanf("%d",&k);
			k^=lastans;
			ask(x,y,k);
			printf("%d\n",lastans);
		}else{
			link(x,y);
		}
	}
	return 0;
}
