#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

struct N{
	LL a,t,id;
}a[300005];
bool cmp(N a,N b){
	return a.t<b.t;
}
LL n,T;
bool judge(int x){
	LL sum = 0,tot=0;
	for(int i=1;i<=n;i++){
		if(sum+a[i].t<=T&&x<=a[i].a){
			tot++;
			sum+=a[i].t;
		}
	}
	return tot>=x;
}
int main(){
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].t;
		a[i].id = i;
	}
	sort(a+1,a+n+1,cmp);
	LL l = 0, r = n+1;
	while(r-l>1){
		LL mid = (l+r) / 2;
		if(judge(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}

	cout<<l<<endl;

	LL sum = 0,tot=0;
	cout<<l<<endl;
	for(int i=1;i<=n;i++){
		if(tot<l&&sum+a[i].t<=T&&l<=a[i].a){
			tot++;
			sum+=a[i].t;
			cout<<a[i].id<<' ';
		}
	}

	return 0;
}