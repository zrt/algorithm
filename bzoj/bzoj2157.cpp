#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
char s[15];
const int MAXN=20005;
int x[MAXN],y[MAXN],z[MAXN];
int H[MAXN],X[MAXN<<1],P[MAXN<<1],E[MAXN<<1],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int fa[MAXN],dep[MAXN],dfn[MAXN],tim,w[MAXN],siz[MAXN],son[MAXN],top[MAXN];
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	siz[x]=1;
	int tmp=0;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa[x]){
			fa[P[i]]=x;
			w[P[i]]=E[i];
			dfs(P[i]);
			siz[x]+=siz[P[i]];
			if(siz[P[i]]>tmp){
				tmp=siz[P[i]];
				son[x]=P[i];
			}
		}
	}
}
void dfs2(int x){
	dfn[x]=++tim;
	if(!top[x]) top[x]=x;
	if(son[x]) top[son[x]]=top[x],dfs2(son[x]);
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa[x]&&P[i]!=son[x]){
			dfs2(P[i]);
		}
	}
}
bool rev[MAXN<<2];
int sum[MAXN<<2],mn[MAXN<<2],mx[MAXN<<2];
void up(int o){
	sum[o]=sum[o<<1]+sum[o<<1|1];
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void do_rev(int o){
	rev[o]^=1;
	swap(mn[o],mx[o]);
	mn[o]=-mn[o];
	mx[o]=-mx[o];
	sum[o]=-sum[o];
}
void down(int o){
	if(rev[o]){
		do_rev(o<<1);do_rev(o<<1|1);
		rev[o]=0;
	}
}
int where[MAXN];
void bd(int o,int l,int r){
	if(l==r){
		sum[o]=mx[o]=mn[o]=w[where[l]];
	}else{
		int mid=(l+r)>>1;
		bd(o<<1,l,mid);
		bd(o<<1|1,mid+1,r);
		up(o);
	}
}
void cg(int o,int l,int r,int pos){
	if(l==r){
		sum[o]=mx[o]=mn[o]=w[where[l]];
	}else{
		int mid=(l+r)>>1;
		down(o);
		if(pos<=mid) cg(o<<1,l,mid,pos);
		else cg(o<<1|1,mid+1,r,pos);
		up(o);
	}
}
void Rev(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		do_rev(o);
	}else{
		int mid=(l+r)>>1;
		down(o);
		if(R<=mid) Rev(o<<1,l,mid,L,R);
		else if(L>mid) Rev(o<<1|1,mid+1,r,L,R);
		else Rev(o<<1,l,mid,L,mid),Rev(o<<1|1,mid+1,r,mid+1,R);
		up(o);
	}
}
void Rev(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		Rev(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(x==y) return;
	else{
		if(dep[x]<dep[y]) swap(x,y);
		Rev(1,1,n,dfn[y]+1,dfn[x]);
	}
}
int sm(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		return sum[o];
	}else{
		int mid=(l+r)>>1;
		down(o);
		if(R<=mid) return sm(o<<1,l,mid,L,R);
		else if(L>mid) return sm(o<<1|1,mid+1,r,L,R);
		else return sm(o<<1,l,mid,L,mid)+sm(o<<1|1,mid+1,r,mid+1,R);
	}
}
int asksum(int x,int y){
	int ret=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ret+=sm(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(x==y) return ret;
	else{
		if(dep[x]<dep[y]) swap(x,y);
		return ret+sm(1,1,n,dfn[y]+1,dfn[x]);
	}
}
int max(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		return mx[o];
	}else{
		int mid=(l+r)>>1;
		down(o);
		if(R<=mid) return max(o<<1,l,mid,L,R);
		else if(L>mid) return max(o<<1|1,mid+1,r,L,R);
		else return max(max(o<<1,l,mid,L,mid),max(o<<1|1,mid+1,r,mid+1,R));
	}
}
int min(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		return mn[o];
	}else{
		int mid=(l+r)>>1;
		down(o);
		if(R<=mid) return min(o<<1,l,mid,L,R);
		else if(L>mid) return min(o<<1|1,mid+1,r,L,R);
		else return min(min(o<<1,l,mid,L,mid),min(o<<1|1,mid+1,r,mid+1,R));
	//	up(o);
	}
}
int askmx(int x,int y){
	int ret=-0x7fffffff;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ret=max(ret,max(1,1,n,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(x==y) return ret;
	else{
		if(dep[x]<dep[y]) swap(x,y);
		return max(ret,max(1,1,n,dfn[y]+1,dfn[x]));
	}
}
int askmn(int x,int y){
	int ret=0x7fffffff;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ret=min(ret,min(1,1,n,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(x==y) return ret;
	else{
		if(dep[x]<dep[y]) swap(x,y);
		return min(ret,min(1,1,n,dfn[y]+1,dfn[x]));
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		x[i]++;
		y[i]++;
		add(x[i],y[i],z[i]);
		add(y[i],x[i],z[i]);
	}
	dfs(1);dfs2(1);
	for(int i=1;i<=n;i++) where[dfn[i]]=i;
	bd(1,1,n);
	scanf("%d",&m);
	while(m--){
		int i,p,u,v;
		scanf("%s",s);
		if(s[0]=='C'){
			scanf("%d%d",&i,&p);
			if(dep[x[i]]>dep[y[i]]){
				w[x[i]]=p;
				cg(1,1,n,dfn[x[i]]);
			}else{
				w[y[i]]=p;
				cg(1,1,n,dfn[y[i]]);
			}
		}else if(s[0]=='N'){
			scanf("%d%d",&u,&v);
			u++;v++;
			Rev(u,v);
		}else if(s[0]=='S'){
			scanf("%d%d",&u,&v);
			u++;v++;
			printf("%d\n",asksum(u,v));
		}else if(s[1]=='A'){
			scanf("%d%d",&u,&v);
			u++;v++;
			printf("%d\n",askmx(u,v));
		}else if(s[1]=='I'){
			scanf("%d%d",&u,&v);
			u++;v++;
			printf("%d\n",askmn(u,v));
		}
		
	}
	return 0;
}
