#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int a[1005];
int e[1005][1005];
int sum[1005];
int H[1005],X[2005000],P[2005000],tot=1,flow[2005000];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int S=1003,T=1004;
int ans;
int d[1005];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);
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
	int ret=0;
	while(bfs()){
		ret+=dfs(S,0x7fffffff);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&e[i][j]);
			sum[i]+=e[i][j];
		}
		ans+=sum[i];
	}
	for(int i=1;i<=n;i++) add(S,i,a[i]),add(i,S,0),add(i,T,sum[i]),add(T,i,0);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++) add(i,j,e[i][j]*2),add(j,i,e[i][j]*2);
	}
	printf("%d\n",ans-Dinic());
//	while(1);
	return 0;
}
