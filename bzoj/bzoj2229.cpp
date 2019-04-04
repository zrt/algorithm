#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int tt,n,m;
int H[155],X[10000],P[10000],tot,flow[10000];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
bool vis[155];
int ans[155][155];
int a[155];
int S,T;
void init(){
	for(int i=2;i<=tot;i+=2) flow[i]=flow[i^1]=(flow[i]+flow[i^1])/2;
}
int d[155];
queue<int> q;
const int inf=0x3f3f3f3f;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(!d[P[i]]&&flow[i]>0){
				d[P[i]]=d[x]+1;q.push(P[i]);
			}
		}
	}
	return d[T];
}
int dfs(int x,int a){
	if(x==T||a==0) return a;
	int tmp,f=a;
	for(int i=H[x];i;i=X[i]){
		if(d[P[i]]==d[x]+1&&flow[i]>0){
			tmp=dfs(P[i],min(a,flow[i]));
			flow[i]-=tmp;
			a-=tmp;
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
int list[155],t;
void solve(int l,int r){
	if(l==r) return;
	//printf("%d %d\n",l,r);
	init();
	S=a[l],T=a[r];
	int f=Dinic();
	bfs();
	for(int i=1;i<=n;i++){
		if(d[i]){
			for(int j=1;j<=n;j++){
				if(!d[j]){
					ans[i][j]=ans[j][i]=min(ans[i][j],f);
				}
			}
		}
	}
	t=0;
	for(int i=l;i<=r;i++) if(d[a[i]]) list[t++]=a[i];
	int p=0;
	for(int i=l;i<=r;i++) if(!d[a[i]]) a[l+p]=a[i],p++;
	for(int i=l+p;i<=r;i++) a[i]=list[i-l-p];
	solve(l,l+p-1);solve(l+p,r);
}
int main(){
//	freopen("in","r",stdin);
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%d",&n,&m);
		tot=1;
		memset(H,0,sizeof H);
		memset(ans,0x3f,sizeof ans);
		for(int i=0,x,y,z;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);add(y,x,z);
		}
		for(int i=1;i<=n;i++) a[i]=i;
		solve(1,n);
		int q;
		scanf("%d",&q);
		while(q--){
			int d,Ans=0;
			scanf("%d",&d);
			for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(ans[i][j]<=d) Ans++;
			printf("%d\n",Ans);
			
		}
		puts("");
	}
	return 0;
}
