#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char s[10];
int a[100005];
int H[100005],P[200005],X[200005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int dep[100005],fa[100005],top[100005],dfn[100005],son[100005],siz[100005],tim,pos[100005];
void dfs(int x){
	siz[x]=1;
	dep[x]=dep[fa[x]]+1;
	int tmp=0;
	for(int i=H[x];i;i=X[i]){
		if(fa[x]!=P[i]){
			fa[P[i]]=x;
			dfs(P[i]);
			if(siz[P[i]]>tmp){
				tmp=siz[P[i]];
				son[x]=P[i];
			}
			siz[x]+=siz[P[i]];
		}
	}
}
void dfs2(int x){
	dfn[x]=++tim;
	if(!top[x]) top[x]=x;
	if(son[x]) top[son[x]]=top[x],dfs2(son[x]);
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa[x]&&P[i]!=son[x]) dfs2(P[i]);
	}
}
int lft[400005],rgt[400005],sum[400005];
bool lazy[400005];
void up(int o){
	sum[o]=sum[o<<1]+sum[o<<1|1]-(rgt[o<<1]==lft[o<<1|1]);
	lft[o]=lft[o<<1];
	rgt[o]=rgt[o<<1|1];
}
void do_(int o,int w){
	lft[o]=rgt[o]=w;
	sum[o]=1;
	lazy[o]=1;
}
void down(int o){
	if(lazy[o]){
		do_(o<<1,lft[o]);
		do_(o<<1|1,lft[o]);
		lazy[o]=0;
	}
}
void bd(int o,int l,int r){
	if(l==r){
		lft[o]=rgt[o]=a[pos[l]];
		sum[o]=1;
	}else{
		int mid=(l+r)>>1;
		bd(o<<1,l,mid);bd(o<<1|1,mid+1,r);
		up(o);
	}
}
void cg(int o,int l,int r,int L,int R,int w){
	if(l==L&&r==R){
		do_(o,w);
	}else{
		int mid=(l+r)>>1;
		down(o);
		if(R<=mid) cg(o<<1,l,mid,L,R,w);
		else if(L>mid) cg(o<<1|1,mid+1,r,L,R,w);
		else{
			cg(o<<1,l,mid,L,mid,w);
			cg(o<<1|1,mid+1,r,mid+1,R,w);
		}
		up(o);
	}
}
void cg(int x,int y,int z){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		cg(1,1,n,dfn[top[x]],dfn[x],z);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	cg(1,1,n,dfn[y],dfn[x],z);
}
int Lft,Rgt,Sum;
void ask(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		if(Lft==-1){
			Lft=lft[o];
			Sum=sum[o];
			Rgt=rgt[o];
		}else{
			Sum+=sum[o];
			if(Rgt==lft[o]) Sum--;
			Rgt=rgt[o];
		}
	}else{
		int mid=(l+r)>>1;
		down(o);
		if(R<=mid) ask(o<<1,l,mid,L,R);
		else if(L>mid) ask(o<<1|1,mid+1,r,L,R);
		else{
			ask(o<<1,l,mid,L,mid);
			ask(o<<1|1,mid+1,r,mid+1,R);
		}
	}
}
int ask(int x,int y){
	int ret=0;
	int lastx=-1,lasty=-1;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y),swap(lastx,lasty);
		Lft=Rgt=-1;
		Sum=0;
		ask(1,1,n,dfn[top[x]],dfn[x]);
		ret+=Sum;
		if(lastx==Rgt) ret--;
		lastx=Lft;
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y),swap(lastx,lasty);
	Lft=Rgt=-1;
	Sum=0;
	ask(1,1,n,dfn[y],dfn[x]);
	ret+=Sum;
	if(lasty==Lft) ret--;
	if(lastx==Rgt) ret--;
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1);dfs2(1);
	for(int i=1;i<=n;i++) pos[dfn[i]]=i;
	bd(1,1,n);
	int x,y,z;
	while(m--){
		scanf("%s",s);
		if(s[0]=='C'){
			scanf("%d%d%d",&x,&y,&z);
			cg(x,y,z);
		}else{
			scanf("%d%d",&x,&y);
			printf("%d\n",ask(x,y));
		}
	}
	return 0;
}
