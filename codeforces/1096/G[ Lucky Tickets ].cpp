#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL p = 998244353 ;
const int bitl = 21;
const int N=1<<bitl;
const int mod=998244353;
const int A=733596141;
// const int bitl = 20;
// const int N=1<<bitl;
// const int mod=998244353;
// const int A=565042129;
int w[N+1];
int F[22][N],ans[N];
int rev[N];
void FFT(int*F,int bit,int o){
	for(int i=0;i<(1<<bit);i++) if(rev[i]>i) swap(F[i],F[rev[i]]);
	for(int i=1;i<=bit;i++){
		int W;
		for(int j=0;j<N;j+=1<<i){
			W=0;
			for(int k=0;k<1<<(i-1);k++){
				int tmp=F[j+k];
				F[j+k]=(F[j+k]+w[W]*1LL*F[j+k+(1<<(i-1))]%mod)%mod;
				F[j+k+(1<<(i-1))]=(tmp+mod-w[W]*1LL*F[j+k+(1<<(i-1))]%mod)%mod;
				W+=o*(1<<(bit-i));
				if(W<0) W+=(1<<bit);
			}
		}
	}
}
int ni;
int Rev(int x){
	int ret=0;
	for(int i=0;i<bitl;i++){
		if(x&(1<<i)) ret|=1<<(bitl-i-1);
	}
	return ret;
}

int n,k;
int a[11];
int pow(int a,int b){
	int ret = 1% mod;
	while(b){
		if(b&1) ret = ret*1LL*a%mod;
		b>>=1;
		a=a*1LL*a%mod;
	}
	return ret;
}
int F1[N],F2[N];
int main(){
	// printf("%d\n",pow(3,(998244353-1)/(1<<20)));

	ni = pow(N, 998244353-2);
	w[0]=1;
	w[1]=A;
	for(int i=0;i<N;i++){
		rev[i]=Rev(i);
	}
	for(int i=2;i<(1<<bitl);i++){
		w[i]=w[i-1]*1LL*A%mod;
	}
	// F1[0] = 1;
	// F2[1] = 1;
	// FFT(F1,bitl,1);
	// FFT(F2,bitl,1);
	// for(int i=0;i<(1<<bitl);i++) F1[i] = F1[i]*1LL*F2[i]%mod;
	// 	for(int i=0;i<10;i++){
	// 		printf("%d ",F1[i]);
	// 	}
	// 	puts("");
	// FFT(F1,bitl,-1);

	// for(int i=0;i<(1<<bitl);i++) F1[i] = F1[i]*1LL*ni%mod;
	// for(int i=0;i<10;i++){
	// 	printf("%d ",F1[i]);
	// }



	scanf("%d%d",&n,&k);
	int n2=n/2;
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
		F[0][a[i]] = 1;
	}
	FFT(F[0],bitl,1);
	// for(int i=0;i<(1<<bitl);i++) F[0][i] = F[0][i]*1LL*ni%mod;
	// for(int i=0;i<10;i++){
	// 	printf("%d ",F[0][i]);
	// }
	// puts("aaaaa");


	for(int i=1;(1<<i)<=n2;i++){
		for(int j=0;j<N;j++){
			F[i][j] = F[i-1][j]*1LL* F[i-1][j]%mod;
		}
	}
	int pos = -1;
	for(int i=0;(1<<i)<=n2;i++){
		if(n2>>i &1){
			// printf("%d\n",i);
			if(pos == -1){
				pos = i;
			}else{
				for(int j=0;j<N;j++){
					F[pos][j] = F[pos][j]*1LL*F[i][j]%mod;
				}
			}
		}
	}
	// pos = 0;
	FFT(F[pos],bitl,-1);
	for(int i=0;i<(1<<bitl);i++) F[pos][i] = F[pos][i]*1LL*ni%mod;
	int mx = n2*10;
	LL ans = 0;
	for(int i=0;i<=mx;i++){
		// printf("%d: %d\n",i,F[pos][i]);
		ans =(ans+(F[pos][i]*1LL*F[pos][i])%mod)%mod;
	}
	printf("%I64d\n",ans);




	return 0;
}