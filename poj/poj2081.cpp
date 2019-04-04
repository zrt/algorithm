#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
//by zrt
//problem:
using namespace std;
set<int> s;
int a[500005];
int main(){
	#ifdef LOCAL
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	a[0]=0;
	for(int i=1;i<=500000;i++){
		a[i]=a[i-1]-i;
		if(a[i]<=0||s.count(a[i])){
			a[i]=a[i-1]+i;
			s.insert(a[i]);
		}else s.insert(a[i]);
	}
	int x;
	while(scanf("%d",&x),(~x)){
		printf("%d\n",a[x]);
	}
	return 0;
}
