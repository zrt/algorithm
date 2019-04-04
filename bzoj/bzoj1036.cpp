#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int siz[30005],dep[30005],fa[30005],top[30005],son[30005],id[30005];
int H[30005],X[60005],P[60005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int n;
void dfs1(int x){
	dep[x]=dep[fa[x]]+1;
	siz[x]=1;
	int tmp=0;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa[x]){
			fa[P[i]]=x;
			dfs1(P[i]);
			siz[x]+=siz[P[i]];
			if(siz[P[i]]>tmp){
				tmp=siz[P[i]];
				son[x]=P[i];
			}
		}
	}
}
int cc;
void dfs2(int x,bool istop){
	id[x]=++cc;
	if(istop) top[x]=x;
	else top[x]=top[fa[x]];
	if(son[x]) dfs2(son[x],0);
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa[x]&&P[i]!=son[x]){
			dfs2(P[i],1);
		}
	}
}
int a[30005];
int maxx[30005*4],sum[30005*4];
void build(int o,int l,int r){
	if(l==r){
		sum[o]=maxx[o]=a[l];
		return;
	}else{
		int m=(l+r)>>1;
		build(o<<1,l,m);build(o<<1|1,m+1,r);
		maxx[o]=max(maxx[o<<1],maxx[o<<1|1]);
		sum[o]=sum[o<<1]+sum[o<<1|1];
	}
}
void change(int o,int l,int r,int pos,int w){
	if(l==r){
		maxx[o]=sum[o]=w;
		return;
	}else{
		int m=(l+r)>>1;
		if(pos<=m) change(o<<1,l,m,pos,w);
		else change(o<<1|1,m+1,r,pos,w);
		maxx[o]=max(maxx[o<<1],maxx[o<<1|1]);
		sum[o]=sum[o<<1]+sum[o<<1|1];
	}
}
int _l,_r,_c;
void asks(int o,int l,int r){
	if(_l<=l&&r<=_r){
		_c+=sum[o];
	}else{
		int m=(l+r)>>1;
		if(_l<=m) asks(o<<1,l,m);
		if(_r>m) asks(o<<1|1,m+1,r);
	}
}
void askm(int o,int l,int r){
	if(_l<=l&&r<=_r){
		_c=max(_c,maxx[o]);
	}else{
		int m=(l+r)>>1;
		if(_l<=m) askm(o<<1,l,m);
		if(_r>m) askm(o<<1|1,m+1,r);
	}
}
char s[10];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[id[i]]);
	}
	build(1,1,n);
	int q;
	scanf("%d",&q);
	for(int i=0,x,y;i<q;i++){
		scanf("%s%d%d",s,&x,&y);
		if(s[0]=='C'){
			change(1,1,n,id[x],y);
		}else if(s[1]=='S'){
			int ans=0;
			while(top[x]!=top[y]){
				if(dep[top[x]]<dep[top[y]]) swap(x,y);
				_l=id[top[x]],_r=id[x],_c=0;
				asks(1,1,n);
				ans+=_c;
				x=fa[top[x]];
			}
			if(dep[x]>dep[y]) swap(x,y);
			_c=0;_l=id[x],_r=id[y];
			asks(1,1,n);
			ans+=_c;
			printf("%d\n",ans);
		}else{
			_c=-(1<<30);
			while(top[x]!=top[y]){
				if(dep[top[x]]<dep[top[y]]) swap(x,y);
				_l=id[top[x]],_r=id[x];
				askm(1,1,n);
				x=fa[top[x]];
			}
			if(dep[x]>dep[y]) swap(x,y);
			_l=id[x],_r=id[y];
			askm(1,1,n);
			printf("%d\n",_c);
		}
	}
	return 0;
}
