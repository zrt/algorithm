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
int floyd[305][305];
int n,m,t;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	memset(floyd,0x3f,sizeof floyd);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		floyd[x][y]=min(floyd[x][y],z);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				floyd[i][j]=min(floyd[i][j],max(floyd[i][k],floyd[k][j]));
			}
		}
	}
	for(int i=0,x,y;i<t;i++){
		scanf("%d%d",&x,&y);
		if(floyd[x][y]==inf) puts("-1");
		else printf("%d\n",floyd[x][y]);
	}
	
	return 0;
}
