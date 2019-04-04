#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
using namespace std;
typedef long long LL;
LL n,m,k;
LL mod=1000000007;
map<LL,LL> mp;
set<pair<LL,LL> > st;
LL po(LL x,LL y,LL p){
	LL ret=1;
	while(y){
		if(y&1){
			ret=ret*x%p;
		}
		y>>=1;
		x=x*x%p;
	}
	return ret;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	LL sum=(1+n)*n/2 %mod;
	for(int i=0,x,y;i<k;i++){
		scanf("%d%d",&x,&y);
		if(st.find(make_pair(x,y))==st.end()){
			mp[x]=(mp[x]-y)%mod;
			st.insert(make_pair(x,y));
		}
		
	}
	LL ans=1;
	for(map<LL,LL>::iterator it=mp.begin();it!=mp.end();++it){
		ans=ans*((sum+it->second)%mod)%mod;
		m--;
	}
	ans=ans*po(sum,m,mod)%mod;
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}
