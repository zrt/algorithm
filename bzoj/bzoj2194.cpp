#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
//by zrt
//problem:
using namespace std;
struct complex{
	double a,b;
	complex(double x=0,double y=0){
		a=x,b=y;
	}
	friend complex operator +(complex a,complex b){
		return complex(a.a+b.a,a.b+b.b);
	}
	friend complex operator -(complex a,complex b){
		return complex(a.a-b.a,a.b-b.b);
	}
	friend complex operator *(complex a,complex b){
		return complex(a.a*b.a-a.b*b.b,a.a*b.b+a.b*b.a);
	}
};
const int N =500000;
const double PI=acos(-1.0);
complex F1[N],F2[N],w[N];
int rev[N];
int Rev(int x,int y){
	int r=0;
	for(int i=0;i<y;i++){
		r<<=1;r|=x&1;x>>=1;
	}
	return r;
}
void FFT(complex*F,int bit,int offset){
	for(int i=0;i<(1<<bit);i++) if(rev[i]>i) swap(F[i],F[rev[i]]);
	int W;
	for(int i=1;i<=bit;i++){
		for(int j=0;j<(1<<bit);j+=(1<<i)){
			W=0;
			for(int k=j;k<j+(1<<(i-1));k++){
				F[k]=F[k]+F[k+(1<<(i-1))]*w[W];
				F[k+(1<<(i-1))]=F[k]-F[k+(1<<(i-1))]*w[W]-F[k+(1<<(i-1))]*w[W];
				W+=offset*(1<<(bit-i));
				if(W<0) W+=1<<bit;
			}
		}
	}
	if(offset<0) for(int i=0;i<(1<<bit);i++) F[i].a/=(1<<bit);
}
int n,bit;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(bit=0;(1<<bit)<=(n<<1);bit++);
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&F1[i].a,&F2[i].a);
	}
	reverse(F1,F1+n);
	for(int i=0;i<(1<<bit);i++){
		w[i].a=cos(2*PI*((double)i/(1<<bit)));
		w[i].b=sin(2*PI*((double)i/(1<<bit)));
		rev[i]=Rev(i,bit);
	}
	
	FFT(F1,bit,1);
	FFT(F2,bit,1);
	for(int i=0;i<(1<<bit);i++) F1[i]=F1[i]*F2[i];
	FFT(F1,bit,-1);
	for(int i=0;i<n;i++){
		printf("%d\n",(int)(F1[n-i-1].a+0.5));
	}
	return 0;
}
