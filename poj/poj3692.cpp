#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int g,b,m;
bool map[205][205];
int H[205],X[40005],P[40005];
int tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int link[205];
bool vis[205];
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
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int kase=0; 
	while(scanf("%d%d%d",&g,&b,&m),g|b|m){
		printf("Case %d: ",++kase);
		tot=0;
		memset(link,0,sizeof link);
		memset(map,0,sizeof map);
		memset(H,0,sizeof H);
		for(int i=0,x,y;i<m;i++){
			scanf("%d%d",&x,&y);
			map[x][y]=1;
		}
		for(int i=1;i<=g;i++){
			for(int j=1;j<=b;j++){
				if(!map[i][j]) add(i,j);
			}
		}
		int ans=0;
		for(int i=1;i<=g;i++){
			memset(vis,0,sizeof vis);
			if(dfs(i))ans++;
		}
		printf("%d\n",g+b-ans);
	}
	
	return 0;
}
