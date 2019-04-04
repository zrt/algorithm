#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long LL;
LL n;
set<LL> s;
int main(){
	scanf("%lld",&n);
	for(int i=1;i*i<=n;i++) if(n%i==0){
		LL a=i,b=n/i,x;
		for(int k=0;k*b+1<n;k++){
			x=k*b+1;
			if((x+1)%a==0) s.insert(x);
		}
		for(int k=1;k*b-1<n;k++){
			x=k*b-1;
			if((x-1)%a==0) s.insert(x);
		}
	}
	for(set<LL>::iterator it=s.begin();it!=s.end();++it){
		printf("%lld\n",*it);
	}
	return 0;
}
