/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
int n,m;
int H[1005],P[1005],X[1005];
int v[1005];
int cut[1005],cnt;
int tot,root;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int tim,dfn[1005],low[1005];
void tarjan(int u,int fa){
	dfn[u]=low[u]=++tim;
	for(int i=H[u];i;i=X[i]){
		if(i==fa) continue;
		if(!dfn[P[i]]){
			tarjan(P[i],i^1);
			low[u]=min(low[u],low[P[i]]);
			if(low[P[i]]>=dfn[u]) v[u]++;
		}else low[u]=min(low[u],dfn[P[i]]);
	}
	if((u!=root&&v[u]>0)||(v[u]>1)) cut[cnt++]=u;
}
int siz[1005],k,cuts[1005];
bool vis[1006];
bool iscut[1005];
void dfs(int u,int fa){
	vis[u]=1;
	siz[k]++;
	for(int i=H[u];i;i=X[i]){
		if(fa==i) continue;
		if(iscut[P[i]]){
			cuts[k]++;
			iscut[P[i]]=0;
			continue;
		}
		if(vis[P[i]]) continue;
		dfs(P[i],i^1);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int kase=0;
	while(scanf("%d",&m)&&m){
		tim=0;
		n=0;
		k=0;
		printf("Case %d: ",++kase);
		memset(siz,0,sizeof siz);
		memset(cuts,0,sizeof cuts);
		memset(v,0,sizeof v);
		memset(H,0,sizeof H);
		memset(dfn,0,sizeof dfn);
		memset(iscut,0,sizeof iscut);
		memset(vis,0,sizeof vis);
		tot=1;cnt=0;
		for(int i=0,x,y;i<m;i++){
			scanf("%d%d",&x,&y);
			n=max(n,max(x,y));
			add(x,y);add(y,x);
		}
		for(int i=1;i<=n;i++){
			if(dfn[i]) continue;
			root=i;
			tarjan(i,-1);
		}
		for(int j=0;j<cnt;j++){
			vis[cut[j]]=1;
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				for(int j=0;j<cnt;j++){
					iscut[cut[j]]=1;
				}
		//		if(iscut[i]) continue;
				k++;
				dfs(i,-1);
			}
		}
		long long ans=1;
		if(k==1){
			printf("2 %lld\n",1ll*n*(n-1)/2);
		}else{
			long long num=0;
			for(int i=1;i<=k;i++){
				if(cuts[i]==1) ans*=siz[i],num++;
			}
			printf("%lld %lld\n",num,ans);
		}
	}
	return 0;
}
