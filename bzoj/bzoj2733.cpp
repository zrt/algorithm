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
int ls[MAXN],rs[MAXN],fa[MAXN],val[MAXN],siz[MAXN];
void push_up(int x){
	siz[x]=1;
	if(ls[x]) siz[x]+=siz[ls[x]];
	if(rs[x]) siz[x]+=siz[rs[x]];
}
void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[rs[x]]=y;else ls[y]=0;
	fa[x]=fa[y];
	if(fa[x]){
		if(ls[fa[x]]==y) ls[fa[x]]=x;else rs[fa[x]]=x;
	}
	fa[y]=x;rs[x]=y;
	push_up(y);push_up(x);
}
void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;else rs[y]=0;
	fa[x]=fa[y];
	if(fa[x]){
		if(ls[fa[x]]==y) ls[fa[x]]=x;else rs[fa[x]]=x;
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
}
void insert(int x,int o){
	int f;
	while(o){
		f=o;
		if(val[x]<val[o]) o=ls[o];
		else o=rs[o]; 
	}
	if(val[x]<val[f]) ls[f]=x;
	else rs[f]=x;
	fa[x]=f;
	push_up(x),push_up(f);
	splay(x,0);
}
int f[MAXN];
char s[100];
int n,m;
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int stk[MAXN],top;
void merge(int x,int y){
	splay(x,0),splay(y,0);
	if(siz[x]>siz[y]) swap(x,y);
	stk[top++]=x;
	while(top>0){
		x=stk[top-1];
		if(ls[x]) stk[top++]=ls[x],ls[x]=0;
		else{
			top--;
			if(rs[x]) stk[top++]=rs[x];
			rs[x]=0;
			insert(x,y);
			y=x;
		}
	}
}
int ask(int x,int pos){
	while(siz[ls[x]]+1!=pos){
		if(siz[ls[x]]>=pos) x=ls[x];
		else pos-=siz[ls[x]]+1,x=rs[x];
	}
	return x;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++) scanf("%d",&val[i]),siz[i]=1;
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		if(get(x)!=get(y)){
			f[get(x)]=get(y);
			merge(x,y);
		}
	}
	scanf("%d",&m);
	int x,y;
	while(m--){
		scanf("%s%d%d",s,&x,&y);
		if(s[0]=='Q'){
			splay(x,0);
			if(y>siz[x]) printf("-1\n");
			else{
				printf("%d\n",ask(x,y));
			}
		}else{
			if(get(x)!=get(y)){
				f[get(x)]=get(y);
				merge(x,y);
			}
		}
	}
	return 0;
}
