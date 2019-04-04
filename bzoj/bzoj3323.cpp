#include<bits/stdc++.h>
using namespace std;
int n;
const int mod=20130426;
int ls[250005],rs[250005],fa[250005];
int add[250005],mul[250005],siz[250005],w[250005];
int root;
inline void up(int x){
	siz[x]=siz[ls[x]]+siz[rs[x]]+1;
}
inline void do_mul(int x,int d){
	if(!x) return;
	w[x]=w[x]*1LL*d%mod;
	mul[x]=mul[x]*1LL*d%mod;
	add[x]=add[x]*1LL*d%mod;
}
inline void do_add(int x,int d){
	if(!x) return;
	w[x]=(w[x]+d)%mod;
	add[x]=(add[x]+d)%mod;
}
inline void down(int x){
	if(mul[x]!=1){
		do_mul(ls[x],mul[x]);
		do_mul(rs[x],mul[x]);
		mul[x]=1;
	}
	if(add[x]){
		do_add(ls[x],add[x]);
		do_add(rs[x],add[x]);
		add[x]=0;
	}
}
int bd(int l,int r){
	if(l>r) return 0;
	int mid=(l+r)/2;
	mul[mid]=1;
	ls[mid]=bd(l,mid-1);
	rs[mid]=bd(mid+1,r);
	if(ls[mid]) fa[ls[mid]]=mid;
	if(rs[mid]) fa[rs[mid]]=mid;
	up(mid);
	return mid;
}
char s[15];

inline void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[ls[y]]=y;else ls[y]=0;
	fa[x]=fa[y];
	if(ls[fa[y]]==y) ls[fa[y]]=x;else if(rs[fa[y]]==y) rs[fa[y]]=x;
	rs[x]=y;fa[y]=x;
	up(y);
}
inline void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[rs[y]]=y;else rs[y]=0;
	fa[x]=fa[y];
	if(ls[fa[y]]==y) ls[fa[y]]=x;else if(rs[fa[y]]==y) rs[fa[y]]=x;
	ls[x]=y;fa[y]=x;
	up(y);
}
int lis[250005];
void splay(int x,int z){
	int t=0;
	int p=x;
	while(p!=z) lis[t++]=p,p=fa[p];
	if(z) down(z);
	for(int i=t-1;i>=0;i--) down(lis[i]);
	/*
	while(fa[x]!=z){
		if(ls[fa[x]]==x) zig(x);else zag(x);
	}
	*/
	
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
	up(x);
}
int t=0;
void dfs(int x){
	down(x);
	if(ls[x])dfs(ls[x]);
	lis[t++]=x;
	if(rs[x])dfs(rs[x]);
}
inline int ask(int x){
	t=0;
	dfs(root);
	long long ret=0;
	for(register int i=t-1;i>=1;i--){
		ret=(ret*x+w[lis[i]])%mod;
	}
	return ret;
}
inline int find(int x,int k){
	int tmp=siz[ls[x]];
	down(x);
	if(tmp>=k) return find(ls[x],k);
	else if(tmp+1==k) return x;
	else return find(rs[x],k-tmp-1);
}
int main(){
	scanf("%d",&n);
	root=bd(1,2e5+3);
	while(n--){
		scanf("%s",s);
		int L,R,X;
		if(s[0]=='m'){
			if(strlen(s)==3){
				//mul
				scanf("%d%d%d",&L,&R,&X);
				L+=2;R+=2;
				int x=find(root,L-1);
				splay(x,0);
				int y=find(root,R+1);
				splay(y,x);
				do_mul(ls[y],X);
				splay(ls[y],0);
			}else{
				//mulx
				scanf("%d%d",&L,&R);
				L+=2,R+=2;
				int x=find(root,L-1);
				splay(x,0);
				int y=find(root,R+1);
				splay(y,x);
				int z=find(root,R);
				splay(z,y);
				down(x);down(y);down(z);
				w[y]+=w[z];
				w[z]=0;
				if(L==R) continue;
				int zz=find(root,R-1);
				splay(zz,y);
				rs[zz]=0;
				up(zz);
				int zzz=find(root,L);
				splay(zzz,y);
				ls[zzz]=z;
				fa[z]=zzz;
				up(zzz);
				splay(zzz,0);
			}
		}else if(s[0]=='a'){
			scanf("%d%d%d",&L,&R,&X);
			L+=2;R+=2;
			int x=find(root,L-1);
			splay(x,0);
			int y=find(root,R+1);
			splay(y,x);
			do_add(ls[y],X);
			splay(ls[y],0);
		}else if(s[0]=='q'){
			scanf("%d",&X);
			printf("%d\n",ask(X));
		}
	}
	return 0;
}
