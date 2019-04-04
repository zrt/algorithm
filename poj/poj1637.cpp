#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int tt;
struct edge{
	int x,y,z;
}e[1005];
int S,T;
int in[201],out[201];
int H[205],X[4005],P[4005],flow[4006];
int tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[206];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);
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
	int f=a,tmp;
	if(x==T||a==0) return a;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(a,flow[i]));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
//	printf("%d\n",f-a);
	return f-a;
}
int Dinic(){
	int f=0;
	while(bfs()) f+=dfs(S,inf);
	return f;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d",&tt);
	S=201,T=202;
	while(tt--){
		int n,m;
		memset(H,0,sizeof H);
		memset(in,0,sizeof in);
		memset(out,0,sizeof out);
		tot=1;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
			in[e[i].y]++;
			out[e[i].x]++;
		}
		int sum(0);
		for(int i=1;i<=n;i++){
			if(abs(in[i]-out[i])&1) {
				puts("impossible");
				goto ed;
			}
			if(in[i]>out[i]){
				add(S,i,(in[i]-out[i])>>1);
				sum+=(in[i]-out[i])>>1;
				add(i,S,0);
			}else if(out[i]>in[i]){
				add(i,T,(out[i]-in[i])>>1);
				add(T,i,0);
			}
		}
		for(int i=0;i<m;i++){
			if(e[i].z==0){
				add(e[i].y,e[i].x,1);
				add(e[i].x,e[i].y,0);
			}
		}
		if(Dinic()==sum){
			puts("possible");
		}else puts("impossible");
		ed:;
	}
	return 0 ;
}
