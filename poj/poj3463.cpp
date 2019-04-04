#include<cstdio>
#include<cstring>
//by zrt
//problem:
using namespace std;
int T,n,m,x,y,z;
int H[1005],P[10005],X[10005],E[10005],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int d[1005][2];
int cnt[1005][2];
bool vis[1005][2];
//int fa[1005];
int S,F;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
	//	while(!q.empty()) q.pop();
		memset(H,0,sizeof H);tot=0;
		memset(d,0x7f,sizeof d);
		memset(vis,0,sizeof vis);
		memset(cnt,0,sizeof cnt);
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
		}
		scanf("%d%d",&S,&F);
		d[S][0]=0;cnt[S][0]=1;
		for(int i=0;i<n*2;i++){
			int t=1<<30,kind,v;
			for(int j=1;j<=n;j++){
				if(!vis[j][0]&&t>d[j][0]){
					t=d[j][0];v=j;kind=0;
				}
				else if(!vis[j][1]&&t>d[j][1]){
					t=d[j][1];v=j;kind=1;
				}
			}
			if(t==1<<30) break;
			vis[v][kind]=1;
			for(int i=H[v];i;i=X[i]){//！！！！！更新最短路时要同时更新次短路。还要更新次数 
				if(d[v][kind]+E[i]<d[P[i]][0]){
					 d[P[i]][1]=d[P[i]][0],cnt[P[i]][1]=cnt[P[i]][0];d[P[i]][0]=d[v][kind]+E[i],cnt[P[i]][0]=cnt[v][kind];
				} 
				else if(d[v][kind]+E[i]==d[P[i]][0]) cnt[P[i]][0]+=cnt[v][kind];
				else if(d[v][kind]+E[i]<d[P[i]][1]) d[P[i]][1]=d[v][kind]+E[i],cnt[P[i]][1]=cnt[v][kind];
				else if(d[v][kind]+E[i]==d[P[i]][1]) cnt[P[i]][1]+=cnt[v][kind];
			}
		}
		int ans=cnt[F][0];
		if(d[F][1]==d[F][0]+1) ans+=cnt[F][1];
		printf("%d\n",ans);
	} 
	return 0;
}
