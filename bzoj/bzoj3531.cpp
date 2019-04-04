#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q;
const int MAXN=200000*40;
int ls[MAXN],rs[MAXN],mx[MAXN],sum[MAXN],cc;
inline int new_(){
	return ++cc;
}
char s[10];
int rt[100005];
int w[100005],c[100005];
int H[100005],X[200005],P[200005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int dep[100005],fa[100005],top[100005],son[100005],siz[100005],dfn[100005],tim;
void dfs(int x){
	siz[x]=1;int mx=0;
	dep[x]=dep[fa[x]]+1;
	for(int i=H[x];i;i=X[i]){
		if(fa[x]==P[i]) continue;
		fa[P[i]]=x;
		dfs(P[i]);
		if(siz[P[i]]>mx){
			mx=siz[P[i]];
			son[x]=P[i];
		}
		siz[x]+=siz[P[i]];
	}
}
void dfs2(int x){
	dfn[x]=++tim;
	if(!top[x]) top[x]=x;
	if(son[x]) top[son[x]]=top[x],dfs2(son[x]);
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa[x]||P[i]==son[x]) continue;
		dfs2(P[i]);
	}
}
void up(int o){
	mx[o]=max(mx[ls[o]],mx[rs[o]]);
	sum[o]=sum[ls[o]]+sum[rs[o]];
}
void add(int&o,int l,int r,int pos,int val){
	if(!o) o=new_();
	if(l==r){
		mx[o]=sum[o]=val;
	}else{
		int mid=(l+r)>>1;
		if(pos<=mid) add(ls[o],l,mid,pos,val);
		else add(rs[o],mid+1,r,pos,val);
		up(o);
	}
}
int ask(int o,int l,int r,int L,int R,int t){
	if(!o) return 0;
	if(l==L&&r==R){
		if(t) return sum[o];else return mx[o];
	}else{
		int mid=(l+r)>>1;
		if(R<=mid) return ask(ls[o],l,mid,L,R,t);
		else if(L>mid) return ask(rs[o],mid+1,r,L,R,t);
		else{
			if(t) return ask(ls[o],l,mid,L,mid,t)+ask(rs[o],mid+1,r,mid+1,R,t);
			else return max(ask(ls[o],l,mid,L,mid,t),ask(rs[o],mid+1,r,mid+1,R,t));
		}
	}
}
int ask(int x,int y,int tag){//1 sum 0 max
	int ret=0;
	int t=c[x];
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		if(tag) ret+=ask(rt[t],1,n,dfn[top[x]],dfn[x],tag);
		else ret=max(ret,ask(rt[t],1,n,dfn[top[x]],dfn[x],tag));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	if(tag) ret+=ask(rt[t],1,n,dfn[x],dfn[y],tag);
	else ret=max(ret,ask(rt[t],1,n,dfn[x],dfn[y],tag));
	return ret;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&c[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1);dfs2(1);
	for(int i=1;i<=n;i++){
		add(rt[c[i]],1,n,dfn[i],w[i]);
	}
	int x,y;
	while(q--){
		scanf("%s%d%d",s,&x,&y);
		if(s[1]=='C'){
			add(rt[c[x]],1,n,dfn[x],0);
			c[x]=y;
			add(rt[c[x]],1,n,dfn[x],w[x]);
		}else if(s[1]=='W'){
			w[x]=y;
			add(rt[c[x]],1,n,dfn[x],w[x]);
		}else if(s[1]=='S'){
			printf("%d\n",ask(x,y,1));
		}else{
			printf("%d\n",ask(x,y,0));
		}
	}
	return 0;
}
