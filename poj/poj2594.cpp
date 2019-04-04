#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
bool map[505][505];
int n,m;
int H[505],X[250500],P[250500],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool cover[505];
int link[505];
bool find(int x){
	for(int i=H[x];i;i=X[i]){
		if(!cover[P[i]]){
			cover[P[i]]=1;
			if(!link[P[i]]||find(link[P[i]])){
				link[P[i]]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	while(scanf("%d%d",&n,&m),n|m){
		memset(map,0,sizeof map);
		memset(H,0,sizeof H);tot=0;
		for(int i=0,x,y;i<m;i++){
			scanf("%d%d",&x,&y);
			map[x][y]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						map[i][j]|=map[i][k]&&map[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&map[i][j]){
					add(i,j);
				}
			}
		}
		memset(link,0,sizeof link);
		int ans(0);
		for(int i=1;i<=n;i++){
			memset(cover,0,sizeof cover);
			if(find(i)) ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0 ;
}
