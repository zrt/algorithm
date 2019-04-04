#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<bitset>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int k,n,m;
int H[1005],tot,P[10005],X[10005];
bitset<1005> sum[105];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool is[1005];
void dfs(int x,int a){
	sum[a][x]=1;
	for(int i=H[x];i;i=X[i]) if(!sum[a][P[i]]) dfs(P[i],a);
}
int num[105];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=k;i++){
		scanf("%d",&num[i]);
	}
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=k;i++){
		dfs(num[i],i);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bool ok=1;
		for(int j=1;j<=k;j++){
			if(!sum[j][i]) {
				ok=0;break;
			}
		}
		if(ok) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
