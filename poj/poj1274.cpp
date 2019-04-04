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

int n,m;
int H[205],X[40005],P[40005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool vis[205];
int link[205];
bool dfs(int x){
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			vis[P[i]]=1;
			if(!link[P[i]]||dfs(link[P[i]])){
				link[P[i]]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(H,0,sizeof H);tot=0;
		for(int i=1,num;i<=n;i++){
			scanf("%d",&num);
			for(int j=0,x;j<num;j++) scanf("%d",&x),add(i,x);
		}
		int ans=0;
		memset(link,0,sizeof link);
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof vis);
			if(dfs(i)) ans++;
		}
		printf("%d\n",ans);
	}
	
	
	return 0;
}
