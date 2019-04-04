#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n;
const int mod=10000007;
typedef long long LL;
LL sum[100];
LL c[100][100];
LL ans;
LL pow(LL a,LL b){
	LL ret=1;
	while(b){
		if(b&1) ret=(ret*a)%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ret;
}
int main(){
	scanf("%lld",&n);
	for(int i=0;i<=64;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1]);
		}
	}
	LL p=0;
	for(;(1LL<<p)<=n;p++);p--;
	for(int i=0;i<p;i++){
		for(int j=0;j<=i;j++){
			sum[j+1]+=c[i][j];
		}
	}
	int tot=1;
	for(int i=p-1;i>=0;i--){
		if(n&(1LL<<i)){
			for(int j=0;j<=i;j++){
				sum[tot+j]+=c[i][j];
			}
			tot++;
		}
	}
	sum[tot]++;
	//for(int i=0;i<=64;i++) printf("%lld\n",sum[i]);
	ans=1;
	for(int i=1;i<=64;i++) ans=(ans*pow(i,sum[i]))%mod;
	printf("%lld\n",ans);
	return 0;
}
