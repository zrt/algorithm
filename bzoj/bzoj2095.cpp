#include <cstdio>
#include <cstring>
#include <algorithm>
#include<queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x3fffffff) ;
int n,m;
#define MAX_N 1050
#define MAX_M 2050
int H[MAX_N],X[MAX_M*2],P[MAX_M*2],E[MAX_M*2],tot;
bool vis[MAX_M*2];
int ind[MAX_N],outd[MAX_N];
int minn,maxx;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int _H[MAX_N],_X[MAX_M*3],_P[MAX_M*3],flow[MAX_M*3],_tot;
inline void _add(int x,int y,int z){
	_P[++_tot]=y;_X[_tot]=_H[x];_H[x]=_tot,flow[_tot]=z;
}
int S,T;
queue<int> q;
int d[MAX_N];
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;
	q.push(S);int k;
	while(!q.empty()){
		k=q.front();q.pop();
		for(int i=_H[k];i;i=_X[i]){
			if(flow[i]>0&&!d[_P[i]]){
				d[_P[i]]=d[k]+1;
				q.push(_P[i]);
			}
		}
	}
	return d[T];
}
int dfs(int x,int a){
	if(x==T||a==0) return a;
	int f=a,tmp;
	for(int i=_H[x];i&&a;i=_X[i]){
		if(flow[i]>0&&d[x]+1==d[_P[i]]){
			tmp=dfs(_P[i],min(a,flow[i]));
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			a-=tmp;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int dinic(){
	int maxflow(0);
	while(bfs()) maxflow+=dfs(S,inf);
	return maxflow;
}
bool judge(int limit){
	memset(ind,0,sizeof ind);memset(outd,0,sizeof outd);memset(vis,0,sizeof vis);_tot=1;
	memset(_H,0,sizeof _H);
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if(E[j]>limit&&E[j^1]>limit) return false;
			if(!vis[j]&&!vis[j^1]&&E[j]<=limit){
				vis[j]=1;
				outd[i]++;ind[P[j]]++;
			}
		}
	}
	int fs(0);
	for(int i=1;i<=n;i++){
		if((outd[i]-ind[i])&1) return false;
		if(ind[i]>outd[i]){
			fs+=(ind[i]-outd[i])>>1;
			_add(S,i,(ind[i]-outd[i])>>1);
			_add(i,S,0);
		}else if(ind[i]!=outd[i]){
			_add(i,T,(outd[i]-ind[i])>>1);
			_add(T,i,0);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if(!vis[j]&&E[j]<=limit){
				_add(i,P[j],1);
				_add(P[j],i,0);
			}
		}
	}
	if(dinic()!=fs) return false ;
	else return true;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d",&n,&m);
	S=n+1,T=n+2;
	tot=1;
	minn=inf,maxx=-inf;
	for(int i=0,a,b,c,d;i<m;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		minn=min(minn,min(c,d));
		maxx=max(maxx,max(c,d));
		add(a,b,c);add(b,a,d);
	}
	int l=minn-1,r=maxx;
	if(!judge(r)) printf("NIE");
	else{
		int m;
		while(r-l>1){
			m=(l+r)>>1;
			if(judge(m)){
				r=m;
			}else l=m;
		}
		printf("%d\n",r);
	}
	return 0 ;
}
