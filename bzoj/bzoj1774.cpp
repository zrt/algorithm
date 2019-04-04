#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
struct N{
	int x,w;
}a[260];
int n,m,k;
int map[260][260];
int ans[260][260];
int num[260];
bool cmp(N a,N b){
	return a.w<b.w;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].w);
		a[i].x=i;
	}
	memset(map,0x3f,sizeof map);
	memset(ans,0x3f,sizeof ans);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) map[i][i]=0,num[a[i].x]=i;
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		x=num[x];y=num[y];
		map[x][y]=map[y][x]=min(map[x][y],z);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
				ans[i][j]=min(ans[i][j],map[i][j]+max(a[i].w,max(a[j].w,a[k].w)));
			}
		}
	}
	for(int i=0,x,y;i<k;i++){
		scanf("%d%d",&x,&y);
		x=num[x];
		y=num[y];
		printf("%d\n",ans[x][y]);
	}
	return 0;
}
