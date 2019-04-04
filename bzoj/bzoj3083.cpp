#include<bits/stdc++.h>
using namespace std;
// 树链剖分+Splay
typedef long long LL;
int n,m;
int H[100005],X[200005],P[200005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int root;
int w[100005],a[100005];
int dfn[100005],r[100005],tim;
int siz[100005],son[100005],top[100005];
int f[100005],dep[100005];
void dfs(int x,int fa){
	int mx=0;
	siz[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa) continue;
		dfs(P[i],x);
		siz[x]+=siz[P[i]];
		if(siz[P[i]]>mx){
			mx=siz[P[i]];
			son[x]=P[i];
		}
	}
}
void dfs2(int x){
	if(!top[x]) top[x]=x;
	dep[x]=dep[f[x]]+1;
	dfn[x]=++tim;
	if(son[x]) top[son[x]]=top[x],f[son[x]]=x,dfs2(son[x]);
	for(int i=H[x];i;i=X[i]){
		if(P[i]==f[x]||P[i]==son[x]) continue;
		f[P[i]]=x,dfs2(P[i]);
	}
	r[x]=tim;
}
int ls[100005],rs[100005],mn[100005],fa[100005];
int cov[100005];
void do_cov(int x,int k){
	if(!x) return;
	w[x]=mn[x]=cov[x]=k;
}
void down(int x){
	if(cov[x]){
		do_cov(ls[x],cov[x]);do_cov(rs[x],cov[x]);
		cov[x]=0;
	}
}
void up(int x){
	mn[x]=min(min(mn[ls[x]],mn[rs[x]]),w[x]);
	siz[x]=siz[ls[x]]+siz[rs[x]]+1;
}
int bd(int l,int r){
	if(l>r) return 0;
	int mid=(l+r)>>1;
	ls[mid]=bd(l,mid-1);
	rs[mid]=bd(mid+1,r);
	if(ls[mid]) fa[ls[mid]]=mid;
	if(rs[mid]) fa[rs[mid]]=mid;
	up(mid);
	return mid;
}
void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[ls[y]]=y;else ls[y]=0;
	fa[x]=fa[y];
	if(ls[fa[y]]==y) ls[fa[y]]=x;else if(rs[fa[y]]==y) rs[fa[y]]=x;
	fa[y]=x;rs[x]=y;
	up(y);
}
void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[rs[y]]=y;else rs[y]=0;
	fa[x]=fa[y];
	if(ls[fa[y]]==y) ls[fa[y]]=x;else if(rs[fa[y]]==y) rs[fa[y]]=x;
	fa[y]=x;ls[x]=y;
	up(y);
}
int lis[100005];
void splay(int x,int z){
	int t=0;
	int p=x;
	while(p!=z) lis[t++]=p,p=fa[p];
	for(int i=t-1;i>=0;i--) down(lis[i]);
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
	up(x);
	if(!z) root=x;
}
int find(int x,int k){
	if(siz[ls[x]]>=k) return find(ls[x],k);
	else if(siz[ls[x]]+1==k) return x;
	else return find(rs[x],k-siz[ls[x]]-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0);
	tim=1;
	dfs2(1);
	for(int i=1;i<=n;i++) w[dfn[i]]=a[i];
	mn[1]=w[1]=0x7fffffff,mn[n+2]=w[n+2]=0x7fffffff;mn[0]=0x7fffffff;
	root=bd(1,n+2);
	int opt,id,x,y,v;
	scanf("%d",&id);
	while(m--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&id);
		}else if(opt==2){
			scanf("%d%d%d",&x,&y,&v);
			while(top[x]!=top[y]){
				if(dep[top[x]]<dep[top[y]]) swap(x,y);
				// top[x] .. x change v
				int xx=find(root,dfn[top[x]]-1);
				splay(xx,0);
				int yy=find(root,dfn[x]+1);
				splay(yy,xx);
				down(xx);
				down(yy);
				do_cov(ls[yy],v);
				splay(ls[yy],0);
				x=f[top[x]];
			}
			if(dfn[x]>dfn[y]) swap(x,y);
			int xx=find(root,dfn[x]-1);
			splay(xx,0);
			int yy=find(root,dfn[y]+1);
			splay(yy,xx);
			down(xx);
			down(yy);
			do_cov(ls[yy],v);
			splay(ls[yy],0);
		}else if(opt==3){
			scanf("%d",&x);
			if(id==x){
				int xx=find(root,1);
				splay(xx,0);
				int yy=find(root,n+2);
			//	printf("%d\n",mn);
				splay(yy,xx);
				down(xx);down(yy);
				printf("%d\n",mn[ls[yy]]);
			}else if(dfn[id]<=dfn[x]&&dfn[x]<=r[id]){
				//子树
				int xx=find(root,dfn[x]-1);
				splay(xx,0);
				int yy=find(root,r[x]+1);
			//	printf("%d\n",mn);
				splay(yy,xx);
				down(xx);down(yy);
				printf("%d\n",mn[ls[yy]]);
			}else if(dfn[x]>dfn[id]||r[x]<dfn[id]){
				int xx=find(root,dfn[x]-1);
				splay(xx,0);
				int yy=find(root,r[x]+1);
			//	printf("%d\n",mn);
				splay(yy,xx);
				down(xx);down(yy);
				printf("%d\n",mn[ls[yy]]);
			}else{
				//补集
				int ans=0x7fffffff;
				int p=id;
				while(p&&top[p]!=top[x]&&f[top[p]]!=x){
					p=f[top[p]];
				}
				if(top[p]==top[x]){
					p=son[x];
				}else p=top[p];
				int xx=find(root,1);
				splay(xx,0);
				int yy=find(root,dfn[p]);
				splay(yy,xx);
				down(xx);down(yy);
				ans=min(ans,mn[ls[yy]]);
				xx=find(root,r[p]);
				splay(xx,0);
				yy=find(root,n+2);
				splay(yy,xx);
				down(xx);down(yy);
				ans=min(ans,mn[ls[yy]]);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
/*
7 1000
1 2
1 3
3 4
3 5
5 6
5 7
3 4 3 5 4 6 7
1
1 5
3 2
*/
