#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long double ld;
ld f[105][32769];
int k,n;
int pre[16];
int w[16];
int main(){
	scanf("%d%d",&k,&n);
	for(int i=0,x;i<n;i++){
		scanf("%d",&w[i]);
		while(~scanf("%d",&x)){
			if(x==0) break;
			x--;
			pre[i]|=(1<<x);
		}
	}
	for(int i=k;i>=1;i--){
		for(int j=0;j<1<<n;j++){
			for(int k=0;k<n;k++){
				if((pre[k]|j)==j){
					f[i][j]+=max((f[i+1][j|(1<<k)]+w[k])/n,f[i+1][j]/n);
				}else f[i][j]+=f[i+1][j]/n;
			}
		}
	}
	printf("%.6f\n",(double)f[1][0]);
	return 0;
}
