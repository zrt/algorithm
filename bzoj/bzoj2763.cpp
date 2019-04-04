#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k;
int H[10005],X[100005],P[100005],E[100005],tot;
int S,T;
int d[10005][11];
bool vis[10005][11];
struct N{
	int x,y,w;
	N(int a=0,int b=0,int c=0){
		x=a,y=b,w=c;
	}
	friend bool operator < (const N&a,const N&b){
		return a.w>b.w;
	}
}t;
priority_queue<N> q;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}

int main(){
	scanf("%d%d%d%d%d",&n,&m,&k,&S,&T);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	memset(d,0x3f,sizeof d);
	d[S][0]=0;
	q.push(N(S,0,0));
	while(!q.empty()){
		t=q.top();q.pop();
		if(vis[t.x][t.y]) continue;
		else vis[t.x][t.y]=1;
		if(t.y<k){
			for(int i=H[t.x];i;i=X[i]){
				if(d[P[i]][t.y+1]>d[t.x][t.y]){
					d[P[i]][t.y+1]=d[t.x][t.y];
					q.push(N(P[i],t.y+1,d[P[i]][t.y+1]));
				}
			}
		}
		for(int i=H[t.x];i;i=X[i]){
			if(d[P[i]][t.y]>d[t.x][t.y]+E[i]){
				d[P[i]][t.y]=d[t.x][t.y]+E[i];
				q.push(N(P[i],t.y,d[P[i]][t.y]));
			}
		}
	}
	int ans=0x7fffffff;
	for(int i=0;i<=k;i++) ans=min(ans,d[T][i]);
	printf("%d\n",ans);
	return 0;
}
