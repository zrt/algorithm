#include<iostream>
#include<cstdio>
#include<cstring>
//by zrt
//problem:
using namespace std;
int H[4445],X[500005],P[500005],tot;
int vis[4445];
int T , n, m,x,y;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
} 
int _ans;
void dfs(int x,int d){
	vis[x]=d;
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			dfs(P[i],d+1);
		}else{
			_ans=max(_ans,d-vis[P[i]]+1);
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof vis);
		memset(H,0,sizeof H);
		tot=0; 
		_ans=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]) dfs(i,1);
		}
		if(_ans<=2) puts("0");else printf("%d\n",_ans);
	}
	
	return 0;
}
