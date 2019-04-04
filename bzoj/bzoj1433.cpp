#include <cstdio>
#include <cstring>
#include <algorithm>
#include<queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int tt,n;
int  is[51];
int hj[51];
int rs[51][51];
int H[220],X[6005],P[6005],tot,flow[6005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int S,T;
queue<int> q;
int d[220];
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);int k;
	while(!q.empty()){
		k=q.front();q.pop();
		for(int i=H[k];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[k]+1;
				q.push(P[i]);
			}
		}
	}
	return d[T];
}
int dfs(int x,int a){
	if(x==T||a==0) return a;
	int f=a,tmp;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(a,flow[i]));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int Dinic(){
	int ff(0);
	while(bfs()) ff+=dfs(S,inf);
	return ff;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		tot=1;
		S=0,T=219;
		memset(H,0,sizeof H);
		for(int i=1;i<=n;i++) scanf("%d",&is[i]);
		for(int i=1;i<=n;i++) scanf("%d",&hj[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&rs[i][j]);
			}
		}
		int tot(0);
		for(int i=1;i<=n;i++){
			if(!is[i]||!hj[i]) add(S,i,1),add(i,S,0),tot++;
		}
		for(int i=1;i<=n;i++){
			if(is[i]) add(i,i+100,1),add(i+100,i,0);
			for(int j=1;j<=n;j++){
				if(i!=j&&(is[j]&&rs[i][j])){
					add(i,j+100,1);add(j+100,i,0);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(is[i]) add(i+100,T,1),add(T,i+100,0);
		}
		if(Dinic()==tot) puts("^_^");
		else puts("T_T");
	}
	return 0 ;
}
