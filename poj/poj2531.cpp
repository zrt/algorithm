/*
ID: zrtdrea1
PROG:
LANG: C++
*/
#include<cstdio>
//by zrt
//problem:
using namespace std;
int n;
int a[25][25];
bool vis[1048577];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	int lmt=(1<<n)-1;
	int ans=0;
	for(int i=1;i<lmt;i++){
		if(vis[i]) continue;
		vis[i]=vis[i^lmt]=1;
		int c=0;
		for(int j=1;j<=n;j++){
			if(1&(i>>(j-1))){
				for(int k=1;k<=n;k++){
					if(!(1&i>>(k-1))){
						c+=a[j][k];
					}
				}
			}
		}
		if(c>ans) ans=c;
	}
	printf("%d\n",ans);
	return 0;
}
