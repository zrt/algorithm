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
int n,sum;
int a[11];
int f[11];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&sum);
	for(int i=1;i<=n;i++) a[i]=i;
	do{
		for(int i=1;i<=n;i++) f[i]=a[i];
		for(int l=n;l>=1;l--){
			for(int i=1;i<l;i++) f[i]+=f[i+1];
		}
		if(f[1]==sum){
			printf("%d",a[1]);
			for(int i=2;i<=n;i++) printf(" %d",a[i]);
			puts("");
			break;
		}
	}while(next_permutation(a+1,a+n+1));
	
	return 0;
}
