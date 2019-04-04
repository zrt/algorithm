#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
typedef long long LL;
LL f[55][55];
char s[55][55];

LL gcd(LL x,LL y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			scanf("%s",s[i]+j);
		}
	}
	f[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(s[i][j]=='*'){
				f[i+1][j]+=f[i][j];
				f[i+1][j+1]+=f[i][j];
			}else{
				f[i+2][j+1]+=f[i][j]*4;
			}
		}
	}
	if(f[n+1][m+1]==0){
		printf("0/1");
	}else
	printf("%lld/%lld",f[n+1][m+1]/gcd(f[n+1][m+1],1LL<<n),(1LL<<n)/gcd(f[n+1][m+1],1LL<<n));
	
	return 0;
}
