#include <cstdio>
#include <cstring>
#include <algorithm>
//by zrt
//problem:
using namespace std;
const int inf(0x1f1f1f1f) ;
const double eps(1e-10) ;
typedef long long LL;
int d[105][105];
int map[105][105];
int ans=inf;
int what[3];
int p[105][105];
int last[105][105];
void print(int x,int y){
	if(!p[x][y]) printf("%d ",x);
	else {
		print(x,p[x][y]);
		print(p[x][y],y); 
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	memset(d,0x1f,sizeof d);
	memset(map,0x1f,sizeof map);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		d[x][y]=d[y][x]=map[x][y]=map[y][x]=min(map[y][x],z);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++){
			for(int j=i+1;j<k;j++){
				if(d[i][j]+map[i][k]+map[k][j]<ans){
					ans=d[i][j]+map[i][k]+map[k][j];
					what[0]=k;what[1]=i;what[2]=j;
					memcpy(last,p,sizeof p);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][k]+d[k][j]<d[i][j]){
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=k;
				}
			}
		}
	}
	memcpy(p,last,sizeof p);
	if(ans==inf) puts("No solution.");
	else print(what[1],what[2]),printf("%d %d\n",what[2],what[0]);
	return 0;
}
