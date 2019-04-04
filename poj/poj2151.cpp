#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,m,t;
double p[1005][35];
double g[1005][35];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d%d",&m,&t,&n),n|m|t){
		for(int i=1;i<=t;i++){
			for(int j=1;j<=m;j++){
				scanf("%lf",&p[i][j]);
			}
		}
		memset(g,0,sizeof g);
		for(int i=1;i<=t;i++) g[i][0]=1;
		for(int i=1;i<=t;i++){
			for(int j=1;j<=m;j++){
				for(int k=m;k>=1;k--){
					g[i][k]=(1-p[i][j])*g[i][k]+(p[i][j])*g[i][k-1];
				}
			}
		}
		double piG=1,sub=1;
		for(int i=1;i<=t;i++) piG*=g[i][1],sub*=(g[i][1]-g[i][n]);
		printf("%.3f\n",piG-sub);
	}
	
	return 0;
}
