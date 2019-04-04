#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int ans;
int a[50005],b[50005],c[50005];
int l[5005],r[5005];
int H[5005],X[50005<<2],P[50005<<2],flow[50005<<2],tot=1;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int S=5003,T=5004;
int d[5005];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
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
	while(bfs()) f+=dfs(S,1<<30);
	return f;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&l[i]),l[i]*=2;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		ans-=2*c[i];
		r[a[i]]+=c[i];
		r[b[i]]+=c[i];
	}
	for(int i=1;i<=n;i++){
		add(S,i,l[i]);
		add(i,S,0);
		add(i,T,r[i]);
		add(T,i,0);
	}
	for(int i=0;i<m;i++){
		add(a[i],b[i],c[i]);
		add(b[i],a[i],c[i]);
	}
	ans+=Dinic();
	printf("%d\n",ans/2*-1);
	return 0;
}
