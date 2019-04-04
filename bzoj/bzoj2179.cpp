#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
//by zrt
//problem:
using namespace std;
const double PI=3.1415926535897931;
const int N=1000010;
int n,bit;
struct complex{
	double a,b;
	complex(double x=0,double y=0){
		a=x,b=y;
	}
	friend complex operator + (complex a,complex b){
		return complex(a.a+b.a,a.b+b.b);
	}
	friend complex operator - (complex a,complex b){
		return complex(a.a-b.a,a.b-b.b);
	}
	friend complex operator * (complex a,complex b){
		// a+bi * c+di ==ac-bd+(ad+bc)i
		return complex(a.a*b.a-a.b*b.b,a.a*b.b+a.b*b.a);
	}
};
int rev[N];
int ans[N];
char s[N];
complex F1[N],F2[N],w[N];
int Rev(int x,int y){
	int r=0;
	for(int i=0;i<y;i++){
		r=(r<<1)|(x&1);
		x>>=1;
	}
	return r;
}
void FFT(complex*F,int bit,int offset){
	int W;
	for(int i=0;i<(1<<bit);i++) if(rev[i]>i) swap(F[i],F[rev[i]]);
	for(int i=1;i<=bit;i++){
		for(int j=0;j<1<<bit;j+=(1<<i)){
			W=0;
			for(int k=j;k<j+(1<<(i-1));k++){
				F[k]=F[k]+F[k+(1<<(i-1))]*w[W];
				F[k+(1<<(i-1))]=F[k]-F[k+(1<<(i-1))]*w[W]-F[k+(1<<(i-1))]*w[W];
				W+=offset*(1<<(bit-i));
				if(W<0)W+=(1<<bit);
			}
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(bit=0;(1<<bit)<=(n<<1);bit++);
	for(int i=0;i<(1<<bit);i++){
		w[i].a=cos(2*PI*1.0*i/(1<<bit));
		w[i].b=sin(2*PI*1.0*i/(1<<bit));
		rev[i]=Rev(i,bit);
	}
	scanf("%s",s);
	for(int i=n-1;i>=0;i--){
		F1[n-i-1].a=s[i]-'0';
	}
	scanf("%s",s);
	for(int i=n-1;i>=0;i--){
		F2[n-i-1].a=s[i]-'0';
	}
	FFT(F1,bit,1);FFT(F2,bit,1);
	for(int i=0;i<(1<<bit);i++) F1[i]=F1[i]*F2[i];
	FFT(F1,bit,-1);
	for(int i=0;i<(1<<bit);i++){
		F1[i].a/=1<<bit;
	}
	int m;
	for(int i=0;i<(1<<bit);i++){
		ans[i]+=(int)(F1[i].a+0.5);
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
		if(ans[i]>0) m=i;
	}
	for(int i=m;i>=0;i--) printf("%d",ans[i]);
	puts("");
	return 0;
}
