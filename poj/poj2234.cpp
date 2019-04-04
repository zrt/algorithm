#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int sg;
	while(~scanf("%d",&n)){
		sg=0;
		for(int i=0,x;i<n;i++){
			scanf("%d",&x);
			sg^=x;
		}
		if(sg) puts("Yes");
		else puts("No");
	}
	
	return 0;
}
