#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int a[50005];
int H[50005],X[100005],P[100005],tot;
int root;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int fa[50005][25];
int dep[50005];
int stk[50005],top;
int belong[50005];
int SIZE;
int cnt;
int dfn[50005],tim;
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	dfn[x]=++tim;
	int bottom=top;
	for(int i=H[x];i;i=X[i]){
		if(fa[x][0]==P[i]) continue;
		fa[P[i]][0]=x;
		dfs(P[i]);
		if(top-bottom>=SIZE){
			cnt++;
			while(top>bottom) belong[stk[--top]]=cnt;
		}
	}
	stk[top++]=x;
}
struct N{
	int u,v,a,b,id;
	friend bool operator < (const N&a,const N&b){
		if(belong[a.u]!=belong[b.u]) return belong[a.u]<belong[b.u];
		return dfn[a.v]<dfn[b.v];
	}
}q[100005];
bool v[100005];
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int ans[100005];
int Ans;
int c[50005];
void upd(int x,int t){
//	printf("%d\n",x);
//	printf("# %d %d\n",a[x],Ans);
	if(!t) t=-1;
	if(c[a[x]]) Ans--;
	c[a[x]]+=t;
	if(c[a[x]]) Ans++;
}
int ask(int x){
	if(q[x].a==q[x].b) return Ans;
	if(c[q[x].a]&&c[q[x].b]) return Ans-1;
	else return Ans;
}
int main(){
	scanf("%d%d",&n,&m);SIZE=sqrt(n+1.0);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(x==0||y==0) continue;
		add(x,y);add(y,x);
	}
	dfs(1);
	while(top>0) belong[stk[--top]]=cnt;
//	for(int i=1;i<=n;i++) printf("%d\n",belong[i]);
	for(int j=0;j<=20;j++){
		for(int i=1;i<=n;i++) fa[i][j+1]=fa[fa[i][j]][j];
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&q[i].u,&q[i].v,&q[i].a,&q[i].b);
		if(dfn[q[i].u]>dfn[q[i].v]) swap(q[i].u,q[i].v);
		q[i].id=i;
	}
	sort(q+1,q+m+1);
	int x=1,y=1;
	for(int i=1;i<=m;i++){
	//	printf("%d %d\n",x,y);
		int px=lca(q[i].u,x);
		int py=lca(q[i].v,y);
		while(x!=px){
			upd(x,v[x]^=1);
			x=fa[x][0];
		}
		x=q[i].u;
		while(x!=px){
			upd(x,v[x]^=1);
			x=fa[x][0];
		}
		while(y!=py){
			upd(y,v[y]^=1);
			y=fa[y][0];
		}
		y=q[i].v;
		while(y!=py){
			upd(y,v[y]^=1);
			y=fa[y][0];
		}
		int tmp=lca(q[i].u,q[i].v);
		upd(tmp,v[tmp]^=1);
		ans[q[i].id]=ask(i);
		upd(tmp,v[tmp]^=1);
		x=q[i].u,y=q[i].v;
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
