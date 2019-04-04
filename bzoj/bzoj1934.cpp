#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x3fffffff) ;
int n,m;
bool a[305];
int S,T;
int H[305],X[100000],P[100000],tot,flow[100000];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[100000];
queue<int> q;
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
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			a-=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d",&n,&m);
	S=0,T=n+1;tot=1;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		a[i]=x;
		if(a[i]){
			add(S,i,1);
			add(i,S,0);
		}else {
			add(i,T,1);
			add(T,i,0);
		}
	}
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		if(a[x]){
			add(x,y,1);
			add(y,x,0);
		}else {
			add(y,x,1);
			add(x,y,0);
		}
	}
	int ff(0);
	while(bfs()){
		ff+=dfs(S,inf);
	}
	printf("%d\n",ff);
	return 0 ;
}
