#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const LL inf(0x3f3f3f3f3f3f3f3fLL);
const double eps(1e-9);
LL n,m,k;
LL H[250005],X[550000],P[550000],E[550000];
LL fa[250005][19];
LL num[250005];
LL tot;
inline void add(LL x,LL y,LL z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
LL log;
LL stk[250005],top;
LL c[250005];
LL lca[250005];
LL dep[250005];
LL mincost[250005];
bool mark[250005];
LL tim;
void dfs(LL x,LL f,LL c){
	num[x]=++tim;
	mincost[x]=c;
	for(LL i=H[x];i;i=X[i]){
		if(P[i]!=f){
			dep[P[i]]=dep[x]+1;
			fa[P[i]][0]=x;
		//	mincost[P[i]]=c;
			dfs(P[i],x,min(E[i],c));
		}
	}
}

bool cmp(LL a,LL b){
	return num[a]<num[b];
}

LL asklca(LL x,LL y){
	if(dep[x]>dep[y]) swap(x,y);
	//depx<=depy
	for(LL i=log;i>=0;i--){
		if(dep[fa[y][i]]>=dep[x]) {
			y=fa[y][i];
		}
	}
	if(x==y) return x;
	for(LL i=log;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];y=fa[y][i];
		}
	}
	return fa[x][0];
}
LL f[250005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld",&n);
	for(LL i=1,x,y,z;i<n;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(log=0;1<<log<=n;log++);log--;
	dep[1]=1;
	dfs(1,0,inf);
	for(LL i=1;i<=log;i++){
		for(LL j=1;j<=n;j++){
			if(fa[j][i-1]){
				fa[j][i]=fa[fa[j][i-1]][i-1];
			}
		}
	}
	scanf("%lld",&m);
	while(m--){
		scanf("%lld",&k);
		for(LL i=1;i<=k;i++){
			scanf("%lld",&c[i]);
			mark[c[i]]=1;
		}
		if(!mark[1]){
			mark[1]=1;c[++k]=1;
		}
		sort(c+1,c+k+1,cmp);
		top=0;
		stk[top++]=c[1];
		f[0]=0;
		for(LL i=2;i<=k;i++){
			if(top==1){
				stk[top++]=c[i];
				lca[top-1]=asklca(stk[top-2],c[i]);
				f[top-1]=mincost[c[i]];
			}else{
				LL now=asklca(stk[top-1],c[i]);
				if(dep[now]<=dep[lca[top-1]]){
					f[top-2]=min(f[top-1]+f[top-2],mincost[lca[top-1]]);
					top--;
					i--;
					continue;
				}else{
					stk[top++]=c[i];
					lca[top-1]=now;
					f[top-1]=mincost[c[i]];
				}
			}
		}
		while(top>1){
			f[top-2]=min(f[top-1]+f[top-2],mincost[lca[top-1]]);
			top--;
		}
		printf("%lld\n",f[0]);
		for(LL i=1;i<=k;i++) mark[i]=0;
	}
	
	return 0;
}
