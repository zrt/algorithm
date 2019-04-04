#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,r,n,m;
typedef long long LL;
int mindiv[10000005],prime[1000005],tot;
int jiecheng[10000005];
int ans[10000005];
LL pow(LL a,LL b,LL p){
	LL ret=1;
	while(b){
		if(b&1) ret=ret*a%p;
		b>>=1;
		a=a*a%p;
	}
	return ret;
}
int main(){
	scanf("%d%d",&t,&r);
	jiecheng[0]=jiecheng[1]=1;
	for(int i=2;i<=10000000;i++){
		jiecheng[i]=jiecheng[i-1]*1LL*i%r;
		if(!mindiv[i]) mindiv[i]=i,prime[tot++]=i;
		for(int j=0;prime[j]*1LL*i<=10000000;j++){
			mindiv[prime[j]*i]=prime[j];
			if(mindiv[i]==prime[j]) break;
		}
	}
	ans[1]=1;
	for(int i=2;i<=10000000;i++){
		if(mindiv[i]==i){
			ans[i]=ans[i-1]*1LL*(i-1)%r*pow(i,r-2,r)%r;
		}else ans[i]=ans[i-1];
	}
	while(t--){
		scanf("%d%d",&n,&m);
		printf("%lld\n",jiecheng[n]*1LL*ans[m]%r);
	}
	return 0;
}
