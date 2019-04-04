#include<cstdio>
#include<algorithm>
using namespace std;
int H[5005],X[20005],P[20005],tot,_tot,num[20005],fa[20005];
bool iscut[20005];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;num[tot]= ++_tot;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;num[tot]=_tot;
}
int x,y,n,m;
int low[5005],dfn[5005],cnt,point[5005],tim,stk[5005],top;
void tarjan(int u){
	low[u]=dfn[u]=++tim;
	stk[top++]=u;
	for(int i=H[u];i;i=X[i]){
		if(num[i]==fa[u]) continue;
		if(!dfn[P[i]]){
			fa[P[i]]=num[i];
			tarjan(P[i]);
			low[u]=min(low[P[i]],low[u]);
		}else{
			low[u]=min(dfn[P[i]],low[u]);
		}
	}
	if(low[u]==dfn[u]){
		int k;++cnt;
		do{
			k=stk[--top];
			point[k]=cnt;
		}while(k!=u);
	}
}
bool vis[20005];int in[5005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	tarjan(1);
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if(vis[j]) continue;
			if(point[i]==point[P[j]]) continue;
			in[point[i]]++;in[point[P[j]]]++;
			vis[j]=1;
		}
	}
	int leaf=0;
	for(int i=1;i<=cnt;i++){
		if(in[i]==2) leaf++;
	}
	printf("%d",(leaf+1)>>1);
	return 0;
}