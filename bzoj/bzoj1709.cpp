#include<cstdio>
using namespace std;
int n,k;
int hang[105],lie[105],a[205],b[400];
int c[105][105];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,x,y;i<=k;i++){
		scanf("%d%d",&x,&y);
		hang[x]++;
		lie[y]++;
		a[x+y]++;
		b[x-y+n]++;
		c[x][y]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(hang[i]+lie[j]+a[i+j]+b[i-j+n]-c[i][j]*3==k){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	
	return 0;
}
