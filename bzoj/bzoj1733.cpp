#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n,m,t;
int S,T;
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
vector<N> v[205];
int H[205],X[80005],P[80005],tot,flow[80005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[205];
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
	while(f<=t&&bfs()) f+=dfs(S,t);
	return f;
}
bool judge(int lim){
	tot=1;
	memset(H,0,sizeof H);
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			if(v[i][j].w<=lim){
				add(i,v[i][j].x,1);
				add(v[i][j].x,i,1);
			}
		}
	}
	if(Dinic()>=t) return 1;
	else return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d%d",&n,&m,&t);
	S=1,T=n;
	int l=0,r=1e6+1,M;
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(N(y,z));
	}
	while(r-l>1){
		M=(l+r)>>1;
		if(judge(M)){
			r=M;
		}else l=M;
	}
	printf("%d\n",r);
	return 0 ;
}
