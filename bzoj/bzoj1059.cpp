#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
typedef long double ld;
void read(int&x){scanf("%d",&x);}
void read(long double&x){double xx;scanf("%lf",&xx);x=xx;}
void read(LL&x){scanf("%lld",&x);}
void read(char*s){scanf("%s",s);}
int tt,n; 
int w[205][205];
int vis[205],link[205];
bool dfs(int x){
	for(int i=1;i<=n;i++){
		if(!vis[i]&&w[x][i]==1){
			vis[i]=1;
			if(link[i]==0||dfs(link[i])){
				link[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	read(tt);
	while(tt--){
		memset(w,0,sizeof w);
		read(n);
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) read(w[i][j]);
		int ans=0;
		memset(link,0,sizeof link);
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof vis);
			if(dfs(i)) ans++;
		}
		if(ans==n) puts("Yes");else puts("No");
	}
	
	
	return 0;
}
