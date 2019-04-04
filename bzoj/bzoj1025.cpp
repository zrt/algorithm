#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int p[1005];
unsigned long long f[1005][1005];
int tot=1;
int mindiv[1005];
unsigned long long ans;
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		if(!mindiv[i]){
			mindiv[i]=i;p[tot++]=i;
		}
		for(int j=0;p[j]*i<=n;j++){
			mindiv[p[j]*i]=p[j];
			if(mindiv[i]==p[j]){
				break;
			}
		}
	}
	f[0][0]=1;
	for(int i=1;i<tot;i++){
		for(int j=0;j<=n;j++) f[i][j]=f[i-1][j];
		for(int j=p[i];j<=n;j*=p[i]){
			for(int k=j;k<=n;k++){
				f[i][k]+=f[i-1][k-j];
			}
		}
	}
	for(int i=1;i<=n;i++) ans+=f[tot-1][i];
	printf("%llu\n",ans+1);
	return 0;
}
