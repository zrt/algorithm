#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
typedef long double ld;
void read(int&x){scanf("%d",&x);}
void read(long double&x){double xx;scanf("%lf",&xx);x=xx;}
void read(LL&x){scanf("%lld",&x);}
void read(char*s){scanf("%s",s);}

int tt;
LL n,k,p;
LL Phi(LL x){
	LL ret=x;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			ret=ret/i*(i-1);
			while(x%i==0) x/=i;
		}
	}
	if(x>1) ret=ret/x*(x-1);
	return ret;
}
LL pow(LL a,LL b,LL p){
//	printf("%lld %lld ")
	LL ret=1%p;
	while(b){ if(b&1) ret=ret*a%p;b>>=1;a=a*a%p;};
	return ret;
}

LL A(LL n,LL k,LL p,bool&flag){
//	printf("%lld %lld %lld %d\n",n,k,p,flag);
	if(p==1){
		flag=1;
		return 0;
	}
	if(k==0){
		return 1;
	}else{
		LL phi=Phi(p);
		LL ret=A(n,k-1,phi,flag);
		if(!flag){
			if(pow((double)n,ret)>phi){
				flag=1;
			}
		}
		return pow(n,ret+(flag?phi:0),p);
	}
}
int main(){
//	for(int i=1;i<=100;i++) printf("%lld\n",Phi(i));
	read(tt);
	while(tt--){
		n=2;
		//read(n);
		k=1000000;
		//read(k);
		read(p);
		// Orz QY
		bool flag=0;
		printf("%lld\n",A(n,k,p,flag));
	}
	return 0;
}
