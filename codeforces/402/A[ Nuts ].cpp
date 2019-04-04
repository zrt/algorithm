#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;
int k,a,b,v; 
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d%d",&k,&a,&b,&v);
	int p=min(k-1,b);
	int u=b/p;
	if(u*v*(p+1)>a){
		printf("%d",(a-1)/(v*(p+1))+1);
	}else{
		a-=u*v*(p+1);
		int q=b-u*p;
		a-=(q+1)*v;
		if(a<=0){
			printf("%d",u+1);
		}
		else printf("%d",u+(a-1)/v+2);
	}
//	printf("%d",)
	return 0;
}

