//莫比乌斯函数 前缀和
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long LL;
#define int LL
const int mod=1000000007;
int n,k,l,r;
int miu[10000005],prime[1000005],tot,mindiv[10000005];
map<int,int> Miu;
int M(int x){//sum 1..x
	if(x<=10000000) return miu[x];
	if(Miu.find(x)!=Miu.end()) return Miu[x];
	int lim=x/2;
	int sum=1;
	for(int i=1;i<=lim;i++){
		int j=x/(x/i);
		sum-=(M(j)-M(i-1))*(x/i-1);
		i=j;
	}
	return Miu[x]=sum;
}
inline void MOD(int&a){
	if(a>=mod) a-=mod;
}
int pow(int a,int b,int p){
	int ret=1%p;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
const int inf=0x3f3f3f3f3f3f3f3fLL;
int solve(int l,int r,int k){
	l=(l-1)/k,r/=k;
	int ans=0;
	for(int i=1;i<=r;i++){
		int j=min(r/(r/i),(l/i?(l/(l/i)):inf));
		ans+=pow(r/j-l/j,n,mod)*(M(j)-M(i-1))%mod;
		ans%=mod;
		i=j;
	}
	return (ans+mod)%mod;
}
#undef int
int main(){
	#define int LL
	miu[1]=1;
	for(int i=2;i<=10000000;i++){
		if(!mindiv[i]) mindiv[i]=i,prime[tot++]=i,miu[i]=-1;
		for(int j=0;prime[j]*1LL*i<=10000000;j++){
			mindiv[prime[j]*i]=prime[j];
			if(mindiv[i]==prime[j]){
				miu[prime[j]*i]=0;
				break;
			}
			miu[prime[j]*i]=-miu[i];
		}
	}
	for(int i=1;i<=10000000;i++)MOD(miu[i]+=miu[i-1]);
	scanf("%lld%lld%lld%lld",&n,&k,&l,&r);
	printf("%lld\n",solve(l,r,k));
	//while(~scanf("%lld",&n)) printf("%lld %lld\n",M(n),miu[n]);
	return 0;
}
