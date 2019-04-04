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
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>=b){
			puts("MMM BRAINS");
		}
		else{
			puts("NO BRAINS");
		}
	}
	
	return 0;
}
