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
long long f[10005][5];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=4;k++){
			for(int j=0;j*j<=i;j++){
				f[i][k]+=f[i-j*j][k-1];
			}
		}
	}
	printf("%lld\n",f[n][1]+f[n][2]+f[n][3]+f[n][4]);
	return 0;
}
