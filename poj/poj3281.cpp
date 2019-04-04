#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=450,MAXM=60000,inf=1e6;
int tot=1;
int H[MAXN],X[MAXM],P[MAXM],flow[MAXM];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[MAXN];
queue<int> q;
int S=444,T=445;
bool bfs(){
	memset(d,0,sizeof d);d[S]=1;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(!d[P[i]]&&flow[i]>0){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	return d[T];
}
int dfs(int x,int a){
	if(x==T||a==0) return a;
	int f=a;
	for(int i=H[x];i;i=X[i]){
		if(d[P[i]]==d[x]+1&&flow[i]>0){
			int tmp=dfs(P[i],min(flow[i],a));
			a-=tmp;
			flow[i]-=tmp;flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int Dinic(){
	int f=0,tmp;
	while(bfs()){
		while((tmp=dfs(S,inf))!=0) f+=tmp;
	}
	return f;
}
int n,F,D;
int main(){
	scanf("%d%d%d",&n,&F,&D);
	for(int i=1;i<=F;i++){
		add(S,i,1);
		add(i,S,0);
	}
	for(int i=1;i<=D;i++){
		add(i+300,T,1);
		add(T,i+300,0);
	}
	for(int i=1;i<=n;i++){
		add(i+100,i+200,1);
		add(i+200,i+100,0);
	}
	for(int i=1;i<=n;i++){
		int f,d;
		scanf("%d%d",&f,&d);
		for(int j=0,x;j<f;j++){
			scanf("%d",&x);
			add(x,i+100,1);
			add(i+100,x,0);
		}
		for(int j=0,x;j<d;j++){
			scanf("%d",&x);
			add(i+200,x+300,1);
			add(x+300,i+200,0);
		}
	}
	printf("%d\n",Dinic());
	return 0;
}