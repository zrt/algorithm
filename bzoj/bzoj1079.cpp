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
int k;
int a[16];
int c[6];
int mod;
int meet[16][16][16][16][16][6];
int dfs(int c1,int c2,int c3,int c4,int c5,int now){
	if(~meet[c1][c2][c3][c4][c5][now]) return meet[c1][c2][c3][c4][c5][now];
	int& ans=meet[c1][c2][c3][c4][c5][now];
	ans=0;
	if(c1){
		if(now!=1) ans+=c1*1LL*dfs(c1-1,c2,c3,c4,c5,0)%mod;
		else ans+=(c1-1)*1LL*dfs(c1-1,c2,c3,c4,c5,0)%mod;
		ans%=mod;
	}
	if(c2){
		if(now!=2) ans+=c2*1LL*dfs(c1+1,c2-1,c3,c4,c5,1)%mod;
		else ans+=(c2-1)*1LL*dfs(c1+1,c2-1,c3,c4,c5,1)%mod;
		ans%=mod;
	}
	if(c3){
		if(now!=3) ans+=c3*1LL*dfs(c1,c2+1,c3-1,c4,c5,2)%mod;
		else ans+=(c3-1)*1LL*dfs(c1,c2+1,c3-1,c4,c5,2)%mod;
		ans%=mod;
	}
	if(c4){
		if(now!=4) ans+=c4*1LL*dfs(c1,c2,c3+1,c4-1,c5,3)%mod;
		else ans+=(c4-1)*1LL*dfs(c1,c2,c3+1,c4-1,c5,3)%mod;
		ans%=mod;
	}
	if(c5){
		if(now!=5) ans+=c5*1LL*dfs(c1,c2,c3,c4+1,c5-1,4)%mod;
		else ans+=(c5-1)*1LL*dfs(c1,c2,c3,c4+1,c5-1,4)%mod;
		ans%=mod;
	}
	return ans;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&k);
	for(int i=1;i<=k;i++) scanf("%d",&a[i]),c[a[i]]++;
	mod=1000000007;
	memset(meet,-1,sizeof meet);
	for(int i=0;i<=5;i++) meet[0][0][0][0][0][i]=1;
	printf("%d\n",dfs(c[1],c[2],c[3],c[4],c[5],0));
	return 0;
}
