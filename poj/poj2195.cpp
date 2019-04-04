#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
int n,m;
int hx[105],hy[105],mx[105],my[105];
int num;
const int inf=0x3f3f3f3f;
char s[105][105];
int tot1,tot2;
int H[205],P[22010],X[22010],cost[22010],from[22010],flow[22010],tot;
int S,T;
inline void add(int x,int y,int cst){
	P[++tot]=y;from[tot]=x;cost[tot]=cst;X[tot]=H[x];H[x]=tot;flow[tot]=1;
	P[++tot]=x;from[tot]=y;cost[tot]=-cst;X[tot]=H[y];H[y]=tot;flow[tot]=0;
}
int d[205],p[205],a[205];
int f,c;
struct N{
	int x,w;
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
priority_queue<N> q;
bool spfa(){
	while(!q.empty()) q.pop();
	memset(d,0x3f,sizeof d);
	d[S]=0,p[S]=0,a[S]=inf;
	int u;q.push(N(S,0));
	while(!q.empty()){
		u=q.top().x;q.pop();
		for(int i=H[u];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[u]+cost[i]){
				d[P[i]]=d[u]+cost[i];
				a[P[i]]=min(a[u],flow[i]);
				p[P[i]]=i;
				q.push(N(P[i],d[P[i]]));
			}
		}
		while(!q.empty()&&d[q.top().x]!=q.top().w) q.pop();
	}
	if(d[T]==inf) return false;
	f+=a[T];
	c+=a[T]*d[T];
	u=T;
	while(u!=S){
		flow[p[u]]-=a[T];
		flow[p[u]^1]+=a[T];
		u=from[p[u]];
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	S=201,T=202;
	while(scanf("%d%d",&n,&m),n|m){
		tot=1;tot1=tot2=0;memset(H,0,sizeof H);
		for(int i=0;i<n;i++) scanf("%s",s[i]);
		for(int i=0;i<n;i++) for(int j=0;j<m;j++){
			if(s[i][j]=='H'){
				tot1++;hx[tot1]=i;hy[tot1]=j;
			}
			if(s[i][j]=='m'){
				tot2++;mx[tot2]=i;my[tot2]=j;
			}
		}
		num=tot1;//s..0 t..201
		for(int i=1;i<=num;i++){//1...100
			for(int j=1;j<=num;j++){//+101...200
				add(i,j+100,abs(hx[i]-mx[j])+abs(hy[i]-my[j]));
			}
		}
		//wij bianquan
		for(int i=1;i<=num;i++){
			add(S,i,0);add(i+100,T,0);
		}
		//mincostmaxflow
		f=c=0;
		while(spfa());
		printf("%d\n",c);
	}
	
	return 0;
}