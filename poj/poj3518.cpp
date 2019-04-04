#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n;
const int MAXN= 1300005;
int mindiv[MAXN];
int prime[100005],tot;

int main(){
	#ifdef LOCAL
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	for(int i=2;i<=1299709;i++){
//		printf("%d\n",i);
		if(!mindiv[i]){
			mindiv[i]=i;
			prime[tot++]=i;
		}
		for(int j=0;prime[j]*1LL*i<MAXN;j++){
			mindiv[prime[j]*i]=prime[j];
			if(mindiv[i]==prime[j]) break;
		}
	}
	while(scanf("%d",&n),n){
		int pos=lower_bound(prime,prime+tot,n)-prime;
		if(prime[pos]==n) puts("0");
		else{
			printf("%d\n",prime[pos]-prime[pos-1]);
		}
	}
	
	return 0;
}
