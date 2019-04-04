#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long LL;
int n;
int p[17];
LL k;
LL a[10000000];
int debug = 7;
int tot;
void dfs(int pos,LL now){
	if(pos>n || pos>debug ){
		a[++tot] = now;
		return;
	}
	while(1){
		dfs(pos+1,now);
		double tmp = now*1.*p[pos];
		if(tmp>1e18) break;
		now = now*p[pos];
	}
}
LL cnt ;
void dfs2(int pos,LL now,LL ans){
	if(now>ans) return;
	if(pos>n){
		LL x = ans/now;
		//cout<<"x:"<<x<<endl;
		cnt += upper_bound(a+1,a+tot+1,x)-a -1;
		return;
	}
	while(1){
		dfs2(pos+1,now,ans);
		double tmp = now*1.*p[pos];
		if(tmp>1e18) break;
		now = now*p[pos];
	}
}
LL count(LL ans){
	cnt = 0;
	dfs2(debug+1,1,ans);
	return cnt;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i];
	cin>>k;
	dfs(1,1);
	sort(a+1,a+tot+1);
	if(n<=debug){
		cout<<a[k]<<endl;
	}else{
		//cout<<'#'<<count(99)<<endl;
		LL L = 1, R=1e18;
		while(L < R){
			LL mid=L+(R-L)/2;
			//cout<< mid<<' '<< count(mid)<<endl;
			if(count(mid) < k) L=mid+1;
			else R=mid;
		}
		cout<<L<<endl;
	}
	


	return 0;
}