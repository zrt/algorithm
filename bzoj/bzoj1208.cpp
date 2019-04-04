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
const int MAXN=80005;
int cc,root;
int fa[MAXN],ls[MAXN],rs[MAXN],val[MAXN],num;
void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[rs[x]]=y;else ls[y]=0;
	fa[x]=fa[y];
	if(ls[fa[y]]==y) ls[fa[y]]=x;else rs[fa[y]]=x;
	rs[x]=y;fa[y]=x;
}
void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;
	else rs[y]=0;
	fa[x]=fa[y];
	if(ls[fa[x]]==y) ls[fa[x]]=x;else rs[fa[x]]=x;
	ls[x]=y;fa[y]=x;
}
void splay(int x,int z){
	while(fa[x]!=z){
		int y=fa[x];
		if(fa[y]==z){
			if(ls[y]==x) zig(x);
			else zag(x);
		}else if(ls[y]==x){
			if(ls[fa[y]]==y) zig(y),zig(x);
			else zig(x),zag(x);
		}else{
			if(ls[fa[y]]==y) zag(x),zig(x);
			else zag(y),zag(x);
		}
	}
	if(!z) root=x;
}
void insert(int x){
	if(!root) {
		root=x;
		return ;
	}
	int f,o=root;
	while(o){
		f=o;
		if(val[x]<val[o]) o=ls[o];
		else o=rs[o];
	}
	if(val[x]<val[f]){
		ls[f]=x;fa[x]=f;
	}else{
		rs[f]=x;fa[x]=f;
	}
}
void Insert(int x){
	val[++cc]=x;
	insert(cc);
	splay(cc,0);
}
int get(int w){
	int o=root;
	while(o){
		if(w==val[o]) return o;
		if(w<val[o]) o=ls[o];
		else o=rs[o];
	}
	return 0;
}

void del(int x){
	splay(x,0);
	if(ls[x]&&rs[x]){
		int f,o=ls[x];
		while(o){
			f=o;
			o=rs[o];
		}
		splay(f,x);
		rs[ls[x]]=rs[x];
		fa[rs[x]]=ls[x];
		if(ls[fa[x]]==x) ls[fa[x]]=ls[x];
		else rs[fa[x]]=ls[x];
		fa[ls[x]]=fa[x];
		if(x==root) root=ls[x];
	}else if(ls[x]){
		if(!fa[x]){
			root=ls[x];
			fa[ls[x]]=0;
		}
		if(ls[fa[x]]==x) ls[fa[x]]=ls[x];
		else rs[fa[x]]=ls[x];
		fa[ls[x]]=fa[x];
	}else{
		if(!fa[x]){
			root=rs[x];
			fa[rs[x]]=0;
		}
		if(ls[fa[x]]==x) ls[fa[x]]=rs[x];
		else rs[fa[x]]=rs[x];
		fa[rs[x]]=fa[x];
	}
	if(x==cc) {
		cc--;
		fa[x]=ls[x]=rs[x]=val[x]=0;
	}
}
int _pre,_nxt;
int get_pre(int w){
	if(get(w)) return w;
	Insert(w);
	int o=ls[root],f;
	f=0;
	int ret;
	if(!o) ret=-inf;
	while(o){
		f=o;
		o=rs[o];
	}
	if(f) ret=val[f],_pre=f;
	del(root);
	return ret;
}
int get_nxt(int w){
	if(get(w)) return w;
	Insert(w);
	int o=rs[root],f;
	f=0;
	int ret;
	if(!o) ret=inf;
	while(o){
		f=o;
		o=ls[o];
	}
	if(f) ret=val[f],_nxt=f;
	del(root);
	return ret;
}
int n,ans;
int a,b;
int mod=1000000;

void solve(int x){
	bool pre=1;
	int tmp=x-get_pre(x),p;
	if((p=get_nxt(x)-x)<tmp){
		tmp=p;pre=0;
	}
	ans=(ans+tmp)%mod;
	if(pre) del(_pre);
	else del(_nxt);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		if(a==0){
			if(num>=0) Insert(b);
			else solve(b);
		}else{
			if(num<=0) Insert(b);
			else solve(b);
		}
		if(!a) num++;
		else num--;
	}
	printf("%d\n",ans);
	return 0;
}
