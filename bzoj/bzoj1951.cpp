#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
// \sum _{i|N} C(N,i)
//p=999911659
//p-1=999911658=2x3x4679x35617
typedef long long LL;
LL mod[]={999911658,2,3,4679,35617};
LL n,g;
LL pow(LL a,LL b,LL p){
	if(a==0) return 0;
	LL ret=1;
	while(b){
		if(b&1) ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret;
}
LL mi;
LL jiecheng[5][40005];
LL C(LL n,LL m,LL p){
	if(n<m) return 0;
	return jiecheng[p][n]*pow(jiecheng[p][m],mod[p]-2,mod[p])%mod[p]*pow(jiecheng[p][n-m],mod[p]-2,mod[p])%mod[p];
}
LL lucas(LL n,LL m,LL p){
	if(m==0) return 1;
	return C(n%mod[p],m%mod[p],p)*lucas(n/mod[p],m/mod[p],p)%mod[p];
}
LL t[5],a[5];
void solve(LL x){// add C(n,x) to mi(%mod[0])
	for(int i=1;i<=4;i++) t[i]=lucas(n,x,i);
	for(int i=1;i<=4;i++) a[i]=mod[0]/mod[i];
	for(int i=1;i<=4;i++) a[i]=a[i]*pow(a[i],mod[i]-2,mod[i])%mod[0]*t[i]%mod[0];
	LL ret=0;
	for(int i=1;i<=4;i++) ret=(ret+a[i])%mod[0];
	mi=(mi+ret)%mod[0];
}
int main(){
	scanf("%lld%lld",&n,&g);
	for(int i=1;i<=4;i++) jiecheng[i][0]=1;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=40000;j++) jiecheng[i][j]=jiecheng[i][j-1]*j%mod[i];
	}
	for(LL i=1;;i++){
		LL ii=i*i;
		if(ii>n) break;
		if(ii==n){
			solve(i);
		}else{
			if(n%i==0){
				solve(i);solve(n/i);
			}
		}
	}
	if(g==999911659){
		puts("0");
		return 0;
	}
	printf("%lld\n",pow(g,mi,999911659));
	return 0;
}
