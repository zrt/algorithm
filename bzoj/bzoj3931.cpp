#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
#define int LL
int n,m;
queue<int> q;
const LL inf=0x3f3f3f3f3f3f3f3fLL;
struct wangluoliu{
	int H[1005],X[2000050],P[2000050],tot;
	int flow[2000050];
	int d[1005];
	int S,T;
	inline void add(int x,int y,int z){
		P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
		P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;
	}
	bool bfs(){
		memset(d,0,sizeof d);
		d[S]=1;
		q.push(S);
		while(!q.empty()){
			int x=q.front();
			q.pop();
			for(int i=H[x];i;i=X[i]){
				if(flow[i]>0&&!d[P[i]]){
					d[P[i]]=d[x]+1;q.push(P[i]);
				}
			}
		}
		return d[T];
	}
	int dfs(int x,int a){
		if(x==T||a==0) return a;
		int tmp,f=a;
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
		int ret=0;
		while(bfs()) ret+=dfs(S,inf);
		return ret;
	}
	int solve(){
		S=1<<1|1,T=n<<1;
		return Dinic();
	}
}b;
struct zuiduanlu{
	int H[505],X[200005],P[200005];LL E[200005];
	int tot;
	LL d[505];
	inline void add(int x,int y,LL z){
		P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
	}
	void solve(){
		memset(d,0x3f,sizeof d);
		d[1]=0;
		q.push(1);
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=H[x];i;i=X[i]){
				if(d[P[i]]>d[x]+E[i]){
					d[P[i]]=d[x]+E[i];
					q.push(P[i]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=H[i];j;j=X[j]){
				if(d[P[j]]==d[i]+E[j]){
					b.add(i<<1|1,P[j]<<1,inf);
				}
			}
		}
	}
}a;
#undef int
int main(){
	#define int LL
	b.tot=1;
	scanf("%lld%lld",&n,&m);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		a.add(x,y,z);a.add(y,x,z);
	}
	a.solve();
	for(int i=1,x;i<=n;i++){
		scanf("%lld",&x);
		b.add(i<<1,i<<1|1,x);
	}
	printf("%lld\n",b.solve());
	return 0;
}
