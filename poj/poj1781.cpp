#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
double tmp;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(cin>>tmp){
		int n=tmp+0.5;
		if(!n) break;
		int gao=0;
		for(int i=0;i<30;i++){
			if((n>>i)&1) gao=i;
		}
		n&=(~(1<<gao));
		n<<=1;
		n|=1;
		printf("%d\n",n);
	}
	
	return 0;
}
