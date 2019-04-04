#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define int LL
LL n;
const LL mod = 1e9+7;
int k;

LL ans = 1;
LL a[5][105][105];
// a[k][i][j]  第k轮 指数为i的概率
void calc(LL&x, int i){
	int num = 0;
		while(x%i==0) x/=i, num++;
		LL ij = 1;
		LL tmp = 0;
		for(int j=0;j<=num;j++){
			tmp =( tmp+a[1][num][j]*ij)%mod;
			ij = ij *i %mod;
		}
		ans = ans * 1LL * tmp%mod;
}
LL inv[105];
LL pow(LL a,LL b,LL p){
	LL ret= 1%p;
	while(b){
		if(b&1) ret= ret*a%p;
		b>>=1;
		a=a*a%p;
	}
	return ret;
}
signed main(){
	for(int i=1;i<=100;i++) inv[i] = pow(i,mod-2,mod);
	cin>>n>>k;
	for(int i=0;i<=60;i++){
		//
		for (int j=0;j<=60;j++) a[0][i][j]=0;
		a[0][i][i] = 1;
		for(int t=1;t<=k;t++){
			LL temp=0;
			for(int j=60;j>=0;j--){
				temp+=a[0][i][j]*inv[j+1]%mod;
				if(temp>=mod) temp -= mod;
				a[1][i][j]=temp;
			}
			for (int j=0;j<=60;j++) a[0][i][j]=a[1][i][j];

		}
	}
	LL x = n;
	for(int i=2;i*1LL*i<=x;i++){
		if(x%i==0){
			calc(x,i);
		}
	}
	if(x!=1)
		calc(x,x);
	cout<<ans<<endl;
	return 0;
}
