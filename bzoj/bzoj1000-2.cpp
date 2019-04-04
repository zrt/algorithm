#include<cstdio>
#include <algorithm>
#include <cstring>
#include<queue>
const int inf=0x3f3f3f3f;
using namespace std;
int H[2],X[100],P[100],flow[100],tot;
int S(0),T(1);
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[2];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);int x;
	while(!q.empty()){
		x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[x]+1;
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
			tmp=dfs(P[i],min(flow[i],a));
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
	int f(0);
	while(bfs()) f+=dfs(S,inf);
	return f;
}
int main(){
	tot=1;
	int a,b;
	scanf("%d%d",&a,&b);
	add(S,T,a);add(T,S,0);add(S,T,b);add(T,S,0);
	printf("%d\n",Dinic());
	return 0;
}
