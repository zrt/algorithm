#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
//  by zrt
//  problem:
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n;
int link[105];
double xa[105],ya[105],x2[105],y2[105];
double w[105][105];
double Lx[105],Ly[105];
bool S[105],T[105];
bool find(int i){
	S[i]=true;
	for(int j=1;j<=n;j++){
		if(fabs(Lx[i]+Ly[j]-w[i][j])<eps&&!T[j]){
			T[j]=1;
			if(!link[j]||find(link[j])){
				link[j]=i;
				return 1;
			}
		}
	}
	return 0;
}
void update(){
	double a=1<<30;
	for(int i=1;i<=n;i++){
		if(S[i]){
			for(int j=1;j<=n;j++){
				if(!T[j]){
					a=min(a,Lx[i]+Ly[j]-w[i][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(S[i]) Lx[i]-=a;
		if(T[i]) Ly[i]+=a;
	}
}
void KM(){
	for(int i=1;i<=n;i++){
		link[i]=Lx[i]=Ly[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(;;){
			for(int j=1;j<=n;j++) S[j]=T[j]=0;
			if(find(i)) break;else update();
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	bool ff(1);
	while(~scanf("%d",&n)){
		if(ff) ff=0;else puts("");
		for(int i=1;i<=n;i++) scanf("%lf%lf",&xa[i],&ya[i]);
		for(int i=1;i<=n;i++) scanf("%lf%lf",&x2[i],&y2[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				w[i][j]=-sqrt((xa[j]-x2[i])*(xa[j]-x2[i])+(ya[j]-y2[i])*(ya[j]-y2[i]));
			}
		}
		KM();
		for(int i=1;i<=n;i++){
			printf("%d\n",link[i]);
		}
	}
	return 0 ;
}