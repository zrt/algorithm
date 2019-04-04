#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,t;
int H[25050],X[2455000],P[2455000],flow[2455000],tot=1;
int x[2455],y[2455],z[2455];
const int inf= 0x3f3f3f3f;
int S=25048,T=25049;
inline void add(int x,int y,int z){
//	printf("%d %d %d\n",x,y,z);
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;
}
int F;
int d[25050];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(!d[P[i]]&&flow[i]>0){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	return d[T];
}
int dfs(int x,int a){
	if(x==T||a==0) return a;
	int tmp,f=a;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(flow[i],a));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
void Dinic(){
	while(bfs()) F+=dfs(S,inf);
}
int main(){
	scanf("%d%d%d",&n,&m,&t);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	}
	int mx=n+t;
	for(int i=0;i<=mx;i++){
		for(int j=0;j<m;j++){
			add(x[j]+i*n,y[j]+(i+1)*n,z[j]);
		}
		for(int j=1;j<=n;j++) add(i*n+j,(i+1)*n+j,inf); 
	}
	add(S,1,t);
//	add(n,T,inf);
	for(int i=0;i<=mx;i++){
		add((i+1)*n+n,T,inf);
		Dinic();
	//	printf("%d\n",F);
		if(F==t){
			printf("%d\n",i+1);break;
		}
	}
	return 0;
}
