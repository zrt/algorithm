#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n;
int H[200005],X[400005],P[400005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}

int a[200005];

int siz[200005];
LL sum[200005];
int dep[200005];

void dfs(int x,int fa){
	siz[x] = 1;
	sum[x] = a[x];
	for(int i=H[x];i;i=X[i]){
		if(fa==P[i]) continue;
		dep[P[i]] = dep[x]+1;
		dfs(P[i],x);
		siz[x]+=siz[P[i]];
		sum[x]+=sum[P[i]];
	}
}
LL mx;
void dfs2(int x,int fa,LL ans){
	mx = max(mx,ans);
	for(int i=H[x];i;i=X[i]){
		if(fa==P[i]) continue;

		dfs2(P[i],x, ans - sum[P[i]] + sum[1] - sum[P[i]]);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}

	dfs(1,0);
	LL ans =0;
	for(int i=1;i<=n;i++) ans += dep[i]*1LL*a[i];
	dfs2(1,0,ans);
	cout<<mx<<endl;

	return 0;
}