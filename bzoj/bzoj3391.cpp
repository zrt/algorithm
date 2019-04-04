#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int H[10005],X[20005],P[20005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int n;
int mx[10005],sum[10005];
void dfs(int x,int fa){
	sum[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa){
			dfs(P[i],x);
			sum[x]+=sum[P[i]];
			mx[x]=max(mx[x],sum[P[i]]);
		}
	}
	mx[x]=max(mx[x],n-sum[x]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,-1);
	bool ok=0;
	for(int i=1;i<=n;i++){
		if(mx[i]<=n/2) printf("%d\n",i),ok=1;
	}
	if(!ok) puts("NONE");
	return 0;
}
