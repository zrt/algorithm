#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
//by zrt
//problem:
using namespace std;
int f[46];
set<int> s;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	f[0]=0;f[1]=1;
	for(int i=2;i<=45;i++){
		f[i]=f[i-1]+f[i-2];
	}
	int MAX=1e9;
	for(int i=0;i<=45;i++) s.insert(f[i]);
	for(int i=3;i<=45;i++){
		for(int j=i;j<=45;j++){
			if(f[i]*1LL*f[j]<=MAX){
				s.insert(f[i]*f[j]);
			}
		}
	}
	int t,x;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&x);
		if(s.count(x)){
			puts("TAK");
		}else{
			puts("NIE");
		}
	}
	return 0;
}
