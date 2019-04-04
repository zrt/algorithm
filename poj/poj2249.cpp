#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;

int main(){

	int n,k;
	while(scanf("%d%d",&n,&k)==2&&n){
		k=min(k,n-k);
		double ans=1.0;
		for(int i=1;i<=k;i++){
			ans*=(double)n;n--;
			ans/=(double)i;
		}
		printf("%.0f\n",ans+0.3);
	}
	return 0;
}
