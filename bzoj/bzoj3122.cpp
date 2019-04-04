#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b,p,X1,t;
int tt;
LL pow(LL a,LL b,LL p){
	LL ret=1%p;
	while(b){
		if(b&1) ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret;
}
LL ni(LL x){
	x=(x%p+p)%p;
	return pow(x,p-2,p);
}
map<LL,LL> mp;
int main(){
	scanf("%d",&tt);
	while(tt--){
		scanf("%lld%lld%lld%lld%lld",&p,&a,&b,&X1,&t);
		if(t==X1){
			puts("1");continue;
		}
		if(a==0){
			if(b==t) puts("2");
			else puts("-1");
			continue;
		}else if(a==1){
			if(b==0){
				puts("-1");
			}else{
				LL ans=(t-X1+p)%p*ni(b)%p;
				printf("%lld\n",ans+1);
			}
			continue;
		}
		t=(t-b*ni(1-a)%p+p)%p;
		t=t*ni(X1-b*ni(1-a))%p;
		mp.clear();
		LL lim=sqrt(p);
		for(int i=lim;i>=0;i--) mp[ni(pow(a,i,p))*t%p]=i;
		bool ok=0;
		LL ans;
		for(int i=0;i<=lim;i++){
			LL tmp=pow(a,i*lim,p);
			if(mp.find(tmp)!=mp.end()){
				ans=mp[tmp]+i*lim;ok=1;
				break;
			}
		}
		if(ok) printf("%lld\n",ans+1);else puts("-1");
	}
	return 0;
}
