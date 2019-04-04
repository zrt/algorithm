#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
const int MAXN=100005;
int ls[MAXN],rs[MAXN],fa[MAXN],siz[MAXN],val[MAXN],cc,root;
bool rev[MAXN];
inline void push_up(int x){
	siz[x]=1;
	if(siz[ls[x]]) siz[x]+=siz[ls[x]];
	if(siz[rs[x]]) siz[x]+=siz[rs[x]];
}
inline void push_down(int x){
	if(rev[x]){
		rev[x]=0;
		swap(ls[x],rs[x]);
		rev[ls[x]]^=1;
		rev[rs[x]]^=1;
	}
}
void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[rs[x]]=y;else ls[y]=0;
	fa[x]=fa[y];
	if(fa[x]){
		if(ls[fa[y]]==y) ls[fa[y]]=x;else rs[fa[y]]=x;
	}
	fa[y]=x;rs[x]=y;
	push_up(y);push_up(x);
}
void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;else rs[y]=0;
	fa[x]=fa[y];
	if(fa[x]){
		if(ls[fa[y]]==y) ls[fa[y]]=x;else rs[fa[y]]=x;
	}
	fa[y]=x;ls[x]=y;
	push_up(y);push_up(x);
}
void splay(int x,int z){
	while(fa[x]!=z){
		int y=fa[x];
		if(fa[y]) push_down(fa[y]);
		push_down(y);
		push_down(x);
		if(fa[y]==z){
			if(ls[y]==x) zig(x);else zag(x);
		}else{
			if(ls[fa[y]]==y){
				if(ls[y]==x) zig(y),zig(x);
				else zag(x),zig(x);
			}else{
				if(ls[y]==x) zig(x),zag(x);
				else zag(y),zag(x);
			}
		}
	}
	if(!z) root=x;
}
int mk(int l,int r){
	if(l>r) return 0;
	if(l==r){
		++cc;
		val[cc]=l-1;
		push_up(cc);
		return cc;
	}else{
		int now=++cc;
		int mid=(l+r)>>1;
		val[now]=mid-1;
		ls[now]=mk(l,mid-1);
		rs[now]=mk(mid+1,r);
		if(ls[now]) fa[ls[now]]=now;
		if(rs[now]) fa[rs[now]]=now;
		push_up(now);
		return now;
	}
}
int Select(int pos){
	pos++;
	int o=root;
	push_down(o);
	while(siz[ls[o]]+1!=pos){
		if(siz[ls[o]]>=pos) o=ls[o];
		else pos-=siz[ls[o]]+1,o=rs[o];
		push_down(o);
	}
	return o;
}
int n,m;
void dfs(int x){
	push_down(x);
	if(ls[x]) dfs(ls[x]);
	if(val[x]>=1&&val[x]<=n) printf("%d ",val[x]);
	if(rs[x]) dfs(rs[x]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	root=mk(1,n+2);
	int x,y;
	while(m--){
		scanf("%d%d",&x,&y);
		int a=Select(x-1);
		int b=Select(y+1);
		splay(a,0);splay(b,a);
		rev[ls[b]]^=1;
		splay(ls[b],0);
	}
	dfs(root);
	return 0;
}
