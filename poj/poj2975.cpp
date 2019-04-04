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
int a[1005];
int n;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d",&n),n){
		int sg=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);sg^=a[i];
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if((sg^a[i])<=a[i]) ans++;
		}
		if(!sg) {
			puts("0");continue;
		}else printf("%d\n",ans);
	}
	
	return 0;
}
