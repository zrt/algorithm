#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int H[100005],X[1000005],P[1000005];
int tot,n,m;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int tim,low[100005],dfn[100005],v[100005],siz[100005];
long long ans[100005];
void tarjan(int x,int fa){
	low[x]=dfn[x]=++tim;
	siz[x]=1;
	long long sum=0;
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa) continue;
		if(!dfn[P[i]]){
			tarjan(P[i],x);
			siz[x]+=siz[P[i]];
			low[x]=min(low[x],low[P[i]]);
			if(low[P[i]]>=dfn[x]){
				ans[x]+=siz[P[i]]*sum;
				sum+=siz[P[i]];
			}
		}else low[x]=min(low[x],low[P[i]]);
	}
	ans[x]+=sum*(n-sum-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	tarjan(1,0);
	for(int i=1;i<=n;i++){
		printf("%lld\n",(ans[i]+n-1)*2);
	}

//	while(1);
	return 0;
}
