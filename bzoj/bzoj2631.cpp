#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int mod=51061;
int n,q;
int fa[100005],ls[100005],rs[100005],sum[100005],w[100005],add[100005],mul[100005],siz[100005];
bool rev[100005];
void up(int x){
	sum[x]=(sum[ls[x]]+sum[rs[x]]+w[x])%mod;
	siz[x]=siz[ls[x]]+siz[rs[x]]+1;
}
void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[rs[x]]=y;else ls[y]=0;
	if(ls[fa[y]]==y) ls[fa[y]]=x;else if(rs[fa[y]]==y) rs[fa[y]]=x;
	fa[x]=fa[y];
	rs[x]=y;
	fa[y]=x;
	up(y);
}
void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;else rs[y]=0;
	if(ls[fa[y]]==y) ls[fa[y]]=x;else if(rs[fa[y]]==y) rs[fa[y]]=x;
	fa[x]=fa[y];
	ls[x]=y;fa[y]=x;
	up(y);
}
void do_add(int x,int d){
	w[x]=(w[x]+d)%mod;
	add[x]=(add[x]+d)%mod;
	sum[x]=(sum[x]+d*siz[x]%mod)%mod;
}
void do_mul(int x,int d){
	w[x]=w[x]*1LL*d%mod;
	add[x]=add[x]*1LL*d%mod;
	mul[x]=mul[x]*1LL*d%mod;
	sum[x]=sum[x]*1LL*d%mod;
}
void down(int x){
	if(rev[x]){
		swap(ls[x],rs[x]);
		if(ls[x]) rev[ls[x]]^=1;
		if(rs[x]) rev[rs[x]]^=1;
		rev[x]=0;
	}
	if(mul[x]!=1){
		if(ls[x]) do_mul(ls[x],mul[x]);
		if(rs[x]) do_mul(rs[x],mul[x]);
		mul[x]=1;
	}
	if(add[x]){
		if(ls[x]) do_add(ls[x],add[x]);
		if(rs[x]) do_add(rs[x],add[x]);
		add[x]=0;
	}
}
inline bool notroot(int x){
	return ls[fa[x]]==x||rs[fa[x]]==x;
}
int list[100005],t;
void splay(int x){
	//down
	t=0;int p=x;
	for(;notroot(p);p=fa[p]){
		list[t++]=p;
	}
	down(p);
	for(int i=t-1;i>=0;i--) down(list[i]);
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
	for(;x;x=fa[x]){
		splay(x);
		rs[x]=y;
		up(x);
		y=x;
	}
}
void mkroot(int x){
	access(x);
	splay(x);
	rev[x]^=1;
}
void link(int x,int y){
	mkroot(x);
	fa[x]=y;
	access(x);
}
void cut(int x,int y){
	mkroot(x);
	access(y);splay(y);
	down(y);
	fa[x]=0;ls[y]=0;up(y);
}
char s[10];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) mul[i]=1,w[i]=1,sum[i]=1,siz[i]=1;
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		link(x,y);
	}
	int u1,v1,u2,v2,c;
	while(q--){
		scanf("%s",s);
		if(s[0]=='+'){
			scanf("%d%d%d",&u1,&v1,&c);
			mkroot(u1);
			access(v1);
			splay(v1);
			do_add(v1,c);
		}else if(s[0]=='-'){
			scanf("%d%d%d%d",&u1,&v1,&u2,&v2);
			cut(u1,v1);link(u2,v2);
		}else if(s[0]=='*'){
			scanf("%d%d%d",&u1,&v1,&c);
			mkroot(u1);
			access(v1);
			splay(v1);
			do_mul(v1,c);
		}else{
			scanf("%d%d",&u1,&v1);
			mkroot(u1);access(v1);splay(v1);
			printf("%d\n",sum[v1]);
		}
	}
	return 0;
}
