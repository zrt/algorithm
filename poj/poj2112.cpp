#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x7fffffff) ;
int H[240],X[14000],P[14000],flow[14000],tot,M,n,k,c;
int d[240][240];
void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int S,T;
int D[240];
#include<queue>
queue<int> q;
bool bfs(){
	memset(D,0,sizeof D);
	D[S]=1;
	int t;
	q.push(S);
	while(!q.empty()){
		t=q.front();q.pop();
		for(int i=H[t];i;i=X[i]){
			if(flow[i]>0&&!D[P[i]]){
				D[P[i]]=D[t]+1;
				q.push(P[i]);
			}
		}
	}
	return D[T];
}
int dfs(int x,int a){
	if(a==0||x==T) return a;
	int f=a,tmp;
	for(int i=H[x];i&&a;i=X[i]){
		if(D[P[i]]==D[x]+1&&flow[i]>0){
			tmp=dfs(P[i],min(a,flow[i]));
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			a-=tmp;
		}
	}
	if(f==a) D[x]=-1;
	return f-a;
}
int dinic(){
	int f(0);
	while(bfs()){
		f+=dfs(S,1<<20);
	}
	return f;
}
bool judge(int limit){
	tot=1;
	memset(H,0,sizeof H);
	for(int i=1;i<=k;i++){
		add(i,T,M);add(T,i,0);
	}
	for(int i=k+1;i<=n;i++){
		add(S,i,1);add(i,S,0);
	}
	for(int i=k+1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(d[i][j]<=limit){
				add(i,j,1);add(j,i,0);
			}
		}
	}
	if(dinic()!=c) return false;
	else return true;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d%d",&k,&c,&M);
	n=k+c;
	S=0,T=n+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&d[i][j]);
			if(!d[i][j]) d[i][j]=inf>>2;
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	
	int l=0,r=22000,m;
	while(r-l>1){
		m=(l+r)>>1;
		if(judge(m)){
			r=m;
		}else l=m;
	}
	printf("%d\n",r);
	return 0 ;
}