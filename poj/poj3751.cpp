#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;

int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c,d,e,f;
		scanf("%d/%d/%d-%d:%d:%d",&a,&b,&c,&d,&e,&f);
		int am=1;
		if(d>12){
			d-=12;am=0;
		}
		else if(d==12){
			am=0;
		}
		else if(d==0){
			d=12;
		}
		printf("%02d/%02d/%04d-%02d:%02d:%02d",b,c,a,d,e,f);
		if(am){
			puts("am");
		}
		else{
			puts("pm");
		}
	} 
	
	return 0;
}
