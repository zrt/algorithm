#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int k,n;
int tt; 
int to[100005];
set<int> s;
int S,T;
int ai[4050],bi[4005],wi[4050];
int H[4050],X[8000000],P[8000000],flow[8000000],cost[8000000],from[8000000],tot;
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;from[tot]=x;flow[tot]=z;cost[tot]=k;
}
int f,c;
int a[4050],d[4050],p[4050];
queue<int> q;
bool spfa(){
	memset(d,0x3f,sizeof d);
	a[S]=inf;
	d[S]=0;q.push(S);int x;
	while(!q.empty()){
		x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
				d[P[i]]=d[x]+cost[i];
				p[P[i]]=i;
				a[P[i]]=min(a[x],flow[i]);
				q.push(P[i]);
			}
		}
	//	while(!q.empty()&&d[q.top().x]!=q.top().w) q.pop();
	}
	x=T;
	if(d[T]==inf) return 0;
	f+=a[T];
	c+=a[T]*d[T];
	while(x!=S){
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tt=1;
	while(tt--){
		scanf("%d%d",&n,&k);
		s.clear();
		tot=1;memset(H,0,sizeof H);
		for(int i=0,x,y,z;i<n;i++){
			scanf("%d:%d:%d",&x,&y,&z);ai[i]=x*3600+y*60+z;
			scanf("%d:%d:%d%d",&x,&y,&z,&wi[i]);bi[i]=x*3600+y*60+z;
	//		ai[i]++;
			s.insert(ai[i]);s.insert(bi[i]);
		}
		int C=0;
		for(set<int>::iterator it=s.begin();it!=s.end();it++){
			to[*it]=++C;
		}
		C++;
		for(int i=1;i<C;i++) add(i,i+1,k,0),add(i+1,i,0,0);
		for(int i=0;i<n;i++){
			add(to[ai[i]],to[bi[i]],1,-wi[i]);
			add(to[bi[i]],to[ai[i]],0,wi[i]);
		}
		S=1,T=C;
		f=c=0;
		while(spfa());
		printf("%d\n",-c);
	}
	
	return 0 ;
}
