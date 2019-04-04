#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n,m;
int H[205],P[10500],X[10500],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool vis[205];
void dfs(int x){
	vis[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]) dfs(P[i]);
	}
}
int link[205];
bool cover[205];
bool find(int k){
	for(int i=H[k];i;i=X[i]){
		if(!cover[P[i]]){
			int q=link[P[i]];
			link[P[i]]=k;
			cover[P[i]]=1;
			if(q==-1||find(q)) return 1;
			link[P[i]]=q;
		}
	}
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);add(x,y);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		dfs(i);
		H[i]=0;
		for(int j=1;j<=n;j++){
			if(j!=i&&vis[j]) add(i,j);
		}
	}
	memset(link,-1,sizeof link);
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(cover,0,sizeof cover);
		if(find(i)) ans++;
	}
	printf("%d\n",n-ans);
	return 0;
}
