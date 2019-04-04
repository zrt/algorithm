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


int n,lim,add;
char s[10];
int k;
int cc;
const int MAXN = 300000;
int ls[MAXN],rs[MAXN],root,fa[MAXN],val[MAXN],sum[MAXN],num[MAXN];
void push_up(int x){
	sum[x]=sum[ls[x]]+sum[rs[x]]+num[x];
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
			if(ls[y]==x) zig(x);
			else zag(x);
		}else{
			if(ls[fa[y]]==y){
				if(ls[y]==x) zig(y),zig(x);else zag(x),zig(x);
			}else{
				if(ls[y]==x) zig(x),zag(x);else zag(y),zag(x);
			}
		}
	}
	if(!z) root=x;
}
int get(int w){
	int o=root;
	while(o){
		if(val[o]==w){
			splay(o,0);
			return o;
		}
		if(w<val[o]) o=ls[o];
		else o=rs[o];
	}
	return 0;
}

int get_kth(int k){
	int o=root;
	if(k<1) return -1-add;
	while(o){
		if(sum[ls[o]]>=k) o=ls[o];
		else if(sum[ls[o]]+num[o]>=k){
			splay(o,0);
			return val[o];
		}else{
			k-=sum[ls[o]]+num[o];
			o=rs[o];
		}
	}
	return -1;
}

void insert(int x){
	int f,o=root;
	if(!root){
		root=x;return;
	}
	while(o){
		f=o;
		if(val[x]<val[o]) o=ls[o];
		else o=rs[o];
	}
	fa[x]=f;
	if(val[x]<val[f]) ls[f]=x;
	else rs[f]=x;
	while(f){
		push_up(f);
		f=fa[f];
	}
}
void Insert(int w){
	if(get(w)){
		sum[root]++;
		num[root]++;
		return;
	}
	val[++cc]=w;sum[cc]=1;num[cc]=1;
	insert(cc);
	splay(cc,0);
}
int ans=0;
void del(int limit){
	Insert(limit);
	ans+=sum[ls[root]]+num[root]-1;
	root=rs[root];
	fa[root]=0;
}
void dfs(int x){
	if(ls[x]) dfs(ls[x]);
	if(x) printf("%d ",val[x]+add);
	if(rs[x]) dfs(rs[x]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&lim);
	lim--;
	add=0;
	for(int i=0;i<n;i++){
		scanf("%s%d",s,&k);
		if(s[0]=='I'){
			if(k<=lim) continue;
			Insert(k-add);
		}else if(s[0]=='A'){
			add+=k;
		}else if(s[0]=='S'){
			add-=k;
			del(lim-add);
		}else if(s[0]=='F'){
			printf("%d\n",get_kth(sum[root]-k+1)+add);
		}
	}
	printf("%d\n",ans);
	return 0;
}
