#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,Q;
typedef long long LL;
int v[100005];LL w[100005];
int H[100005],X[200005],P[200005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int belong[100005];
struct N{
	int x,y,t,id;
	friend bool operator < (const N&a,const N&b){
		if(belong[a.x]!=belong[b.x]) return belong[a.x]<belong[b.x];
		if(belong[a.y]!=belong[b.y]) return belong[a.y]<belong[b.y];
		return a.t<b.t;
	}
}q[100005];
int SIZE;
int dep[100005],fa[100005][25],dfn[100005],tim,stk[100005],top;
int cnt;
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	dfn[x]=++tim;
	int bottom=top;
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa[x][0]) continue;
		fa[P[i]][0]=x;
		dfs(P[i]);
		if(top-bottom>=SIZE){
			cnt++;
			while(top>bottom) belong[stk[--top]]=cnt;
		}
	}
	stk[top++]=x;
}
int a[100005],b[100005],pre[100005];
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];y=fa[y][i];
		}
	}
	return fa[x][0];
}
bool s[100005];
int c[100005];
int col[100005];
LL ans[100005],Ans;
void upd(int x,int t){
	if(!t) t=-1;
	Ans-=v[col[x]]*1LL*w[c[col[x]]];
	c[col[x]]+=t;
	Ans+=v[col[x]]*1LL*w[c[col[x]]];
}
void timeup(int T){
	if(!s[a[T]]){
		col[a[T]]=b[T];
	}else{
		upd(a[T],0);
		col[a[T]]=b[T];
		upd(a[T],1);
	}
}
void timedown(int T){
	if(!s[a[T]]){
		col[a[T]]=pre[T];
	}else{
		upd(a[T],0);
		col[a[T]]=pre[T];
		upd(a[T],1);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	SIZE=pow((double)n,0.666666666666666666666)+1;
	for(int i=1;i<=m;i++) scanf("%d",&v[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) w[i]+=w[i-1];
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++) scanf("%d",&col[i]);
	dfs(1);
	while(top>0) belong[stk[--top]]=cnt;
	for(int j=0;j<=20;j++){
		for(int i=1;i<=n;i++) fa[i][j+1]=fa[fa[i][j]][j];
	}
	tim=0;
	int _=0;
	for(int i=1,type;i<=Q;i++){
		scanf("%d",&type);
		if(type&1){
			_++;
			scanf("%d%d",&q[_].x,&q[_].y);
			if(dfn[q[_].x]>dfn[q[_].y]) swap(q[_].x,q[_].y); 
			q[_].id=_;
			q[_].t=tim;
		}else{
			tim++;
			scanf("%d%d",&a[tim],&b[tim]);
			pre[tim]=col[a[tim]];
			col[a[tim]]=b[tim];
		}
	}
	sort(q+1,q+_+1);
	int x=1,y=1,t=tim;
	for(int i=1;i<=_;i++){
		int px=lca(q[i].x,x);
		int py=lca(q[i].y,y);
		while(x!=px){
			upd(x,s[x]^=1);
			x=fa[x][0];
		}
		x=q[i].x;
		while(x!=px){
			upd(x,s[x]^=1);
			x=fa[x][0];
		}
		while(y!=py){
			upd(y,s[y]^=1);
			y=fa[y][0];
		}
		y=q[i].y;
		while(y!=py){
			upd(y,s[y]^=1);
			y=fa[y][0];
		}
		while(t<q[i].t){
			timeup(t+1);
			t++;
		}
		while(t>q[i].t){
			timedown(t);
			t--;
		}
		int pp=lca(q[i].x,q[i].y);
		upd(pp,s[pp]^=1);
		ans[q[i].id]=Ans;
		upd(pp,s[pp]^=1);
		x=q[i].x;y=q[i].y;
	}
	for(int i=1;i<=_;i++)  printf("%lld\n",ans[i]);
	return 0;
}

/*

4 3 5
1 9 2
7 6 5 1
2 3
3 1
3 4
1 2 3 2
1 1 2
1 4 2
0 2 1
1 1 2
1 4 2

*/
