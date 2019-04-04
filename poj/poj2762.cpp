#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
int H[1001],P[6001],X[6001],tot,dfn[6001],tim;
int _H[1001],_P[6001],_X[6001],_tot;
inline void _add(int x,int y){
	_P[++_tot]=y;_X[_tot]=_H[x];_H[x]=_tot;
}
int low[6001];
bool instack[6001];int stk[6001],top;
inline void add(int x,int y){
	P[++tot]=y,X[tot]=H[x],H[x]=tot;
}
int belong[1001],cnt,siz[1001];
void tarjan(int u){
	low[u]=dfn[u]=++tim;
	instack[u]=1;stk[top++]=u;
	for(int i=H[u];i;i=X[i]){
		int v=P[i];
		if(!dfn[v]){
			tarjan(v);low[u]=min(low[u],low[v]);
		}else if(instack[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		cnt++;
		int k;
		do{
			siz[cnt]++;
			k=stk[--top];
			belong[k]=cnt;
			instack[k]=0;
		}while(k!=u);
	}
}
int in[1005],f[1005];
queue<int> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	while(T--){
		memset(H,0,sizeof H);tot=0;
		memset(dfn,0,sizeof dfn);tim=0;cnt=0;
		memset(_H,0,sizeof _H);_tot=0;
		memset(in,0,sizeof in);
		memset(f,0,sizeof f);
		memset(siz,0,sizeof siz);
		int n,m,x,y;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		for(int i=1;i<=n;i++){
			if(!dfn[i]) tarjan(i);
		}
		for(int i=1;i<=n;i++){
			for(int j=H[i];j;j=X[j]){
				if(belong[i]!=belong[P[j]]){
					_add(belong[i],belong[P[j]]);
					in[belong[P[j]]]++;
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			if(!in[i]) {
				f[i]=siz[i];
				q.push(i);
			}
		}
		while(!q.empty()){
			int k=q.front();q.pop();
			for(int i=_H[k];i;i=_X[i]){
				f[_P[i]]=max(f[_P[i]],f[k]+siz[_P[i]]);
				in[_P[i]]--;
				if(!in[_P[i]]) q.push(_P[i]);
			}
		}
		for(int i=1;i<=cnt;i++){
			if(f[i]==n){
				printf("Yes\n");goto ed;
			}
		}
		if(1) printf("No\n");
		ed:;
	}
	
	return 0;
}
