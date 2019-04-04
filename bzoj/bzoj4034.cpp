#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int n,m;
int H[100005],X[200005],P[200005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int w[100005];
int fa[100005];
int siz[100005];
int son[100005];
void dfs1(int x){
	siz[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa[x]){
			fa[P[i]]=x;
			dfs1(P[i]);
			siz[x]+=siz[P[i]];
			if(siz[P[i]]>siz[son[x]]){
				son[x]=P[i];
			}
		}
	}
}
int dfn[100005],tim,which[100005],end[100005];
int top[100005];
LL sum[100005*4],lazy[100005*4];
void dfs2(int x){
//	printf("%d\n",x);
	dfn[x]=++tim;
	if(!top[x]) top[x]=x;
	if(son[x]){
		top[son[x]]=top[x];
		dfs2(son[x]);
	}
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=son[x]&&P[i]!=fa[x]){
			dfs2(P[i]);
		}
	}
	end[x]=tim;
}
void up(int o){
	sum[o]=sum[o<<1]+sum[o<<1|1];
}
void bd(int o,int l,int r){
	if(l==r){
		sum[o]=w[which[l]];
	}else{
		int mid=(l+r)/2;
		bd(o<<1,l,mid);
		bd(o<<1|1,mid+1,r);
		up(o);
	}
}
int t,x,a;
void do_add(int o,LL a,int l,int r){
	sum[o]+=a*1LL*(r-l+1);
	lazy[o]+=a;
}
void down(int o,int l,int r){
	if(lazy[o]){
		int mid=(l+r)/2;
		do_add(o<<1,lazy[o],l,mid);
		do_add(o<<1|1,lazy[o],mid+1,r);
		lazy[o]=0;
	}
}

void add(int o,int l,int r,int L,int R,int a){
	if(l==L&&r==R){
		do_add(o,a,l,r);
	}else{
		down(o,l,r);
		int mid=(l+r)/2;
		if(R<=mid) add(o<<1,l,mid,L,R,a);
		else if(L>mid) add(o<<1|1,mid+1,r,L,R,a);
		else add(o<<1,l,mid,L,mid,a),add(o<<1|1,mid+1,r,mid+1,R,a);
		up(o);
	}
}
LL ask(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		return sum[o];
	}else{
		down(o,l,r);
		int mid=(l+r)/2;
		if(R<=mid) return ask(o<<1,l,mid,L,R);
		else if(L>mid) return ask(o<<1|1,mid+1,r,L,R);
		else return ask(o<<1,l,mid,L,mid)+ask(o<<1|1,mid+1,r,mid+1,R);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=n;i++) which[dfn[i]]=i;
	bd(1,1,n);
	while(m--){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&x,&a);
			add(1,1,n,dfn[x],dfn[x],a);
		}else if(t==2){
			scanf("%d%d",&x,&a);
			add(1,1,n,dfn[x],end[x],a);
		}else {
			scanf("%d",&x);
			LL sum=0;
			while(x){
				sum+=ask(1,1,n,dfn[top[x]],dfn[x]);
				x=fa[top[x]];
			}
			printf("%lld\n",sum);
		}
	}
	//system("pause");
	return 0;
}
