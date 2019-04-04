#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
int get(int x,int y){
	return (x-1)*m+y;
}
int a[105][105];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
const int inf =0x3f3f3f3f;
int sum;
int H[10005],X[200050],P[200050],flow[200050],tot=1;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;
}
int d[10005];
int S=10003,T=10004;
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]) d[P[i]]=d[x]+1,q.push(P[i]);
		}
	}
	return d[T];
}
int dfs(int x,int a){
	if(x==T||a==0) return a;
	int tmp,f=a;
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
	return f-a;
}
int Dinic(){
	int ret=0;
	while(bfs()) ret+=dfs(S,inf);
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) scanf("%d",&a[i][j]),sum+=a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((i+j)&1){
				add(S,get(i,j),a[i][j]);
				for(int k=0;k<4;k++){
					int x=dx[k]+i;
					int y=dy[k]+j;
					if(x>0&&x<=n&&y>0&&y<=m){
						add(get(i,j),get(x,y),inf);
					}
				}
			}else add(get(i,j),T,a[i][j]);
		}
	}
	int ans=Dinic();
	printf("%d\n",sum-ans);
	return 0;
}
