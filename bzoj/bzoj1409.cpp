#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL m,p;
const int MAXN=46342;
LL prime[MAXN],tot,mindiv[MAXN];
LL n,q,phiq;
struct Matrix{
	LL a[4][4];
	LL* operator [] (int x){
		return a[x];
	}
	void clear(){
		memset(a,0,sizeof a);
	}
	friend Matrix operator *(Matrix a,Matrix b){
		Matrix c;
		c.clear();
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				for(int k=1;k<=2;k++){
					c[i][j]=(c[i][j]+a[i][k]*b[k][j])%phiq;
				}
			}
		}
		return c;
	}
};
LL phi(LL a){
	LL ret=a;
	for(int i=0;i<tot;i++){
		if(prime[i]>a) break;
		if(a%prime[i]==0){
			ret=ret/prime[i]*(prime[i]-1);
			while(a%prime[i]==0) a/=prime[i];
		}
	}
	if(a!=1) ret=ret/a*(a-1);
	return ret;
}
Matrix pow(Matrix x,int b){
	Matrix a;
	a.clear();a[1][1]=a[2][2]=1;
	while(b){
		if(b&1) a=a*x;
		b>>=1;
		x=x*x;
	}
	return a;
}
LL pow(LL a,LL b,LL p){
	LL ret=1;
	while(b){
		if(b&1) ret=ret*a%p;
		b>>=1;
		a=a*a%p;
	}
	return ret%p;
}
int main(){
	scanf("%lld%lld",&m,&p);
	for(int i=2;i<=46341;i++){
		if(!mindiv[i]) mindiv[i]=i,prime[tot++]=i;
		for(int j=0;prime[j]*i<=46341;j++){
			mindiv[prime[j]*i]=prime[j];
			if(mindiv[i]==prime[j]){
				break;
			}
		}
	}
	while(m--){
		scanf("%lld%lld",&n,&q);
		phiq=phi(q);
		Matrix a;
		a.clear();
		a[1][1]=0;a[1][2]=a[2][1]=a[2][2]=1;
		Matrix b;
		b.clear();
		b[1][1]=1;b[1][2]=1;
		b=b*pow(a,n-1);
		printf("%lld\n",pow(p,b[1][1],q));
	}
	return 0;
}
