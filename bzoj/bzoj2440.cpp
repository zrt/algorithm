#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int miu[500005];
int tt,n;
int mindiv[500005],prime[500005],tot;
bool judge(int x){
	long long ret=0;
	for(int i=1;i*i<=x;i++){
		ret+=x/(i*i)*miu[i];
	}
	return ret>=n;
}
int calc(int n){
	int l=0,r=n<<1;
	while(r-l>1){
		int mid=l+(r-l)/2;
		if(judge(mid)) r=mid;
		else l=mid;
	}
	return r;
}
int main(){
	miu[1]=1;
	for(int i=2;i<=500000;i++){
		if(!mindiv[i]) mindiv[i]=i,prime[tot++]=i,miu[i]=-1;
		for(int j=0;prime[j]*i<=500000;j++){
			mindiv[prime[j]*i]=prime[j];
			if(prime[j]==mindiv[i]){
				miu[prime[j]*i]=0;
				break;
			}
			miu[prime[j]*i]=-1*miu[i];
		}
	}
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		printf("%d\n",calc(n));
	}
	return 0;
}
