#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n,K;double f;
double p[20005],b[20005],c[20005];
double x[20005],v[20005]; 
double k[20005];
bool judge(double C){
	for(int i=0;i<n;i++){
		k[i]=x[i]-v[i]*C;
	}
	sort(k,k+n);
	double ret=0.0;
	for(int i=0;i<K;i++){
		ret+=k[i];
	}
	if(ret>0.0) return true;
	else return false;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d%lf",&n,&K,&f);
	for(int i=0;i<n;i++){
		scanf("%lf%lf%lf",&p[i],&b[i],&c[i]);
		v[i]=(p[i]*b[i])/(p[i]+b[i]);
		x[i]=v[i]*c[i]*f; 
	}
	double l=-eps,r=1e12,m;
	for(int i=0;i<55;i++){
		m=(l+r)/2.0;
		if(judge(m)){
			l=m;
		}else{
			r=m;
		}
	}
	printf("%.4f\n",l);
	return 0 ;
}
