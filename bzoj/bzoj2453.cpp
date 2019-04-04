#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define lowbit(x) ((x)&-(x))
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
set<int> st[20005];
int to[1000005];
int tot;
int n,m;
int a[20005];
int last[20005];
int b[20005];
char s[10];
const int MAXN=10005;
int cc;
int ls[MAXN*100],rs[MAXN*100],fa[MAXN*100],siz[MAXN*100],val[MAXN*100];
int p[MAXN*100];
struct Splay{
	int root;
	void push_up(int x){
		siz[x]=p[x];
		if(ls[x]) siz[x]+=siz[ls[x]];
		if(rs[x]) siz[x]+=siz[rs[x]];
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
	void insert(int x){
		if(!root){
			root=x;
			return;
		}
		int f,o=root;
		while(o){
			if(val[o]==val[x]){
				p[o]+=p[x];
				push_up(o);
				splay(o,0);
				return;
			}
			f=o;
			if(val[x]<val[o]){
				o=ls[o];
			}else o=rs[o];
		}
		if(val[x]<val[f]) ls[f]=x,fa[x]=f;
		else rs[f]=x,fa[x]=f;
		push_up(f);
		splay(x,0);
	}
	void Insert(int w){
		++cc;
		val[cc]=w;p[cc]=1;
		insert(cc);
	}
	void Del(int x){
		p[x]--;
		push_up(x);
		splay(x,0);
	}
	int get(int v){
		int o=root;
		while(1){
			if(val[o]==v) return o;
			if(v<val[o]) o=ls[o];
			else o=rs[o];
		}
	}
	int ask(int lim){
		Insert(lim);
		int ans=siz[ls[root]];
		Del(root);
		return ans;
	}
}splay[MAXN*10];
int Ask(int pos,int lim){
	return splay[pos].ask(lim);
}
void insert(int pos,int val){
	splay[pos].Insert(val);
}
void Del(int pos,int val){
	splay[pos].Del(splay[pos].get(val));
}
int ask(int pos,int lim){
	int ret=0;
	while(pos){
		ret+=Ask(pos,lim);
		pos-=lowbit(pos);
	}
	return ret;
}
void add(int pos,int val){
	while(pos<=n){
		insert(pos,val);
		pos+=lowbit(pos);
	}
}
void del(int pos,int val){
	while(pos<=n){
		Del(pos,val);
		pos+=lowbit(pos);
	}
}
set<int>::iterator it;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(!to[a[i]]) to[a[i]]=++tot;
		a[i]=to[a[i]];
	}
	for(int i=1;i<=n;i++) st[a[i]].insert(i),b[i]=last[a[i]],last[a[i]]=i;
	for(int i=1;i<=n;i++) add(i,b[i]);
	int x,y;
	while(m--){
	//	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	//	puts("");
		scanf("%s%d%d",s,&x,&y);
		if(s[0]=='Q'){
			printf("%d\n",ask(y,x)-ask(x-1,x));
		}else{
			if(a[x]==to[y]) continue;
			if(!to[y]) to[y]=++tot;
			y=to[y];
			int nxt;
			it=st[a[x]].upper_bound(x);
			if(it==st[a[x]].end()){
				goto jumb;
			}else nxt=*it;
			del(nxt,b[nxt]);
			b[nxt]=b[x];
			add(nxt,b[nxt]);
			jumb:
			st[a[x]].erase(x);
			
			del(x,b[x]);
			it=st[y].upper_bound(x);
			if(it==st[y].end()){
				if(it==st[y].begin()){
					b[x]=0;
				}else{
					--it;
					b[x]=*it;
				}
				goto jumb2;
			}else nxt=*it;
			b[x]=b[nxt];
			del(nxt,b[nxt]);
			b[nxt]=x;
			add(nxt,b[nxt]);
			jumb2:
			add(x,b[x]);
			st[y].insert(x);
			a[x]=y;
		}
	}
	return 0;
}
