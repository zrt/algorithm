#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m;
char s[105][105];
const int inf=0x3f3f3f3f;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int num(int i,int j){
	// 0..m-1
	return (i-1)*m+j-1;
}
int H[10005],X[100050],P[100050],flow[100050],tot=1;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;
}
vector<int> ans;
queue<int> q;
int d[10005],S=10003,T=10004;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(!d[P[i]]&&flow[i]>0){
				q.push(P[i]);d[P[i]]=d[x]+1;
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
void Dinic(){
	while(bfs()) dfs(S,inf);
}
bool vis[10005];
void dfs1(int x){
	if(x<n*m){
		if((x/m+x%m)&1) ans.push_back(x);
	}
	vis[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&!vis[P[i]]){
			dfs1(P[i]);
		}
	}
}
void dfs2(int x){
	
	if(x<n*m){
		if(!((x/m+x%m)&1)) ans.push_back(x);
	}
	vis[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(flow[i^1]>0&&!vis[P[i]]){
			dfs2(P[i]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((i+j)&1){
				if(s[i][j]=='.'){
					for(int k=0;k<4;k++){
						int x=dx[k]+i,y=dy[k]+j;
						if(x>=1&&x<=n&&y>=1&&y<=m){
							if(s[x][y]=='.'){
								add(num(i,j),num(x,y),1);
							}
						}
					}
					add(S,num(i,j),1);
				}
			}else if(s[i][j]=='.') add(num(i,j),T,1);
		}
	}
	Dinic();
	dfs1(S);
	memset(vis,0,sizeof vis);
	dfs2(T);
	if(ans.size()>0){
		puts("WIN");
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++){
			printf("%d %d\n",ans[i]/m+1,ans[i]%m+1);
		}
	}else{
		puts("LOSE");
	}
	return 0;
}
