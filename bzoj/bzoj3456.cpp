#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int mod=1004535809;
const int g=3;
int n;
//非圆周卷积一定要加倍啊。。
LL pow(LL a,LL b,LL p){
	LL ret=1%p;
	while(b){
		if(b&1) ret=ret*a%p;
		b>>=1;
		a=a*a%p;
	}
	return ret;
}
int rev[1<<20];
int w[1<<20];
int Rev(int x,int bit){
	int ret=0;
	for(int i=0;i<bit;i++){
		if(x&(1<<i)) ret|=1<<(bit-i-1);
	}
	return ret;
}
void fft(int*f,int bit,int o){
	// len=1<<bit
	w[0]=1;w[1]=pow(g,(mod-1)/(1<<bit),mod);
	for(int i=2;i<1<<bit;i++) w[i]=w[i-1]*1LL*w[1]%mod;
	for(int i=0;i<1<<bit;i++) rev[i]=Rev(i,bit);
	for(int i=0;i<1<<bit;i++) if(rev[i]>i) swap(f[rev[i]],f[i]);
	//for(int i=0;i<4;i++) printf("%d\n",f[i]);
	for(int i=1;i<=bit;i++){
		//Length = 2^i
		for(int j=0;j<1<<bit;j+=1<<i){
			int W=0;
			for(int k=0;k<1<<(i-1);k++){
				int tmp=f[j+k];
				f[j+k]=(f[j+k]+w[W]*1LL*f[j+k+(1<<(i-1))])%mod;
				f[j+k+(1<<(i-1))]=(tmp-w[W]*1LL*f[j+k+(1<<(i-1))]%mod+mod)%mod;
				W+=o*(1<<(bit-i));
				if(W<0) W+=1<<bit;
			}
		}
	}
	if(o==-1){
		int ni=pow(1<<bit,mod-2,mod);
		for(int i=0;i<1<<bit;i++) f[i]=f[i]*1LL*ni%mod;
	}
}
int lg;
int A[1<<20],C[1<<20],ni[1<<20],tmp[1<<20];
int fac[1<<20];
void getinv(int *A){
	ni[0]=pow(A[0],mod-2,mod);
	for(int i=2;i<=lg+1;i++){
		for(int j=0;j<1<<(i-1);j++) tmp[j]=A[j];
		for(int j=1<<(i-1);j<1<<i;j++) tmp[j]=0;
		fft(tmp,i,1);
		fft(ni,i,1);
		for(int j=0;j<1<<i;j++) tmp[j]=tmp[j]*1LL*ni[j]%mod;
		fft(tmp,i,-1);
		tmp[0]=(2-tmp[0]+mod)%mod;
		for(int j=1;j<1<<i;j++) tmp[j]=mod-tmp[j];
		fft(tmp,i,1);
		for(int j=0;j<1<<i;j++) ni[j]=tmp[j]*1LL*ni[j]%mod;
		fft(ni,i,-1);
		for(int j=1<<(i-1);j<1<<i;j++) ni[j]=0;
	//	printf("%d: ",i-1);
	//	for(int j=0;j<1<<i;j++) printf("%d ",ni[j]);
	//	puts("");
	}
}
int main(){
	scanf("%d",&n);
	for(lg=0;1<<lg<=n;lg++);
	fac[0]=1;
	for(int i=1;i<1<<lg;i++) fac[i]=fac[i-1]*1LL*i%mod;
	for(int i=0;i<1<<lg;i++) A[i]=pow(2,i*1LL*(i-1)/2,mod)*pow(fac[i],mod-2,mod)%mod;
	for(int i=1;i<1<<lg;i++) C[i]=pow(2,i*1LL*(i-1)/2,mod)*pow(fac[i-1],mod-2,mod)%mod;
	getinv(A);	
//	for(int i=0;i<1<<(lg+1);i++) printf("%d ",ni[i]);
//	puts("");
	fft(C,lg+1,1);
	fft(ni,lg+1,1);
	for(int i=0;i<1<<(lg+1);i++) C[i]=C[i]*1LL*ni[i]%mod;
	fft(C,lg+1,-1);
	printf("%lld\n",C[n]*1LL*fac[n-1]%mod);
	
	
	/* test fft
	A[0]=1;A[1]=2;
	B[0]=3;B[1]=4;
	
	fft(A,2,1);
//	for(int i=0;i<4;i++) printf("%d\n",A[i]);
	fft(B,2,1);
	A[0]=A[0]*1LL*B[0]%mod;
	A[1]=A[1]*1LL*B[1]%mod;
	A[2]=A[2]*1LL*B[2]%mod;
	A[3]=A[3]*1LL*B[3]%mod;
	fft(A,2,-1);
	for(int i=0;i<4;i++) printf("%d\n",A[i]);
	*/
	return 0;
}
