#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int n;
int LS[400005],RS[400005];
int cc;
int Root;
int w[400005];
int siz[400005];
int ls[15000500],rs[15000500],sum[15000500];
int num;
int stk[15000500],top;
int getnew(){
	if(top>0){
		ls[stk[top-1]]=rs[stk[top-1]]=sum[stk[top-1]]=0;
		return stk[--top];
	}
	return ++num;
}
void add(int &o,int l,int r,int pos){
	if(!o) o=getnew();
	if(l==r){
		sum[o]=1;
	}else{
		int mid=(l+r)>>1;
		if(pos<=mid) add(ls[o],l,mid,pos);else add(rs[o],mid+1,r,pos);
		sum[o]=1;
	}
}
int read(){
	int x;
	scanf("%d",&x);
	int now=++cc;
	if(!x){
		LS[now]=read();
		RS[now]=read();
		siz[now]=siz[LS[now]]+siz[RS[now]]+1;
	}else{
		add(w[now],1,n,x);
		siz[now]=1;
	}
	return now;
}
LL ans;
LL ans0,ans1;
int merge(int a,int b,int l,int r){
	if(!a) return b;
	if(!b) return a;
	int now=getnew();
	int mid=(l+r)>>1;
	int lft=sum[ls[a]]+sum[ls[b]];
	int rgt=sum[rs[a]]+sum[rs[b]];
	ans0+=sum[rs[a]]*1LL*sum[ls[b]];
	ans1+=sum[ls[a]]*1LL*sum[rs[b]];
	if(lft<rgt){
		rs[now]=merge(rs[a],rs[b],mid+1,r);
		ls[now]=merge(ls[a],ls[b],l,mid);
	}else{
		ls[now]=merge(ls[a],ls[b],l,mid);
		rs[now]=merge(rs[a],rs[b],mid+1,r);
	}
	stk[top++]=a;
	stk[top++]=b;
	sum[now]=sum[ls[now]]+sum[rs[now]];
	return now;
}
void dfs(int x){
	if(!LS[x]) return;
	else{
		if(siz[LS[x]]<siz[RS[x]]) dfs(RS[x]),dfs(LS[x]);
		else dfs(LS[x]),dfs(RS[x]);
		ans0=ans1=0;
		w[x]=merge(w[LS[x]],w[RS[x]],1,n);
		ans+=min(ans0,ans1);
	}
}
int main(){
	scanf("%d",&n);
	Root=read();
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
