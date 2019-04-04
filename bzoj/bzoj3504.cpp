#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
int n,a1,a2,an,b1,b2,bn;
char s[55][55];
int H[55],X[25000],P[25000],flow[25000],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;
}
int d[55];
int S=53,T=54;
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);
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
	int f=a,tmp;
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
int Dinic(){
	int f=0;
	while(bfs()) f+=dfs(S,inf);
	return f;
}
bool solve(int a1,int a2,int b1,int b2){
	tot=1;
	memset(H,0,sizeof H);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(s[i][j]=='N') add(i,j,inf),add(j,i,inf);
			else if(s[i][j]=='O') add(i,j,2),add(j,i,2);
		}
	}
	add(S,a1,2*an);
	add(S,b1,2*bn);
	add(a2,T,2*an);
	add(b2,T,2*bn);
	return Dinic()==2*an+2*bn;
}
int main(){
	while(~scanf("%d%d%d%d%d%d%d",&n,&a1,&a2,&an,&b1,&b2,&bn)){
		for(int i=0;i<n;i++) scanf("%s",s[i]);
		if(solve(a1,a2,b1,b2)&&solve(a1,a2,b2,b1)) puts("Yes");
		else puts("No");
	}
	return 0;
}
