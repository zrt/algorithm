#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
//by zrt
//problem:
using namespace std;
int c,l;
int spf[2505];
int minn[2505];
int maxx[2505];
int S,T;
int H[5505],X[4000000],P[4000000],flow[4000000],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[5505];
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
	int f=0;
	while(bfs()){
		f+=dfs(S,1<<30);
	}
	return f;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	tot=1;
	S=5504,T=5503;
	scanf("%d%d",&c,&l);
	for(int i=1;i<=c;i++) scanf("%d%d",&minn[i],&maxx[i]),add(S,i,1),add(i,S,0);
	for(int i=1,x;i<=l;i++) scanf("%d%d",&spf[i],&x),add(i+c,T,x),add(T,i+c,0);
	for(int i=1;i<=c;i++){
		for(int j=1;j<=l;j++){
			if(minn[i]<=spf[j]&&spf[j]<=maxx[i]){
				add(i,j+c,1);
				add(j+c,i,0);
			}
		}
	}
	printf("%d\n",Dinic());
	return 0;
}
