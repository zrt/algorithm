#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,f;
int H[405],tot,S,T,P[160005],flow[160005],X[160005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[405];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;
	while(!q.empty()) q.pop();
	q.push(S);
	int x;
	while(!q.empty()){
		x=q.front();q.pop();
		if(x==T) return 1;
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	return 0;
}
int dfs(int x,int a){
	if(x==T||a==0) return a;
	int f=a,tmp;
	for(int i=H[x];i;i=X[i]){
		if(d[P[i]]==d[x]+1&&flow[i]>0){
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
	int f=0;
	while(bfs()){
		f+=dfs(S,inf);
	}
	return f;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	S=403,T=404;
	tot=1;
	int d;
	scanf("%d%d%d",&n,&f,&d);
	//n 1..n n+1..n+n
	//f 2*n+1..2*n+f
	//d 2*n+f+1..2*n+f+d
	for(int i=1;i<=n;i++){
		add(i,i+n,1);
		add(i+n,i,0);
	}
	for(int i=1;i<=f;i++){
		add(S,i+2*n,1);
		add(i+2*n,S,0);
	}
	for(int i=1;i<=d;i++){
		add(2*n+f+i,T,1);
		add(T,2*n+f+i,0);
	}
	for(int i=1;i<=n;i++){
		int fi,di;
		scanf("%d%d",&fi,&di);
		int x;
		for(int j=1;j<=fi;j++){
			scanf("%d",&x);
			add(x+2*n,i,1);
			add(i,x+2*n,0);
		}
		for(int j=1;j<=di;j++){
			scanf("%d",&x);
			add(i+n,x+2*n+f,1);
			add(x+2*n+f,i+n,0);
		}
	}
	printf("%d\n",Dinic());
	return 0;
}
