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
int S,T,n,m;
int H[205],X[405],P[405],tot,flow[405];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
queue<int> q;
int d[205];
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;int tmp;q.push(S);
	while(!q.empty()){
		tmp=q.front();q.pop();
		for(int i=H[tmp];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[tmp]+1;
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
	while(~scanf("%d%d",&n,&m)){
		tot=1;
		memset(H,0,sizeof H);
		memset(flow,0,sizeof flow);
		for(int i=0,x,y,z;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,0);
		}
		S=1,T=m;
		int f=Dinic();
		printf("%d\n",f);
	}
	
	return 0;
}