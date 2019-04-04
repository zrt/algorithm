#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
LL n;
LL a[105];
int cnt[105];

unordered_map<uLL,int> calced;
uLL hash_(){
	uLL h = 0;
	for(int i=1;i<=n;i++){
		h = h*13131 + cnt[i] + 21312312;
	}
	return h;
}
int sg(){
	sort(cnt+1,cnt+n+1);
	uLL hx = hash_();
	if(calced.find(hx)!=calced.end()){
		return calced[hx];
	}
	unsigned long long st = 0;
	int now[105];
	int mx = 0;
	for(int i=1;i<=n;i++) now[i]=cnt[i],mx=max(mx,now[i]);
	if(mx == 0 ) return 0;
	for(int i=1;i<=mx;i++){// 操作；
		for(int j=1;j<=n;j++){
			if(now[j]>=i) cnt[j] = now[j]-i;
			else cnt[j] = now[j];
		}
		st |= 1<< sg();
	}
	int ans = 0;
	while(st>>ans &1) ans++;
	for(int i=1;i<=n;i++) cnt[i]=now[i];
	return calced[hx]=ans;
}
unordered_map<int,bool> okk;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int nim = 0;
	for(int i=2;i*i<=1000000000;i++){
		bool flag = 0;
		for(int j=1;j<=n;j++){
			while(a[j]%i == 0){
				a[j]/=i;
				cnt[j]++;
				flag = 1;
			}
		}
		if(flag){
			nim ^= sg();
			memset(cnt,0,sizeof cnt);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]>1 && !okk[a[i]]){
			okk[a[i]] = true;
			nim^=1;
		}
	}

	if(nim == 0) puts("Arpa");
	else puts("Mojtaba");

	return 0;
}