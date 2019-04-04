#include <cstdio>
#include <cstring>
#include <algorithm>
#include<queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int f,p;
LL INF=0x3f3f3f3f3f3f3f3f;
int ni[205],fi[205];
LL map[205][205];
int S,T;
int H[404],X[340000],P[340000],tot;
int  flow[340000];
int d[406];
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
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int sum=0;
bool judge(LL lim){
	tot=1;memset(H,0,sizeof H);
	for(int i=1;i<=f;i++){
		add(S,i<<1,ni[i]);
		add(i<<1,S,0);
		add(i<<1,i<<1|1,inf);
		add(i<<1|1,i<<1,0);
		add(i<<1|1,T,fi[i]);
		add(T,i<<1|1,0);
	}
	for(int i=1;i<=f;i++){
		for(int j=1;j<=f;j++){
			if(i!=j) {
				if(map[i][j]<=lim){
					add(i<<1,j<<1|1,inf);
					add(j<<1|1,i<<1,0);
				}
			}
		}
	}
	if(Dinic()==sum) return true;
	else return false;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d",&f,&p);
	S=0,T=1;
	
	for(int i=1;i<=f;i++) scanf("%d%d",&ni[i],&fi[i]),sum+=ni[i];
	memset(map,0x3f,sizeof map);
	for(int i=0,x,y,z;i<p;i++){
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=map[y][x]=min(map[x][y],(LL)z);
	//	map[x][y]=z;
	}
	for(int k=1;k<=f;k++){
		for(int i=1;i<=f;i++){
			if(i==k) continue;
			for(int j=1;j<=f;j++){
				if(i==j||k==j) continue;
				 map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}
		}
	}
	if(!judge(INF-1)) {
		puts("-1");
		return 0;
	}
	LL l=-1,r=INF-1,m;
	while(r-l>1){
		m=(l+r)/2;
		if(judge(m)){
			r=m;
		}else l=m;
	}
	printf("%lld\n",r);
	return 0 ;
}
