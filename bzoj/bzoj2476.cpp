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
int p;
LL mod=987654321;
struct Matrix{
	int m,n;
	LL a[2][2];
	void setI(){
		memset(a,0,sizeof a);
		for(int i=0;i<m;i++) a[i][i]=1;
	}
	void set(){
		memset(a,0,sizeof a);
	}
	friend Matrix operator * (Matrix&a,Matrix&b){
		Matrix c;
		c.set();
		c.m=a.m;c.n=b.n;
		for(int i=0;i<c.m;i++){
			for(int j=0;j<c.n;j++){
				for(int k=0;k<a.n;k++){
					c.a[i][j]+=a.a[i][k]*1LL*b.a[k][j]%mod;
					if(c.a[i][j]>=mod) c.a[i][j]%=mod;
 				}
			}
		}
		return c;
	}
};
Matrix pow(Matrix a,int p){
	Matrix ret;
	ret.m=ret.n=a.m;
	ret.setI();
	while(p){
		if(p&1) ret=ret*a;
		a=a*a;
		p>>=1;
	}
	return ret;
}

int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d",&p),p){
		if(p<8){
			puts("0");
		}else if(p==8){
			puts("2");
		}else if(p==9){
			puts("0");
		}else if(p==10){
			puts("9");
		}else if(p&1){
			puts("0");
		}else{
			p/=2;
			Matrix a,b;
			a.m=1;a.n=2;
			a.a[0][0]=13;
			a.a[0][1]=5;
			b.m=b.n=2;
			b.a[0][0]=3;
			b.a[0][1]=1;
			b.a[1][0]=-1;
			b.a[1][1]=0;
			b=pow(b,p-5);
			a=a*b;
			printf("%lld\n",((a.a[0][0]-p+1)%mod+mod)%mod);
		}
	}
	
	return 0;
}
