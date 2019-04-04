#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int dep[1000005],dfn[1000005],tim;
int fa[1000005][21];
LL mn[1000005],mx[1000005],sum[1000005];
int Num[1000005];
bool mark[1000005];
LL Sum,Mn,Mx;
struct Graph{
	int H[1000005],X[2000005],P[2000005],tot;
	inline void add(int x,int y){
		P[++tot]=y;X[tot]=H[x];H[x]=tot;
//		printf("# %d %d\n",x,y);
	}
	void dfs(int x){
		//printf("%d\n",x);
		dep[x]=dep[fa[x][0]]+1;
		dfn[x]=++tim;
		for(int i=H[x];i;i=X[i]){
			if(P[i]!=fa[x][0]){
				fa[P[i]][0]=x;
				dfs(P[i]);
			}
		}
	}
	int lca(int x,int y){
	//	printf("## %d %d\n",x,y);
		if(dep[x]<dep[y]) swap(x,y);
		for(int i=20;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
		if(x==y) return x;
		for(int i=20;i>=0;i--){
			if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
		}
		return fa[x][0];
	}
	void dp(int x){
	//	printf("%d\n",x);
		if(mark[x]) mn[x]=0,mx[x]=0,sum[x]=0,Num[x]=1;
		else mn[x]=0x3f3f3f3f3f3f3f3fLL,mx[x]=-0x3f3f3f3f3f3f3f3fLL,sum[x]=0,Num[x]=0;
		for(int i=H[x];i;i=X[i]){
			dp(P[i]);
			mn[P[i]]+=dep[P[i]]-dep[x];
			mx[P[i]]+=dep[P[i]]-dep[x];
			sum[P[i]]+=Num[P[i]]*1LL*(dep[P[i]]-dep[x]);
			if(mark[x]){
				Mn=min(Mn,mn[P[i]]);
				Mx=max(Mx,mx[x]+mx[P[i]]);
				Mx=max(Mx,mx[P[i]]);
				mx[x]=max(mx[x],mx[P[i]]);
				Sum+=sum[x]*Num[P[i]]+sum[P[i]]*Num[x];
				//Sum+=sum[P[i]];
				sum[x]+=sum[P[i]];
				Num[x]+=Num[P[i]];
			}else{
				Mn=min(mn[x]+mn[P[i]],Mn);
				mn[x]=min(mn[x],mn[P[i]]);
				Mx=max(Mx,mx[x]+mx[P[i]]);
				mx[x]=max(mx[x],mx[P[i]]);
				Sum+=sum[x]*Num[P[i]]+sum[P[i]]*Num[x];
				sum[x]+=sum[P[i]];
				Num[x]+=Num[P[i]];
			}
		}
	//	printf("%d %lld %lld %lld\n",x,Sum,Mn,Mx);
	}
	
}tree,t;
bool cmp(int a,int b){
	return dfn[a]<dfn[b];
}
int n,q,num;
int stk[1000005],top;
int a[1000005];
int use[1000005],cc;
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	//puts("HAHAHA");
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		tree.add(x,y);tree.add(y,x);
	}
//	puts("hhh");
	tree.dfs(1);
//	puts("QAAQ");
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	scanf("%d",&q);
	while(q--){
	//	printf("%d\n",q);
		scanf("%d",&num);
		cc=0;
		for(int i=1;i<=num;i++){
			scanf("%d",&a[i]);
			mark[a[i]]=1;use[cc++]=a[i];
		}
	//	puts("HAHA");
		sort(a+1,a+num+1,cmp);
	//	puts("HEHE");
		top=0;
		if(!mark[1]){
			use[cc++]=1;
		}
		stk[top++]=1;
		for(int i=1;i<=num;i++){
		//	printf("%d\n",stk[top-1]);
			int lca=tree.lca(a[i],stk[top-1]);
			if(!mark[lca]) use[cc++]=lca;
		//	printf("$$ %d\n",lca);
			while(dep[lca]<dep[stk[top-1]]){
				if(dep[stk[top-2]]<=dep[lca]){
					int x=stk[--top];
					if(stk[top-1]!=lca){
						stk[top++]=lca;
					}
					t.add(lca,x);
					break;
				}
				t.add(stk[top-2],stk[top-1]);
				top--;
			}
			if(stk[top-1]!=a[i]){
				stk[top++]=a[i];
			}
		}
		while(top>1) t.add(stk[top-2],stk[top-1]),top--;
	//	puts("OKKK");
		Sum=0,Mn=0x3f3f3f3f3f3f3f3fLL,Mx=0;
		t.dp(1);
		printf("%lld %lld %lld\n",Sum,Mn,Mx);
		t.tot=0;
		for(int i=0;i<cc;i++) t.H[use[i]]=0,mark[use[i]]=0;
	}
	return 0;
}
