#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n;
int a[55];
char f[60][50500];
// 1 win
char dfs(int a,int b){
	if(!a) return b&1;
	if(b==1) return dfs(a+1,0);
	if(f[a][b]!=-1) return f[a][b];
	char &ret=f[a][b];
	if(a&&!dfs(a-1,b)) return ret=true;
	if(a&&b&&!dfs(a-1,b+1)) return ret=true;
	if(a>=2&&!dfs(a-2,b+2+(b?1:0))) return ret=true;
	if(b&&!dfs(a,b-1)) return ret=true;
	return ret=0;
}
int main(){
	scanf("%d",&t);
	memset(f,-1,sizeof f);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int A=0,B=-1;
		for(int i=1;i<=n;i++) if(a[i]==1) A++;else B+=a[i]+1;
		if(B==-1) B=0;
		puts(dfs(A,B)?"YES":"NO");
	}
	return 0;
}
