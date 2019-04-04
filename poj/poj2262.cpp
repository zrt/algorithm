#include<iostream>
#include<cstdio>
#include<bitset>
//by zrt
//problem:
using namespace std;
bitset<1000002> b;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	b.set();
	b[1]=0;
	for(int i=2;i<1000002;i++){
		if(!b[i]) continue;
		int k=1000002/i;
		for(int j=2;j<k;j++){
			int p=i*j;
			b[p]=0;
		}
	}
	int n;
	while(scanf("%d",&n)==1&&n){
		for(int i=1;i<=n;i+=2){
			if(!b[i]) continue;
			if(!b[n-i]) continue;
			printf("%d = %d + %d\n",n,i,n-i);break;
		}
	}
	return 0;
}
