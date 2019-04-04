#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool f[55][1055];
int n,begin,mx,x;
int main(){
	scanf("%d%d%d",&n,&begin,&mx);
	f[0][begin]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		for(int j=x;j<=mx;j++) f[i][j]|=f[i-1][j-x];
		for(int j=mx-x;j>=0;j--) f[i][j]|=f[i-1][j+x];
	}
	bool ok=0;
	for(int i=mx;i>=0;i--) if(f[n][i]) {
		printf("%d\n",i);ok=1;break;
	}
	if(!ok) puts("-1");
	return 0;
}
