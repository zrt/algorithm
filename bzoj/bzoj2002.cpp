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
int n,m;
const int MAXN=200005;
int a[MAXN];
int fa[MAXN],ls[MAXN],rs[MAXN],siz[MAXN];
inline void upd(int x){
	siz[x]=1;
	if(ls[x]) siz[x]+=siz[ls[x]];
	if(rs[x]) siz[x]+=siz[rs[x]];
}
inline void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[rs[x]]=y;else ls[y]=0;
	fa[x]=fa[y];
	if(ls[fa[x]]==y) ls[fa[x]]=x;
	else if(rs[fa[x]]==y) rs[fa[x]]=x;
	fa[y]=x;rs[x]=y;
	upd(y);
}
inline void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;else rs[y]=0;
	fa[x]=fa[y];
	if(ls[fa[x]]==y) ls[fa[x]]=x;
	else if(rs[fa[x]]==y) rs[fa[x]]=x;
	fa[y]=x;ls[x]=y;
	upd(y);
}
inline bool notroot(int x){
	return ls[fa[x]]==x||rs[fa[x]]==x;
}
inline void splay(int x){
	while(notroot(x)){
		int y=fa[x];
		if(notroot(fa[y])){
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
	upd(x);
}
inline void access(int x){
	int y;
	splay(x);
	rs[x]=0;
	while(fa[x]){
		y=fa[x];
		splay(y);
		rs[y]=x;
		upd(y);
		splay(x);
	}
}
inline void cut(int x){
	access(x);
	splay(x);
	fa[ls[x]]=fa[x];
	fa[x]=ls[x];
	ls[x]=0;
	upd(x);
}
inline void link(int x,int y){
	access(x);
	splay(x);
	access(y);
	splay(y);
	rs[y]=x;
	fa[x]=y;
	upd(y);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n+1;i++) upd(i);
	for(int i=1;i<=n;i++){
		if(i+a[i]>n){
			link(i,n+1);
		}else{
			link(i,i+a[i]);
		}
	}
	scanf("%d",&m);
	while(m--){
		int i;
		scanf("%d",&i);
		if(i==1){
			int x;
			scanf("%d",&x);
			x++;
			access(x);
			printf("%d\n",siz[ls[x]]);
		}else{
			int x,y;
			scanf("%d%d",&x,&y);
			x++;
			cut(x);
			a[x]=y;
			if(x+a[x]>n){
				link(x,n+1);
			}else{
				link(x,x+a[x]);
			}
		}
	}
	
	return 0;
}
