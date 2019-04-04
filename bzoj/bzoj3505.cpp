#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
long long ans;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	scanf("%d%d",&n,&m);
	n++;m++;
	ans=(n*m)*1LL*(n*m-1)/2*(n*m-2)/3;
	ans-=1LL*n*(m)*(m-1)*(m-2)/3/2;
	ans-=1LL*m*(n)*(n-1)*(n-2)/3/2;
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			int tmp=gcd(i,j)+1;
			if(tmp>2){
				ans-=(tmp-2)*2*(n-i)*(m-j);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
