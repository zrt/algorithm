#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
//by zrt
//problem:
using namespace std;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	while(n--){
		int t;
		scanf("%d",&t);
		int minn=1000,maxx=0;
		for(int i=0;i<t;i++){
			int x;
			scanf("%d",&x);
			minn=min(minn,x);
			maxx=max(maxx,x);
		}
		printf("%d\n",(maxx-minn)*2);
	}
	
	return 0;
}
