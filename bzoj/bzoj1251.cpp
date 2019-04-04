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
const int MAXN=55000;
int num[MAXN],ls[MAXN],rs[MAXN],fa[MAXN],Max[MAXN],val[MAXN],add[MAXN],root;
bool rev[MAXN];
void push_up(int x){
	num[x]=1;Max[x]=val[x];
	if(ls[x]){
		num[x]+=num[ls[x]];
		Max[x]=max(Max[x],Max[ls[x]]);
	}
	if(rs[x]){
		num[x]+=num[rs[x]];
		Max[x]=max(Max[x],Max[rs[x]]);
	}
	return;
}
void push_down(int x){
	if(add[x]){
		if(ls[x]){
			Max[ls[x]]+=add[x];
			val[ls[x]]+=add[x];
			add[ls[x]]+=add[x];
		}
		if(rs[x]){
			Max[rs[x]]+=add[x];
			val[rs[x]]+=add[x];
			add[rs[x]]+=add[x];
		}
		add[x]=0;
	}
	if(rev[x]){
		swap(ls[x],rs[x]);
		if(ls[x]) rev[ls[x]]^=1;
		if(rs[x]) rev[rs[x]]^=1;
		rev[x]=0;
	}
	return;
}
void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[rs[x]]=y;else ls[y]=0;
	fa[x]=fa[y];
	if(fa[y]){
		if(ls[fa[y]]==y) ls[fa[y]]=x;else rs[fa[y]]=x;
	}
	fa[y]=x;rs[x]=y;
	push_up(y);push_up(x);
}
void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;else rs[y]=0;
	fa[x]=fa[y];
	if(fa[y]){
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
int Select(int pos){
	pos++;
	int o=root;
	push_down(o);
	while(num[ls[o]]+1!=pos){
		if(num[ls[o]]>=pos) o=ls[o];
		else pos-=num[ls[o]]+1,o=rs[o];
		push_down(o);
	}
	return o;
}
int n,m,k,x,y,z;
int mk(int l,int r){
	if(l>r) return 0;
	if(l==r){
		push_up(l);
		return l;
	}
	int mid=(l+r)>>1;
	ls[mid]=mk(l,mid-1);
	rs[mid]=mk(mid+1,r);
	if(ls[mid]) fa[ls[mid]]=mid;
	if(rs[mid]) fa[rs[mid]]=mid;
	push_up(mid);
	return mid;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	root=mk(1,n+2);
	while(m--){
		scanf("%d",&k);
		if(k==1){
			scanf("%d%d%d",&x,&y,&z);
			int a=Select(x-1),b=Select(y+1);
			splay(a,0);splay(b,a);
			int c=ls[b];
			Max[c]+=z;
			add[c]+=z;
			val[c]+=z;
			splay(c,0);
		}else if(k==2){
			scanf("%d%d",&x,&y);
			int a=Select(x-1),b=Select(y+1);
			splay(a,0);splay(b,a);
			int c=ls[b];
			rev[c]^=1;
			splay(c,0);
		}else{
			scanf("%d%d",&x,&y);
			int a=Select(x-1),b=Select(y+1);
			splay(a,0);splay(b,a);
			int c=ls[b];
			printf("%d\n",Max[c]);
			splay(c,0);
		}
	}
	return 0;
}
