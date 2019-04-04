#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int H[50005],X[20000005],P[20000005],tot=1;
int dp[50005];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int stk[50005],top;
int dfn[50005];
int low[50005],tim;
int ans;
int list[100005],t;
struct N{
	int pos,w;
	N(int a=0,int b=0){
		pos=a;w=b;
	}
};
struct dddl{
	N q[100005];
	int h,t;
	void clear(){
		h=t=0;
	}
	void pop(int x){
		if(q[h].pos==x) h++;
	}
	int ask(){
		return q[h].w;
	}
	void push(N a){
		while(h<t&&q[t-1].w<=a.w) t--;
		q[t++]=a;
	}
}q;
bool debug;
int fa[50005];
void dfs(int x){
	dfn[x]=low[x]=++tim;
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa[x])continue;
		if(fa[P[i]]&&dfn[P[i]]>dfn[x]){
			//find circle
			int k=P[i];
			t=0;
			while(k!=x) list[t++]=k,k=fa[k];
			list[t++]=x;
			int mx=0x80808080;
			for(int j=0;j<t;j++){
				list[j+t]=list[j];
				mx=max(mx,dp[list[j]]+min(j+1,t-j-1));
			}
			q.clear();
			q.push(N(0,dp[list[0]]));
			int adds=0;
			for(int j=1;j<2*t;j++){
				q.pop(j-t/2-1);
				adds++;
				ans=max(ans,dp[list[j]]+adds+q.ask());
				q.push(N(j,dp[list[j]]-adds));
			}
			dp[x]=max(dp[x],mx);
		}else if(!low[P[i]]){
			fa[P[i]]=x;
			dfs(P[i]);
			low[x]=min(low[x],low[P[i]]);
			if(low[P[i]]>dfn[x])ans=max(ans,dp[x]+dp[P[i]]+1),dp[x]=max(dp[x],dp[P[i]]+1);
		}else low[x]=min(low[x],dfn[P[i]]);
	}
	ans=max(ans,dp[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,k;i<m;i++){
		scanf("%d",&k);
		int last;
		scanf("%d",&last);
		for(int i=1,t;i<k;i++){
			scanf("%d",&t);
			add(last,t);add(t,last);
			last=t;
		}
	}
	dfs(1);
	printf("%d\n",ans);	
	return 0;
}
