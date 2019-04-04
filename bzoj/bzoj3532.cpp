#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int tt;
int f[705];
int a[705],pos[705],b[705],c[705];
int id[705];
int n;
bool cmp(int a,int b){
	return c[a]<c[b];
}
int H[1650],X[1650*1650],P[1650*1650],flow[1650*1650],tot;
int S,T;
const int inf=0x3f3f3f3f;
vector<int> ans;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
	P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;
}
int d[1650];
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
	int ret=0;
	while(bfs()) ret+=dfs(S,inf);
	return ret;
}
int main(){
	scanf("%d",&tt);
	while(tt--){
		tot=1;int mx=0;
		S=1648,T=1649;
		memset(H,0,sizeof H);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
		}
		for(int i=1;i<=n;i++) id[i]=i;
		sort(id+1,id+n+1,cmp);
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				if(a[j]<a[i]) f[i]=max(f[i],f[j]+1);
			}
			mx=max(mx,f[i]);
		}
	
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]<a[j]&&f[i]+1==f[j]){
					add(i<<1|1,j<<1,inf);
				}
			}
			if(f[i]==mx){
				add(i<<1|1,T,inf);
			}
			if(f[i]==1) add(S,i<<1,inf);
			add(i<<1,i<<1|1,b[i]);
			pos[i]=tot-1;
		}
		int Ans=Dinic();
		for(int i=1;i<=n;i++){
			if(!flow[pos[id[i]]]){
				S=id[i]<<1;
				T=id[i]<<1|1;
				if(!bfs()){
					ans.push_back(id[i]);
					flow[pos[id[i]]^1]=0;
					S=1649,T=id[i]<<1|1;
					Dinic();
					S=id[i]<<1,T=1648;
					Dinic();
				}
			}
		}
		printf("%d %u\n",Ans,ans.size());
		sort(ans.begin(),ans.end());
		bool ok=1;
		for(int i=0;i<ans.size();i++){
			if(ok) ok=0;else putchar(' ');
			printf("%d",ans[i]);
		}
		puts("");
		ans.clear();
	}
	
	return 0;
}
