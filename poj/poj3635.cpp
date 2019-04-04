#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue> 
//by zrt
//problem:
using namespace std;
int n,m,w[1005],Q,c,s,e;
int H[1005],X[20005],P[20005],E[20005],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int x,y,z;
int d[1005][105];
int vis[1005][105];
struct N{
	int x,y,w;
	N(int a=0,int b=0,int c=0){
		x=a,y=b,w=c;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){//!
		scanf("%d",&w[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	scanf("%d",&Q);
	N t;
	while(Q--){
		scanf("%d%d%d",&c,&s,&e);
		memset(d,0x7f,sizeof d);
		memset(vis,0,sizeof vis);
		while(!q.empty()) q.pop();
		d[s][0]=0;
		q.push(N(s,0,0));
		while(!q.empty()){
			t=q.top();q.pop();
			if(t.x==e){
				printf("%d\n",t.w);goto ed;
			}
			if(vis[t.x][t.y]) continue;else vis[t.x][t.y]=1;
			if(t.y<c) {
				if(!vis[t.x][t.y+1]&&d[t.x][t.y+1]>d[t.x][t.y]+w[t.x]){
					d[t.x][t.y+1]=d[t.x][t.y]+w[t.x];
					q.push(N(t.x,t.y+1,d[t.x][t.y+1]));
				}
			}
			for(int i=H[t.x];i;i=X[i]){
				if(t.y>=E[i]){
					if(!vis[P[i]][t.y-E[i]]&&d[P[i]][t.y-E[i]]>d[t.x][t.y]){
						d[P[i]][t.y-E[i]]=d[t.x][t.y];q.push(N(P[i],t.y-E[i],d[P[i]][t.y-E[i]]));
					}
				}
			}
		}
		if(1){
			printf("impossible\n");
		}
		ed:;
	}
	return 0;
}
