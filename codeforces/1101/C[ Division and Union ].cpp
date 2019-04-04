#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int l[100005], r[100005];
int p[100005];
int belong[100005];
// int num[200005];
bool cmp(int x,int y){
	if(l[x] != l[y]) return l[x] < l[y];
	return r[x]<r[y];
}
int main(){
	ios::sync_with_stdio(0);
	int tt,n;

	cin >> tt;
	while(tt--){
		cin >> n;
		for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
		for(int i=1;i<=n;i++) p[i] = i;
		sort(p+1,p+n+1, cmp);
		belong[p[1]] = 0;
		int cnt = 1;
		int mxr = r[p[1]];
		for(int i=2;i<=n;i++){
			if(l[p[i]]<=mxr){
				belong[p[i]] = belong[p[i-1]];
			}else{
				// puts("!!!");
				cnt ++;
				belong[p[i]] = belong[p[i-1]]^1;
			}
			mxr = max(mxr, r[p[i]]);
		}
		if(cnt == 1){
			cout<<-1<<endl;
		}else{
			for(int i=1;i<=n;i++){
				cout<<belong[i]+1<<' ';
			}
			cout<<endl;
		}

	}


	return 0;
}