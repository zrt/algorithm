#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int tot=1;
int H[505],X[124850*2],P[124850*2],E[124850*2],flow[124850*2];
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;flow[tot]=k;
}
int d[505];
struct N{
	int x,w;
	friend bool operator < (const N&a,const N&b){
		return a.w>b.w;
	}
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
priority_queue<N> q;
int n,m;
bool bfs(){
	memset(d,0,sizeof d);
	d[1]=1;
	static queue<int> q;
	q.push(1);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	return d[n];
}
int dfs(int x,int a){
	if(x==n||a==0) return a;
	int f=a;
	int tmp;
	for(int i=H[x];i;i=X[i]){
		if(d[P[i]]==d[x]+1&&flow[i]>0){
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
	int ret=0;
	while(bfs()) ret+=dfs(1,1000000000);
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,x,y,z,k;i<m;i++){
		scanf("%d%d%d%d",&x,&y,&z,&k);
		add(x,y,z,k);
		add(y,x,z,k);
	}
	memset(d,0x3f,sizeof d);
	d[1]=0;
	q.push(N(1,0));
	while(!q.empty()){
		int x=q.top().x;q.pop();
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				q.push(N(P[i],d[P[i]]));
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if(d[i]+0LL+E[j]>d[P[j]]){
				flow[j]=0;
			}
		}
	}
	printf("%d\n",d[n]);
	printf("%d\n",Dinic());
//	while(1);
	return 0;
}
