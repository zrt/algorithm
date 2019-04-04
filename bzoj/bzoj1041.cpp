#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
LL R,ans;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
bool check(LL y,double x){
	if(x-floor(x)<1e-12){
		LL x1=x;
		if(gcd(x1,y)==1&&x1!=y){
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%lld",&R);
	int lim=sqrt(2*R);
	for(int d=1;d<=lim;d++){
		if((2*R)%d==0){
			int li=sqrt(R/d);
			for(int a=1;a<=li;a++){
				double b=sqrt((2*R/d)-a*a);
				if(check(a,b)) ans++;
			}
			if(d*d!=2*R){
				li=sqrt(d/2);
				for(int a=1;a<=li;a++){
					double b=sqrt(d-a*a);
					if(check(a,b)) ans++;
				}
			}
		}
	}
	printf("%lld\n",ans*4+4);
	return 0;
}
