#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,m,t;
int a[305][305]; 
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&m,&t);
	memset(a,0x3f,sizeof a);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=min(a[x][y],z);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],max(a[i][k],a[k][j]));
			}
		}
	}
	for(int i=0,x,y;i<t;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",a[x][y]==0x3f3f3f3f?-1:a[x][y]);
	}
	return 0;
}
