#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int n,k;
int H[505],X[10005],P[10005];
int tot;
int link[505],vis[505];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool dfs(int x){
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			vis[P[i]]=1;
			int q=link[P[i]];
			if(q==-1||dfs(q)){
				link[P[i]]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	for(int i=0,x,y;i<k;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	int ans=0;
	memset(link,-1,sizeof link);
	for(int i=1;i<=n;i++) {
		if(dfs(i)) ans++;
		memset(vis,0,sizeof vis);
	}
	printf("%d\n",ans);
	return 0;
}
