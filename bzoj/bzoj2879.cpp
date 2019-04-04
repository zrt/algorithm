#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int last[105],num[105];
int y[105];
int H[1000],X[400005],P[400000],flow[400000],E[400000],from[400000],tot=1,belong[1000];
int cc,S,T;
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;E[tot]= k;from[tot]=x;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;E[tot]=-k;from[tot]=y;
}
int t[50][105];
int sum;
int d[1000],p[1000];
queue<int> q;
int ff;
int _cost;
const int inf=0x3f3f3f3f;
int a[1000];
bool spfa(){
	memset(d,0x3f,sizeof d);
	d[S]=0;q.push(S);a[S]=inf;
	while(!q.empty()){
		int x=q.front();q.pop();
	//	if(x==T) continue;
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]&&flow[i]>0){
				d[P[i]]=d[x]+E[i];
				a[P[i]]=min(flow[i],a[x]);
				p[P[i]]=i;
				q.push(P[i]);
			}
		}
	}
	if(d[T]==0x3f3f3f3f) return 0;
	bool enough=0;
	if(ff+a[T]>=sum) a[T]=sum-ff,enough=1;
	ff+=a[T];
	_cost+=a[T]*d[T];
	
	
	int i=belong[from[p[T]]];
	++cc;
	belong[cc]=i;
	add(cc,T,1,0);
	last[i]=tot-1;
	//printf("%d\n",flow[last[i]]);
	num[i]++;
	for(int j=1;j<=n;j++){
		add(j,cc,1,t[j][i]*num[i]);
	}
	
	
	
	int x=T;
	while(x!=S){
		flow[p[x]]-=a[T];
		flow[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	if(enough) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	S=n+1,T=n+2;
	cc=n+2;
	for(int i=1;i<=n;i++) scanf("%d",&y[i]),sum+=y[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&t[i][j]);
	for(int i=1;i<=n;i++) add(S,i,y[i],0);
	for(int i=1;i<=m;i++){
		++cc;
		belong[cc]=i;
		add(cc,T,1,0);
		last[i]=tot-1;
		num[i]++;
		for(int j=1;j<=n;j++){
			add(j,cc,1,t[j][i]*num[i]);
		}
	}
	while(1){
		spfa();
		if(ff==sum) break;
	}
	printf("%d\n",_cost);
	return 0;
}
