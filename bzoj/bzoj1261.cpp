#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long double ld;
int n;double k,c;
ld f[31][31][31];
bool vis[31][31][31];
int d[31];
int sum;
ld dfs(int l,int r,int dep){
	if(l>r) return 0;
	if(l==r) return d[l]*((dep+1)*k+c);
	if(vis[l][r][dep]) return f[l][r][dep];
	vis[l][r][dep]=1;
	ld&ans=f[l][r][dep];
	ans=1e100;
	for(int i=l;i<=r;i++){
		ans=min(ans,dfs(l,i-1,dep+1)+dfs(i+1,r,dep+1)+d[i]*((dep+1)*k+c));
	}
	return ans;
}
int main(){
	scanf("%d%lf%lf",&n,&k,&c);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]),sum+=d[i];
	printf("%.3f\n",(double)dfs(1,n,0)/sum);
	return 0;
}
