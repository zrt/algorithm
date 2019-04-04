#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long f[10005];
int v,n;
int x;
int main(){
	scanf("%d%d",&v,&n);
	f[0]=1;
	for(int i=0;i<v;i++){
		scanf("%d",&x);
		for(int i=0;i<=n-x;i++){
			f[i+x]+=f[i];
		}
	}
	printf("%lld\n",f[n]);
	return 0;
}
