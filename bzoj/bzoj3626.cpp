#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q;
const int MAXN=50005;
int H[MAXN],X[MAXN<<1],P[MAXN<<1],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
struct N{
	int x,z,t,id;
	N(int a=0,int b=0,int c=0,int d=0){
		x=a,z=b,t=c;id=d;
	}
}Q[MAXN<<1];
int t;
bool cmp(const N&a,const N&b){
	return a.x<b.x;
}
const int mod=201314;
int dep[MAXN],siz[MAXN],son[MAXN],fa[MAXN];
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	siz[x]=1;
	int tmp=0;
	for(int i=H[x];i;i=X[i]){
		dfs(P[i]);
		siz[x]+=siz[P[i]];
		if(siz[P[i]]>tmp){
			tmp=siz[P[i]];
			son[x]=P[i];
		}
	}
}
int dfn[MAXN],tim,top[MAXN];
typedef long long LL;
void dfs2(int x){
	if(!top[x]) top[x]=x;
	dfn[x]=++tim;
	if(son[x]) top[son[x]]=top[x],dfs2(son[x]);
	for(int i=H[x];i;i=X[i]){
		if(son[x]!=P[i]){
			dfs2(P[i]);
		}
	}
}
LL sum[MAXN<<2];
LL lazy[MAXN<<2];
LL ans[MAXN];
void do_add(int o,int l,int r,int k){
	lazy[o]+=k;
	sum[o]+=k*(r-l+1);
}
void down(int o,int l,int r){
	if(lazy[o]){
		int mid=(l+r)>>1;
		do_add(o<<1,l,mid,lazy[o]);
		do_add(o<<1|1,mid+1,r,lazy[o]);
		lazy[o]=0;
	}
}
void add(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		do_add(o,l,r,1);
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid) add(o<<1,l,mid,L,R);
		else if(L>mid) add(o<<1|1,mid+1,r,L,R);
		else add(o<<1,l,mid,L,mid),add(o<<1|1,mid+1,r,mid+1,R);
		sum[o]=sum[o<<1]+sum[o<<1|1];
	}
}
LL ask(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		return sum[o];
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid) return ask(o<<1,l,mid,L,R);
		else if(L>mid) return ask(o<<1|1,mid+1,r,L,R);
		else return ask(o<<1,l,mid,L,mid)+ask(o<<1|1,mid+1,r,mid+1,R);
	}
}
void upd(int x){
	while(x){
		add(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
}
int ask(int z){
	LL ret=0;
	while(z){
		ret+=ask(1,1,n,dfn[top[z]],dfn[z]);
		z=fa[top[z]];
	}
	return ret%mod;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[i]);fa[i]++;
		add(fa[i],i);
	}
	//树链剖分
	dfs(1);dfs2(1);
	for(int i=0,x,y,z;i<q;i++){
		scanf("%d%d%d",&x,&y,&z);
		x++;y++;z++;
		if(x==1){
			Q[t++]=N(y,z,1,i);
		}else{
			Q[t++]=N(y,z,1,i);
			Q[t++]=N(x-1,z,-1,i);
		}
	}
	sort(Q,Q+t,cmp);
	int j=0;
	for(int i=1;i<=n;i++){
		upd(i);
		while(j<t&&Q[j].x==i) ans[Q[j].id]+=ask(Q[j].z)*Q[j].t,ans[Q[j].id]%=mod,j++;
	}
	for(int i=0;i<q;i++) printf("%lld\n",(ans[i]+mod)%mod);
	return 0;
}
