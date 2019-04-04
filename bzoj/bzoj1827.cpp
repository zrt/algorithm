#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int H[100005],X[200005],P[200005],E[200005];
int tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int c[100005];
int n;
typedef long long LL;
LL ans[100005];
LL sum[100005],num[100005];

void dp1(int x,int fa){
	num[x]=c[x];
	sum[x]=0;
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa) continue;
		dp1(P[i],x);
		num[x]+=num[P[i]];
		sum[x]+=sum[P[i]]+num[P[i]]*E[i];
	}
}
LL SUM;
void dp2(int x,int fa,int edge){
	if(!fa) ans[x]=sum[x];
	else ans[x]=ans[fa]-num[x]*edge+(SUM-num[x])*edge;
	for(int i=H[x];i;i=X[i]){
		if(fa==P[i]) continue;
		dp2(P[i],x,E[i]);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]),SUM+=c[i];
	for(int i=1,x,y,z;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dp1(1,0);
	dp2(1,0,0);
	LL minn=1LL<<50;
	for(int i=1;i<=n;i++) minn=min(minn,ans[i]);
	printf("%lld\n",minn);
	return 0;
}
