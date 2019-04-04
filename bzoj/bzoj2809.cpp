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
int key[MAXN],h[MAXN],l[MAXN],r[MAXN],root[MAXN],sum[MAXN],num[MAXN];
int cc;
int n,m;
LL ans;
int H[MAXN],X[MAXN],P[MAXN],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int c[MAXN],w[MAXN];
int merge(int x,int y){
	if(!x) return y;
	if(!y) return x;
	if(key[x]<key[y]) swap(x,y);
	r[x]=merge(r[x],y);
	if(h[l[x]]>h[r[x]]) swap(l[x],r[x]);
	h[x]=r[x]?h[r[x]]+1:0;
	return x;
}
void dfs(int x){
	for(int i=H[x];i;i=X[i]){
		dfs(P[i]);
		sum[x]+=sum[P[i]];num[x]+=num[P[i]];
		root[x]=merge(root[x],root[P[i]]);
		while(sum[x]>m){
			sum[x]-=key[root[x]];num[x]--;
			root[x]=merge(l[root[x]],r[root[x]]);
		}
	}
	ans=max(ans,w[x]*1LL*num[x]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++){
		scanf("%d%d%d",&x,&c[i],&w[i]);
		if(x) add(x,i);
	}
	for(int i=1;i<=n;i++){
		root[i]=++cc;
		sum[i]=key[root[i]]=c[i];
		num[i]=1;
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
