#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,k;
char s[55][55];
int H[205],X[100000],P[100000],flow[100000],tot=1;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int S=203,T=204;
int d[205];
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
int dfs(int x,int f){
	if(x==T||f==0) return f;
	int a=f,tmp;
	for(int i=H[x];i;i=X[i]){
		if(d[P[i]]==d[x]+1&&flow[i]>0){
			tmp=dfs(P[i],min(flow[i],a));
			flow[i]-=tmp;
			a-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int ff;
int Dinic(){
	while(bfs()) ff+=dfs(S,105);
	return ff;
}
int ans;
void solve(){
	while(1){
		for(int i=1;i<=n;i++){
			add(S,i<<1,1);
			add(i<<1,S,0);
			add((i+n)<<1,T,1);
			add(T,(i+n)<<1,0);
		}
		if(Dinic()<n*(ans+1)) break;
		else ans++;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		add(i<<1,i<<1|1,k);
		add(i<<1|1,i<<1,0);
		add((i+n)<<1|1,(i+n)<<1,k);
		add((i+n)<<1,(i+n)<<1|1,0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]=='Y'){
				add(i<<1,(j+n)<<1,1);
				add((j+n)<<1,i<<1,0);
			}else{
				add(i<<1|1,(j+n)<<1|1,1);
				add((j+n)<<1|1,i<<1|1,0);
			}
		}
	}
	solve();
	printf("%d\n",ans);
	return 0;
}
