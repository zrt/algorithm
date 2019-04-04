/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
const int maxn=10502;
const int maxm=505;
int f[maxn][maxm];
int n,m;
int d[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=f[i-1][j-1]+d[i];
			
		}
		f[i][0]=f[i-1][0];
		for(int k=1;k<=min(m,i);k++){
			if(f[i-k][k]>f[i][0]){
				f[i][0]=f[i-k][k];
			}
		}
	}
	printf("%d\n",f[n][0]);
	return 0;
}
