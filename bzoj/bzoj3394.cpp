#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int n,f,m;
int map[505][505];
int p[505];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&f,&m);
	memset(map,0x3f,sizeof map);
	for(int i=1;i<=f;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) map[i][i]=0;
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=map[y][x]=min(map[x][y],z);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}
		}
	}
	int ans=inf,tmp,pos;
	for(int i=1;i<=n;i++){
		tmp=0;
		for(int j=1;j<=f;j++){
			tmp+=map[i][p[j]];
		}
		if(tmp<ans){
			ans=tmp;
			pos=i;
		}
	}
	printf("%d\n",pos);
	return 0;
}
