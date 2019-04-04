#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
//by zrt
//problem:
using namespace std;
typedef int LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
LL lcm(LL a,LL b){
	return a/gcd(a,b)*b;
}
struct Fs{
	LL fz,fm;
	Fs(LL a=0,LL b=1){
		LL g=gcd(b,a);
		a/=g;b/=g;
		fz=a;fm=b;
	}
	friend Fs operator + (Fs a,Fs b){
		LL f=lcm(a.fm,b.fm);
		return Fs(f/a.fm*a.fz+f/b.fm*b.fz,f);
	}
	friend Fs operator - (Fs a,Fs b){
		LL f=lcm(a.fm,b.fm);
		return Fs(f/a.fm*a.fz-f/b.fm*b.fz,f);
	}
};
Fs a[1048576];
char s[25];
int n;
Fs div2(Fs a){
	if(!(a.fz&1)){
		return Fs(a.fz/2,a.fm);
	}else{
		return Fs(a.fz,a.fm*2);
	}
}
void FWT(int l,int r){
	if(l+1==r) return;
	int m=(l+r)>>1;FWT(l,m);FWT(m,r);
	Fs tmpa,tmpb;
	for(int i=l;i<m;i++) tmpa=div2(a[i]+a[i-l+m]),tmpb=div2(a[i-l+m]-a[i]),a[i]=tmpa,a[i-l+m]=tmpb;
}
void dfs(int S,int pos){
	if(a[S].fz){
		printf("%d",a[S].fz);
		if(a[S].fm!=1) printf("/%d",a[S].fm);
		bool ff=1;
		for(int i=0;i<n;i++){
			if(S&(1<<(n-i-1))) {
				if(ff) ff=0,putchar(' ');
				printf("x%d",i+1);
			}
		}
		puts("");
	}
	if(pos>=0){
		dfs(S|1<<pos,pos-1);//空一位 
		for(int i=pos-1;i>=0;i--){
			dfs(S|1<<i,i-1);
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<(1<<n);i++){
		scanf("%s",s);
		int pos=0;
		for(int j=0;j<n;j++){
			if(s[j]=='+') pos|=1<<(n-j-1);
		}
		double tmp;
		scanf("%lf",&tmp);
		a[pos].fz=round(tmp*100);
		a[pos].fm=100;
	}
	FWT(0,(1<<n));
	for(int i=0;i<1<<n;i++){
		LL g=gcd(a[i].fm,a[i].fz);
		a[i].fz/=g;
		a[i].fm/=g;
		if(a[i].fm<0){
			a[i].fm*=-1;
			a[i].fz*=-1;
		}
	}
	dfs(0,n-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
