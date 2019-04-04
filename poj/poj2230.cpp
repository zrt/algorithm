#include <cstdio>
#include <cstring>
#include <algorithm>

//by zrt
//problem:
using namespace std;
const int inf(0x3f3f3f3f) ;
const double eps(1e-10) ;
typedef long long LL;
int n,m;
int H[10005],X[100005],P[100005],tot;
bool vis[100005];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
void dfs(int x){	
	for(int i=H[x];i;i=X[i]){
		if(!vis[i]){
	//		printf("%d\n",x);
			vis[i]=1;
			dfs(P[i]);
		}
	}
	printf("%d\n",x);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	tot=1;
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
	//	add(x,y);
		add(x,y);add(y,x);
	}
//	printf("%d\n",1);
	dfs(1);
	return 0;
}
