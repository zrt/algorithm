#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int p,a;
int base[]={2,3,5,7,11,13,17,19,23};

int qpow(int a,int b,int p){
	int ret=1;
	while(b){
		if(b&1) ret=ret*1LL*a%p;
		b>>=1;
		a=a*1LL*a%p;
	}
	return ret;
}
bool test(int a,int d,int p){
	if(!(p&1)) return 0;
	int s=0;
	while(!(d&1)) s++,d>>=1;
	int r=qpow(a,d,p);
	if(r==1) return 1;
	for(int i=0;i<s;i++){
		if(r==p-1) return 1;
		r=r*1LL*r%p;
	}
	return 0;
}
bool check(int n ){
	if(n<2) return 0;
	if(n==2) return 1;
	for(int i=0;i<9;i++){
		if(n==base[i]) return 1;
		if(!test(base[i],n-1,n)) return 0;
	}
	return 1;
}
int main(){
	#ifdef LOCAL
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d",&p,&a),p|a){
		if(check(p)) puts("no");
		else{
			if(qpow(a,p,p)==a) puts("yes");
			else puts("no");
		}
	}
	return 0;
}
