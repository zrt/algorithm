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
const int MAXN=3000000;
char val[MAXN];
int ls[MAXN],rs[MAXN],fa[MAXN],root,siz[MAXN];
inline void push_up(int x){
	if(!x) return;
	siz[x]=1;
	if(ls[x]) siz[x]+=siz[ls[x]];
	if(rs[x]) siz[x]+=siz[rs[x]];
}

inline void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[rs[x]]=y;else ls[y]=0;
	fa[x]=fa[y];
	if(fa[x]){
		if(ls[fa[x]]==y) ls[fa[x]]=x;else rs[fa[x]]=x;
	}
	fa[y]=x;rs[x]=y;
	push_up(y);push_up(x);
}
inline void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;else rs[y]=0;
	fa[x]=fa[y];
	if(fa[x]){
		if(ls[fa[x]]==y) ls[fa[x]]=x;else rs[fa[x]]=x;
	}
	fa[y]=x;ls[x]=y;
	push_up(y);push_up(x);
}
inline void splay(int x,int z){
	while(fa[x]!=z){
		int y=fa[x];
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
inline int Select(int pos){
	pos++;
	int o=root;
	while(siz[ls[o]]+1!=pos){
		if(siz[ls[o]]>=pos) o=ls[o];
		else pos-=siz[ls[o]]+1,o=rs[o];
	}
	return o;
}
int cc;
char s[MAXN],opt[15];
int mk(int l,int r){
	if(l>r) return 0;
	if(l==r){
		val[++cc]=s[l];
		push_up(cc);
		return cc;
	}else{
		int mid=(l+r)>>1;
		int now=++cc;
		val[now]=s[mid];
		ls[now]=mk(l,mid-1);
		rs[now]=mk(mid+1,r);
		if(ls[now]) fa[ls[now]]=now;
		if(rs[now]) fa[rs[now]]=now;
		push_up(now);
		return now;
	}
}
int n,now;
void dfs(int x){
	if(ls[x]) dfs(ls[x]);
	printf("%c",val[x]);
	if(rs[x]) dfs(rs[x]);
}
void dfs_print(int x){
	if(ls[x]) dfs_print(ls[x]);
	printf("%c",val[x]);
	if(rs[x]) dfs(rs[x]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	root=mk(1,2);
	scanf("%d",&n);
	now=0;
	while(n--){
		scanf("%s",opt);
		if(opt[0]=='M'){
			int k;
			scanf("%d",&k);
			now=k;
		}else if(opt[0]=='I'){
			int l;
			scanf("%d",&l);getchar();
			int L=1;
			while(L<=l){
				fgets(s+L,MAXN,stdin);
				L=strlen(s+L)+L-1;
			}
			int a=Select(now);
			int b=Select(now+1);
			splay(a,0);
			splay(b,a);
			int c=mk(1,l);
			ls[b]=c;fa[c]=b;
			push_up(b);
			splay(c,0);
		}else if(opt[0]=='D'){
			int l;
			scanf("%d",&l);
			int a=Select(now);
			int b=Select(now+l+1);
			splay(a,0);
			splay(b,a);
			ls[b]=0;
			push_up(b);
			splay(b,0);
		}else if(opt[0]=='G'){
			int x;
			scanf("%d",&x);
			int a=Select(now);
			int b=Select(now+x+1);
			splay(a,0),splay(b,a);
			dfs_print(ls[b]);
			puts("");
			splay(ls[b],0);
		}else if(opt[0]=='P'){
			now--;
		}else if(opt[0]=='N'){
			now++;
		}
	}
	return 0;
}
