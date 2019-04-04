#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int a,b,c,d;
	char x,y;
	while(scanf("%d%c%d%c%d%c%d",&a,&y,&b,&x,&c,&y,&d)==7){
		int n,m;
		if(x=='+'){
			n=lcm(b,d),m=a*(n/b)+c*(n/d);
		}
		else{
			n=lcm(b,d),m=a*(n/b)-c*(n/d);
		}
		int a=m/gcd(m,n);
		int b=n/gcd(m,n);
		if(b<0){
			b*=-1;a*=-1;
		}
		if(a==0) puts("0");
		else if(b==1){
			printf("%d\n",a);
		}
		else{
			printf("%d/%d\n",a,b);
		}
	} 
	
	return 0;
}
