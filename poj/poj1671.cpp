/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
double f[100][100];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	memset(f,0,sizeof f);
	f[1][1]=1;
	for(int i=2;i<100;i++){
		for(int j=1;j<=i;j++){
			f[i][j]=f[i-1][j]*j+f[i-1][j-1];
		}
	}
	int x;
	while(scanf("%d",&x)&&x){
		double ans=0;
		for(int i=1;i<=x;i++){
			ans+=f[x][i];
		}
		printf("%d %.0f\n",x,ans);
	}
	return 0;
}
