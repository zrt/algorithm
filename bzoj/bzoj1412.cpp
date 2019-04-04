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
int n,m;
int s[102][102];
int H[10105],P[90000],X[90000],tot,flow[90000],S,T;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
queue<int> q;
int d[10105];
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;int k;q.push(S);
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
//	printf("%d %d\n",x,a);
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
	scanf("%d%d",&n,&m);
	S=10101,T=10102;tot=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&s[i][j]);
		}
	}
	int num(0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==1){
				add(num,T,inf);
				add(T,num,0);
			}
			if(s[i][j]==2){
				add(S,num,inf);
				add(num,S,0);
			}
			if(i<n){
				add(num,num+m,1);add(num+m,num,1);
			}
			if(j<m){
				add(num,num+1,1);add(num+1,num,1);
			}
			num++;
		}
	}
	printf("%d\n",Dinic());
	return 0 ;
}
