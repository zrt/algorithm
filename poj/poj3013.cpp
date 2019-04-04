#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
//by zrt
//problem:
using namespace std;
int T;
struct N{
	int x,w;
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
	N(int a=0,int b=0){
		x=a,w=b;
	}
}t;
int w[50005],n,m,x,y,z;long long d[50005];
int X[50005*3],E[50005*3],H[50005],P[50005*3],tot;
bool vis[50005];
priority_queue<N> q;
inline void add(int x,int y,int z){
	P[++tot]=y;E[tot]=z;X[tot]=H[x];H[x]=tot;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(H,0,sizeof H);
		memset(vis,0,sizeof vis);
		tot=0;
		for(int i=1;i<=n;i++) scanf("%d",&w[i]);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);add(y,x,z);
		}
		memset(d,0x3f,sizeof d);
		d[1]=0;
		q.push(N(1,0));
		while(!q.empty()){
			t=q.top();q.pop();
			if(vis[t.x]) continue;
			vis[t.x]=1;
			for(int i=H[t.x];i;i=X[i]){
				if(d[P[i]]>d[t.x]+E[i]){
					d[P[i]]=d[t.x]+E[i];
					q.push(N(P[i],d[P[i]]));
				}
			}
		}
		/*
		q.push(N(1,0));
		while(!q.empty()){
			t=q.top();q.pop();
			for(int i=H[t.x];i;i=X[i]){
				if(d[P[i]]>d[t.x]+E[i]){
					d[P[i]]=d[t.x]+E[i];
					q.push(N(P[i],d[P[i]]));
				}
			}
		}
		*/
		long long ans=0;
		int i;
		for(i=1;i<=n;i++){
			if(d[i]==0x3f3f3f3f3f3f3f3f){
				break;
			}
			ans+=d[i]*w[i];
		}
		if(i==n+1){
			printf("%lld\n",ans);
		}else{
			puts("No Answer");
		}
	}
	return 0;
}