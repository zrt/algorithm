#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
LL n,t;
LL f[100],g[100];//1 .. 0
void pre(){
	f[0]=g[0]=1;
	for(int i=1;i<=64;i++){
		f[i]=g[i-1];
		g[i]=f[i-1]+g[i-1];
	}
}
LL dp(LL x){
	LL ret=0;
	for(int i=62;i>=0;i--){
		if(x&(1LL<<i)){
			ret+=g[i];if(i<62&&(x&(1LL<<(i+1)))) break;
		}
		
	}
	return ret-1;
}
void mul(LL a[2][2],LL b[2][2]){
	LL c[2][2]={0};
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				c[i][j]+=a[i][k]*b[k][j]%mod;
				if(c[i][j]>=mod)c[i][j]-=mod;
			}
		}
	}
	for(int i=0;i<2;i++) for(int j=0;j<2;j++) a[i][j]=c[i][j];
}
LL ask(LL x){
	//g[x]
	LL a[2][2]={{0,1},{1,1}};
	x--;
	LL b[2][2]={{0,1},{1,1}};
	while(x){
		if(x&1){
			mul(b,a);
		}
		x>>=1;
		mul(a,a);
	}
	return (b[0][0]+b[1][0])%mod;
}
int main(){
	scanf("%lld",&t);
	pre();
	while(t--){
		scanf("%lld",&n);
		printf("%lld\n",dp(n+1));
		printf("%lld\n",ask(n+1));
	}
	return 0;
}
