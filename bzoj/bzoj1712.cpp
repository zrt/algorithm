#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
#define int LL
int a[2][2];
int b[2][2];
int n,t;
int sum;
int c[50005];
int mod=98765431;
void mul(int a[][2],int b[][2]){
	static int c[2][2];
	memset(c,0,sizeof c);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				(c[i][j]+=a[i][k]*1LL*b[k][j]%mod)%=mod;
			}
		}
	}
	memcpy(a,c,sizeof c);
}
#undef int
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#define int LL
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]),sum+=c[i],sum%=mod;
	a[0][0]=sum;
	b[0][0]=-1;b[0][1]=1;b[1][1]=n-1;
	int opt;
	if(t&1) opt=-1;else opt=1;
	while(t){
		if(t&1) mul(a,b);
		mul(b,b);
		t>>=1;
	}
	for(int i=1;i<=n;i++){
		printf("%lld\n",((a[0][1]+opt*c[i])%mod+mod)%mod);
	}
	return 0;
}
