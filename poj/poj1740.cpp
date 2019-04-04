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
bool f[105];
int n;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d",&n),n){
		int ans=0;
		memset(f,0,sizeof f);
		for(int i=0,x;i<n;i++){
			scanf("%d",&x);
			if(f[x]) ans++;
			else ans--;
			f[x]=!f[x];
		}
		if(ans) puts("1");
		else puts("0");
	}
	
	return 0;
}
