#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
//by zrt
//problem:
using namespace std;
int T,n,dis[505][505];
bool vis[505];
int d[505];
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
}t;
priority_queue<N> q;
int ans;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&dis[i][j]);
			}
		}
		memset(d,0x7f,sizeof d);
		memset(vis,0,sizeof vis);
		ans=0;
		d[1]=0;q.push(N(1,0));
		while(!q.empty()){
			t=q.top();q.pop();
			if(vis[t.x]) continue;
			else vis[t.x]=1;
			if(t.w>ans) ans=t.w;
			for(int i=1;i<=n;i++){
				if((!vis[i])&&dis[t.x][i]<d[i]){
					d[i]=dis[t.x][i];
					q.push(N(i,d[i]));
				}
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
