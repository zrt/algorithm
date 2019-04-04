#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x,y;
int H[1005],P[2005],X[2005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int stk[1005],top;
int dfn[1005],low[1005],tim;
int cnt,belong[1005];
void tarjan(int u,int fa){
	dfn[u]=low[u]=++tim;
	stk[top++]=u;
	for(int i=H[u];i;i=X[i]){
		if(i==fa) continue;
		if(!dfn[P[i]]){
			tarjan(P[i],i^1);
			low[u]=min(low[u],low[P[i]]);
		}else low[u]=min(low[u],dfn[P[i]]);
	}
	if(low[u]==dfn[u]){
		cnt++;
		int k;
		do{
			k=stk[--top];
			belong[k]=cnt;
		}while(k!=u);
	}
}
int out[1005];
int main(){
	tot=1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	tarjan(1,0);
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if(belong[i]!=belong[P[j]]){
				out[belong[i]]++;//!!!判断的是块的出度 
			}
		}
	}
	int leaf=0;
	for(int i=1;i<=cnt;i++){
		if(out[i]==1){
			leaf++;
		}
	}
	printf("%d\n",(leaf+1)>>1);
	return 0;
}