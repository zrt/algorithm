#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
typedef long long LL;
#define int LL
const int mod=1000000007;
int n,k,l,r;
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
int miu(int x){
	int lim=sqrt(x);
	int ret=1;
	for(int i=2;i<=lim;i++){
		if(x%i==0){
			x/=i;
			ret*=-1;
			if(x%i==0) return 0;
		}
	}
	if(x>1) ret*=-1;
	return ret;
}
void work(){
	int R=r/k;
	int L=(l-1)/k;
	int ans=0;
	for(int i=1;i<=R;i++){
		LL k=pow(R/i-L/i,n,mod);
		if(k>0){
			ans+=k*miu(i);
			ans%=mod;
		}else{
			i=min(R/(R/i),L/i?(L/(L/i)):inf);
		}
	}
	printf("%lld\n",(ans+mod)%mod);
	
}
#undef int
int main(){
    #define int LL
    scanf("%lld%lld%lld%lld",&n,&k,&l,&r);
	work();
    return 0;
}
