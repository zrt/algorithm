#include<iostream>
#include<cstdio>
#include<bitset> 
//by zrt
//problem:
using namespace std;
bitset<1010> bs;
int n;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	bs[0]=1;
	for(int i=1;i<n;i++){
		if(bs[i-1]) ;
		else bs[i]=1;
	}
	printf("%d\n",(n*n+1)/2);
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(i&1){
				if(bs[j]){
					putchar('C');
				}else{
					putchar('.');
				}
			}else{
				if(bs[j]){
					putchar('.');
				}else{
					putchar('C');
				}
			}
		}
		puts("");
	}
	
	return 0;
}

