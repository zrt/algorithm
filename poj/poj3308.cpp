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
int tt,m,n,L;
int H[105],X[12005],P[12005],tot;
double flow[12005];
int S,T;
inline void add(int x,int y,double z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
double h[55],l[55];
int d[105];
double sum;
/*
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
double dfs(int x,double a){
	if(x==T||fabs(a)<eps) return a;
	double f=a,tmp;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(a,flow[i]));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(fabs(a)<eps) break;
		}
	}
	if(fabs(f-a)<eps) d[x]=-1;
	return f-a;
}
double Dinic(){
	double f(0.0);
	while(bfs()) f+=dfs(S,1e6);
	return f;
}

int d[1205];*/
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
double dfs(int x,double a){
	double f=a,tmp;
	if(x==T||a==0) return a;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(a,flow[i]));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(fabs(a)<eps) break;
		}
	}
	if(fabs(f-a)<eps) d[x]=-1;
	return f-a;
}
double Dinic(){
	double f=0;
	while(bfs()) f+=dfs(S,sum);
	return f;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%d%d",&m,&n,&L);
		S=0,T=m+n+1;
		sum=0;
		tot=1;memset(H,0,sizeof H);
		for(int i=1;i<=m;i++){
			scanf("%lf",&h[i]),h[i]=log(h[i]);add(S,i,h[i]),add(i,S,0);sum+=h[i];
		}
		for(int i=1;i<=n;i++){
			scanf("%lf",&l[i]);l[i]=log(l[i]);add(i+m,T,l[i]),add(T,i+m,0);sum+=l[i];
		}
		for(int i=0,x,y;i<L;i++){
			scanf("%d%d",&x,&y);
			add(x,y+m,1e10);
			add(y+m,x,0);
		}
		printf("%.4f\n",exp(Dinic()));
	}
	return 0 ;
}
