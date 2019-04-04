#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int a,b,d,tt;
int miu[50005],prime[50005],mindiv[50005],tot;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	miu[1]=1;
	for(int i=2;i<=50000;i++){
		if(!mindiv[i]){
			mindiv[i]=i;
			prime[tot++]=i;
			miu[i]=-1;
		}
		for(int j=0;prime[j]*i<=50000;j++){
			mindiv[prime[j]*i]=prime[j];
			if(mindiv[i]==prime[j]){
				miu[prime[j]*i]=0;
				break;
			}
			miu[i*prime[j]]=miu[i]*-1;
		}
	}
	for(int i=2;i<=50000;i++) miu[i]+=miu[i-1];
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%d%d",&a,&b,&d);
		a/=d,b/=d;
		if(a>b) swap(a,b);
		int ans=0,skip;
		for(int i=1;i<=a;i++){
			skip=min(a/(a/i),b/(b/i));
			ans+=(miu[skip]-miu[i-1])*(a/i)*(b/i);
			i=skip;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
