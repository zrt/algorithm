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
LL k;
LL lastmod,lasta;
bool ok;
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
LL lcm(LL a,LL b){
	return a/gcd(a,b)*b;
}
void exgcd(LL a,LL b,LL&d,LL&x,LL&y){
	if(!b){
		d=a;x=1;y=0;
	}else{
		exgcd(b,a%b,d,x,y);
		x-=a/b*y;
		swap(x,y);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(~scanf("%lld",&k)){
		ok=1;
		LL mod,a;
		scanf("%lld%lld",&lastmod,&lasta);
		if(k==1){
			printf("%lld\n",a);
			continue;
		}
		for(int i=1;i<k;i++){
			scanf("%lld%lld",&mod,&a);
			if(!ok) continue;
			LL A=lastmod,B=-mod,C=lasta-a;
			LL x,y,d;
			exgcd(A,B,d,x,y);
			if(C%d){
				ok=0;continue;
			}else{
				x%=mod/d;
				x=C/d*x;
				x=(x%(mod/d)+(mod/d))%(mod/d);
				LL newmod=lcm(lastmod,mod);
				LL newa=lasta-x%newmod*lastmod%newmod;
				newa=(newa%newmod+newmod)%newmod;
				lastmod=newmod;
				lasta=newa;
			}
		}
		if(ok){
			printf("%lld\n",lasta);
		}else printf("%d\n",-1);
	}
	return 0;
}
