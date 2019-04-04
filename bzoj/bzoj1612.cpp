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
int n,m; 
int win[105],lose[105];
int map[105][105];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		map[x][y]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				map[i][j]|=map[i][k]&&map[k][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(map[i][j]){
				win[i]++;
				lose[j]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(win[i]+lose[i]==n-1){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
