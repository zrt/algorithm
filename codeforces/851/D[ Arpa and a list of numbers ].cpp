#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
LL n,x,y;
LL a[500005];
LL s1[1000005];
LL s2[1000005];
LL ans;

LL ask1(int l,int r){
	if(r>1000000) r=1000000;
	if(l<1) l=1;
	if(l>r) return 0;
	return s1[r]-s1[l-1];
}

LL ask2(int l,int r){
	if(r>1000000) r=1000000;
	if(l<1) l=1;
	if(l>r) return 0;
	return s2[r]-s2[l-1];
}
LL solve(int p){
	LL ret = 0;
	LL c=x/y;
	// printf("##%lld\n",c);
	for(int i=p;i<=1000000+p;i+=p){
		ret += (ask1(max(i-c,i-p+1LL),i)*i- ask2(max(i-c,i-p+1LL),i))*y;
		ret += ask1(i-p+1,i-c-1)*x;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>x>>y;
	for(int x,i=1;i<=n;i++){
		cin>>x;
		s1[x] ++;
		s2[x] +=x;
	}
	for(int i=1;i<=1000000;i++) s1[i]+=s1[i-1],s2[i]+=s2[i-1];
	ans = solve(2);
	// printf("# %lld\n",ans);
	for(int i=3;i<=1000000;i++){
		ans=min(ans,solve(i));
		// if(i==17){
		// 	printf("# %lld\n",ans);
		// }
	}

	cout<<ans<<endl;


	return 0;
}