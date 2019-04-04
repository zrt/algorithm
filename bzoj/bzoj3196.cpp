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
const int MAXN=51005;
int ls[MAXN*80],rs[MAXN*80],p[MAXN*80],fa[MAXN*80],siz[MAXN*80],val[MAXN*80],cc;
int stk[MAXN*80],top;
struct Splay{
	int root;
	inline void upd(int x){
		siz[x]=p[x];
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
		upd(y);upd(x);
	}
	inline int newnode(){
		if(top>0) return stk[--top];
		return ++cc;
	}
	inline void zag(int x){
		int y=fa[x];
		if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;else rs[y]=0;
		fa[x]=fa[y];
		if(fa[x]){
			if(ls[fa[x]]==y) ls[fa[x]]=x;else rs[fa[x]]=x;
		}
		fa[y]=x;ls[x]=y;
		upd(y);upd(x);
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
	inline void Insert(int w){
		int f,o=root;
		if(!root){
		//	++cc;
			int cc=newnode();
			p[cc]=1;
			val[cc]=w;
			root=cc;
			upd(cc);
			return;
		}
		while(o){
			if(val[o]==w){
				p[o]++;
				upd(o);
				splay(o,0);
				return;
			}
			f=o;
			if(w<val[o]) o=ls[o];
			else o=rs[o];
		}
	//	++cc;
		int cc=newnode();
		p[cc]=1;
		val[cc]=w;
		if(w<val[f]) ls[f]=cc;
		else rs[f]=cc;
		fa[cc]=f;
		upd(cc);
		splay(cc,0);
		return;
	}
	inline void Del(int x){
		p[x]--;
		if(p[x]>0){
			upd(x);
			splay(x,0);
		}else{
			splay(x,0);
			if(!ls[x]){
				root=rs[x];
				fa[root]=0;
			}else{
				int o=ls[x];
				while(rs[o]) o=rs[o];
				splay(o,x);
				rs[o]=rs[root];
				fa[rs[root]]=o;
				ls[root]=rs[root]=fa[root]=siz[root]=p[root]=val[root]=0;
				stk[top++]=root;
				root=o;
				fa[root]=0;
			}
		}
	}
	inline int get(int w){
		int o=root;
		while(o){
			if(w==val[o]) return o;
			if(w<val[o]) o=ls[o];
			else o=rs[o];
		}
		return o;
	}
	inline int ask(int lim){
		Insert(lim);
		int ret=siz[ls[root]];
		Del(root);
		return ret;
	}
	inline int pre(int k){
		Insert(k);
		if(!ls[root]){
			Del(root);
			return -inf;
		}
		int o=ls[root];
		while(rs[o]){
			o=rs[o];
		}
		Del(root);
		return val[o];
	}
	inline int nxt(int k){
		Insert(k);
		if(!rs[root]) {
			Del(root);
			return inf;
		}
		int o=rs[root];
		while(ls[o]){
			o=ls[o];
		}
		Del(root);
		return val[o];
	}
}splay[MAXN*4];
int a[MAXN];
void mk(int o,int l,int r){
	if(l==r){
		splay[o].Insert(a[l]);
	}else{
		int mid=(l+r)>>1;
		mk(o<<1,l,mid);
		mk(o<<1|1,mid+1,r);
		for(int i=l;i<=r;i++) splay[o].Insert(a[i]);
	}
}
int n,m,opt;
int _sum;
int _l,_r,_c;
void ask(int o,int l,int r,int lim){
	if(_l<=l&&r<=_r){
		_sum+=splay[o].ask(lim);
	}else{
		int mid=(l+r)>>1;
		if(_l<=mid) ask(o<<1,l,mid,lim);
		if(_r>mid) ask(o<<1|1,mid+1,r,lim);
	}
}
int Ask(int l,int r,int lim){
	_l=l,_r=r;
	_sum=0;
	ask(1,1,n,lim);
	return _sum+1;
}
void change(int o,int l,int r,int pos,int k,int nw){
	if(l==r){
		splay[o].Del(splay[o].get(k));
		splay[o].Insert(nw);
	}else{
		int mid=(l+r)>>1;
		splay[o].Del(splay[o].get(k));
		splay[o].Insert(nw);
		if(pos<=mid) change(o<<1,l,mid,pos,k,nw);
		else change(o<<1|1,mid+1,r,pos,k,nw);
	}
}
int _pre,_nxt;
void pre(int o,int l,int r,int k){
	if(_l<=l&&r<=_r){
		_pre=max(_pre,splay[o].pre(k));//-inf;
	}else{
		int mid=(l+r)>>1;
		if(_l<=mid) pre(o<<1,l,mid,k);
		if(_r>mid) pre(o<<1|1,mid+1,r,k);
	}
}
void nxt(int o,int l,int r,int k){
	if(_l<=l&&r<=_r){
		_nxt=min(_nxt,splay[o].nxt(k));//-inf;
	}else{
		int mid=(l+r)>>1;
		if(_l<=mid) nxt(o<<1,l,mid,k);
		if(_r>mid) nxt(o<<1|1,mid+1,r,k);
	}
}
int readint(){
	char x;int ret;
	int flag=1;
	while(x=getchar(),(x!='-'&&(x<'0'||x>'9')));
	if(x=='-') flag*=-1,x=getchar();
	ret=x-'0';
	while(x=getchar(),x>='0'&&x<='9') ret*=10,ret+=x-'0';
	return ret*flag;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) a[i]=readint();
	mk(1,1,n);
	while(m--){
		scanf("%d",&opt);
		if(opt==1){
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",Ask(l,r,k));
		}else if(opt==2){
			int l,r,k,L,R,MID;
			scanf("%d%d%d",&l,&r,&k);
			L=0,R=1e8+5;
			while(R-L>1){
				MID=(L+R)>>1;
				int tmp=Ask(l,r,MID);
				if(tmp>k){
					R=MID;
				}else L=MID;
			}
			printf("%d\n",R-1);
		}else if(opt==3){
			int pos,k;
			scanf("%d%d",&pos,&k);
			change(1,1,n,pos,a[pos],k);
			a[pos]=k;
		}else if(opt==4){
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			_l=l,_r=r;
			_pre=-inf;
			pre(1,1,n,k);
			printf("%d\n",_pre);
		}else{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			_l=l,_r=r;
			_nxt=inf;
			nxt(1,1,n,k);
			printf("%d\n",_nxt);
		}
	}
	
	return 0;
}
