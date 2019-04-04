#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
typedef long double ld;
int n,m;
int w[55][55];
int get(int x,int y){
	return (x)*(m+2)+y;
}
int a[55][55];
int b[55][55];
int H[3000],X[400000],P[400000],tot;
ld flow[300000];
inline void add(int x,int y,ld z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;
}
int S=2998,T=2999;
ld sum;
int d[3000];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	q.push(S);
	d[S]=1;
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
ld dfs(int x,ld a){
	if(x==T||fabs(a)<1e-10) return a;
	ld tmp,f=a;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(flow[i],a));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(fabs(a)<1e-10) break;
		}
	}
	if(fabs(f-a)<1e-10) d[x]=-1;
//	printf("$$%d %.3f\n",x,(double)(f-a));
	return f-a;
}
ld Dinic(){
	ld ret=0;
	while(bfs()) ret+=dfs(S,1e6);
	return ret;
}
bool judge(ld k){
	tot=1;
	memset(H,0,sizeof H);
	for(int i=1;i<=m;i++) add(get(0,i),T,1e6),add(get(n+1,i),T,1e6);
	for(int i=1;i<=n;i++) add(get(i,0),T,1e6),add(get(i,m+1),T,1e6);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) add(S,get(i,j),w[i][j]);
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m;j++) add(get(i-1,j),get(i,j),a[i][j]*k),add(get(i,j),get(i-1,j),a[i][j]*k);
	for(int i=1;i<=n;i++) for(int j=1;j<=m+1;j++) add(get(i,j-1),get(i,j),b[i][j]*k),add(get(i,j),get(i,j-1),b[i][j]*k);
	double kk=Dinic();
//	printf("%.3f\n",kk);
	return sum-kk>0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&w[i][j]),sum+=w[i][j];
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m+1;j++) scanf("%d",&b[i][j]);
	ld l=0,r=50*50*100;
	for(int i=0;i<=33;i++){
		ld mid=(l+r)/2;
		if(judge(mid)) l=mid;
		else r=mid;
	}
	printf("%.3f\n",(double)l);
	return 0;
}
