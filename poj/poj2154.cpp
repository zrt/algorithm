#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int tt;
int n,p;
int mindiv[100005],phi[100005],prime[100005],tot;
int pow(int a,int b){
	int ret=1;
	a%=p;
	while(b){
		if(b&1) ret=ret*1LL*a%p;
		a=a*1LL*a%p;
		b>>=1;
	}
	return ret;
}
int getphi(int a){
	if(a<=100000) return phi[a]%p;
	int ret=a;
	int sqr=sqrt(a);
	for(int i=0;prime[i]<=sqr;i++){
		if(a%prime[i]==0){
			ret=ret-ret/prime[i];
			while(a%prime[i]==0) a/=prime[i];
		}
	}
	if(a>1) ret=ret-ret/a;
	return ret%p;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	for(int i=2;i<=100000;i++){
		if(!mindiv[i]){
			prime[tot++]=i;
			mindiv[i]=i;
			phi[i]=i-1;
		}
		for(int j=0;prime[j]*i<=100000;j++){
			int now=prime[j]*i;
			mindiv[now]=prime[j];
			if(prime[j]==mindiv[i]){
				phi[now]=phi[i]*prime[j];
				break;
			}
			phi[now]=phi[i]*(prime[j]-1);
		}
	}
	phi[1]=1;
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%d",&n,&p);
		int ans=0;
		int sqr=sqrt(n);
		for(int l=1;l<=sqr;l++){
			if(n%l) continue;
			ans=(ans+getphi(l)*1LL*pow(n,n/l-1))%p;
			if(l*l==n) break;
			ans=(ans+getphi(n/l)*1LL*pow(n,l-1))%p;
		}
		printf("%d\n",ans);
	}
	return 0;
}