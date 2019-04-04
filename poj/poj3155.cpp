#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-18) ;
const int inf(0x3f3f3f3f) ;
int n,m;
int H[1205],X[5000000],P[5000000],tot;
double flow[5000000];
inline void add(int x,int y,double z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
vector<int> v[205];
vector<int> point;
int num;
int S,T;
int d[1205];
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
	while(bfs()) f+=dfs(S,m+10);
	return f;
}
bool judge(double x){// -x
	tot=1;memset(H,0,sizeof H);
	double sum=m;
	num=n;
	for(int i=1;i<=n;i++){
		int siz=v[i].size();
		add(i,T,x);
		add(T,i,0);
		for(int j=0;j<siz;j++){
			num++;
			add(i,num,0);
			add(num,i,inf);
			add(num,v[i][j],inf);
			add(v[i][j],num,0);
			add(S,num,1);
			add(num,S,0);
		}
	}
	double ans=sum-Dinic();
//	printf("#%.3f\n",ans);
	if(ans>0) return true;
	else return false;
}
bool vis[1205];
void dfs1(int x){
	vis[x]=1;point.push_back(x);
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]&&flow[i]>0) dfs1(P[i]);
	}
}
void solve(){
	dfs1(S);
	int num(0);
	for(int i=0;i<point.size();i++){
		if(point[i]>0&&point[i]<=n) num++;
	}
	if(num==0){
		puts("1\n1");
		return ;
	}
	printf("%d\n",num);
	sort(point.begin(),point.end());
	for(int i=0;i<point.size();i++){
		if(point[i]>0&&point[i]<=n) printf("%d\n",point[i]);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d",&n,&m);
	S=0,T=n+m+2;
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
	}
	double l=0,r=m,M;
	for(int tt=0;tt<30;tt++){
		M=(l+r)/2.0;
		if(judge(M)) l=M;
		else r=M;
	}
	judge(l-eps);
	solve();
	return 0 ;
}
