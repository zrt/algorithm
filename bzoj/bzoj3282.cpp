#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=300005;
int ls[MAXN],rs[MAXN],fa[MAXN];
int w[MAXN],s[MAXN];
bool rev[MAXN];
void up(int x){
	s[x]=w[x]^s[ls[x]]^s[rs[x]];
}
void Rev(int x){
	if(!x) return;
	rev[x]^=1;
	swap(ls[x],rs[x]);
}
void down(int x){
	if(rev[x]){
		Rev(ls[x]);Rev(rs[x]);
		rev[x]=0;
	}
}
void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[ls[y]]=y;else ls[y]=0;
	fa[x]=fa[y];
	if(ls[fa[y]]==y) ls[fa[y]]=x;else if(rs[fa[y]]==y) rs[fa[y]]=x;
	rs[x]=y;fa[y]=x;
	up(y);
}
void zag(int x){
	int y=fa[x];
	if(ls[x])  rs[y]=ls[x],fa[rs[y]]=y;else rs[y]=0;
	fa[x]=fa[y];
	if(ls[fa[y]]==y) ls[fa[y]]=x;else if(rs[fa[y]]==y) rs[fa[y]]=x;
	ls[x]=y;fa[y]=x;
	up(y);
}
int lis[MAXN];
bool notroot(int x){
	return ls[fa[x]]==x||rs[fa[x]]==x;
}
void splay(int x){
	int t=0;
	int p=x;
	while(notroot(p)) lis[t++]=p,p=fa[p];
	down(p);for(int i=t-1;i>=0;i--) down(lis[i]);
	while(notroot(x)){
		int y=fa[x];
		if(!notroot(y)){
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
	up(x);
}
void access(int x){
	int y=0;
	while(x){
		splay(x);
		rs[x]=y;
		up(x);
		y=x;
		x=fa[x];
	}
}
void mkroot(int x){
	access(x);
	splay(x);
	Rev(x);
}
void link(int x,int y){
	mkroot(x);
	fa[x]=y;
}
void cut(int x,int y){
	mkroot(x);
	access(y);
	splay(y);
	ls[y]=0;
	fa[x]=0;
	up(y);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]),s[i]=w[i];
	while(m--){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==0){
			mkroot(x);
			access(y);
			splay(y);
			printf("%d\n",s[y]);
		}else if(t==1){
			mkroot(x);
			access(y);
			splay(y);
			int o=y;
			down(o);
			while(ls[o]) o=ls[o],down(o);
			if(o==x){
				continue;
			}else link(x,y);
		}else if(t==2){
			mkroot(x);
			access(y);
			splay(y);
			int o=y;
			down(o);
			while(ls[o]) o=ls[o],down(o);
			if(o==x){
				cut(x,y);
			}else continue;
		}else{
			splay(x);
			w[x]=y;
			up(x);
		}
	}
	return 0;
}
