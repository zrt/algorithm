#include<bits/stdc++.h>
using namespace std;
int n,m;
int fac[2000005];
const int mod=20100403;
int pow(int a,int b,int p){
	int ret=1%p;
	while(b){
		if(b&1) ret=ret*1LL*a%p;
		a=a*1LL*a%p;
		b>>=1;
	}
	return ret;
}
int c(int n,int m){
	return fac[n]*1LL*pow(fac[m],mod-2,mod)%mod*1LL*pow(fac[n-m],mod-2,mod)%mod;
}
int main(){
	scanf("%d%d",&n,&m);
	fac[0]=1;
	for(int i=1;i<=n+m;i++){
		fac[i]=fac[i-1]*1LL*i%mod;
	}
	printf("%d\n",(c(n+m,n)-c(n+m,n+1)+mod)%mod);
	return 0;
}
