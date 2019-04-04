#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int n,w;
int c[20];
int ans;
int v[20];
void dfs(int pos,int tot){
	if(tot>=ans) return;
	if(pos==n+1) {
		ans=tot;return;
	}
	for(int i=1;i<=tot;i++){
		if(w-v[i]>=c[pos]){
			v[i]+=c[pos];
			dfs(pos+1,tot);
			v[i]-=c[pos];
		}
	}
	v[tot+1]=c[pos];
	dfs(pos+1,tot+1);
	v[tot+1]=0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	ans=20;
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
