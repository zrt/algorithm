#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int a[1000006];
int x,y,n;
int ans;
int tmd;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		a[x]++;
		a[y+1]--;
	}
	for(int i=0;i<=1000000;i++){
		tmd+=a[i];
		ans=max(ans,tmd);
	}
	printf("%d\n",ans);
	return 0;
}
