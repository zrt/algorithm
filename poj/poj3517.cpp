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
int n,k,m;
int f[10005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d%d",&n,&k,&m),n|k|m){
		f[1]=0;
		for(int i=2;i<=n-1;i++){
			f[i]=(f[i-1]+k)%i;
		}
		printf("%d\n",(f[n-1]+m)%n+1);
	}
	return 0;
}
