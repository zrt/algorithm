#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int mindiv[205],prime[205],tot;
int pow(int a,int b){
	int ret=1;
	while(b){
		if(b&1) ret*=a;
		a*=a;
		b>>=1;
	}
	return ret;
}
int ans1[205],ans2[205],top;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	for(int i=2;i<=200;i++){
		if(!mindiv[i]){
			mindiv[i]=i;
			prime[tot++]=i;
		}
		for(int j=0;prime[j]*i<=200;j++){
			mindiv[prime[j]*i]=prime[j];
			if(mindiv[i]==prime[j]) break;
		}
	}
	ios::sync_with_stdio(false);
	string line;
	while(getline(cin,line)){
		istringstream istr(line);
		int a,b,now=1;
		while(istr>>a>>b){
			now*=pow(a,b);
		}
		if(a==0) goto ed;
		now--;
		int sqr=sqrt(now);top=0;
		for(int i=0;prime[i]<=sqr;i++){
			if(now%prime[i]==0){
				ans1[top]=prime[i];
				ans2[top]=0;
				while(now%prime[i]==0) ans2[top]++,now/=prime[i];
				top++;
			}
		}
		if(now>1){
			ans1[top]=now;
			ans2[top]=1;
			top++;
		}
		while(top>0){
			cout<<ans1[top-1]<<' '<<ans2[top-1]<<' ';
			top--;
		}
		cout<<'\n';
	}
	ed:
	return 0;
}
