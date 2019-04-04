#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
//by zrt
//problem:
using namespace std;
int n,m;
map<int,int> mp;
int c[6],k[6],p[6];
//8jinzhi &7
int sta[100],price[100];
int dp[32769];
int U;
bool check(int x){
	for(int i=0;i<n;i++){
		if(((x>>(i*3))&7)>k[i]) return 0;
	}
	return 1;
}
bool check(int x,int y){
	for(int i=0;i<n;i++){
		if(((x>>(i*3))&7)+((y>>(i*3))&7)>k[i]) return 0;
	}
	return 1;
}
int ask(int sta){
	int ret=0;
	for(int i=0;i<n;i++){
		ret+=(k[i]-((sta>>(i*3))&7))*p[i];
	}
	return ret;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&c[i],&k[i],&p[i]);
		mp[c[i]]=i;
		U|=k[i]<<(i*3);
	}
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int a;
		scanf("%d",&a);
		for(int j=0;j<a;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			sta[i]|=y<<(mp[x]*3);
		}
		scanf("%d",&price[i]);
	}
	for(int i=0;i<U;i++){
		if(!check(i)) continue;
		for(int j=0;j<m;j++){
			if(check(i,sta[j])){
				dp[i+sta[j]]=min(dp[i+sta[j]],dp[i]+price[j]);
			}
		}
	}
	int ans=dp[U];
	for(int i=0;i<U;i++){
		if(!check(i)) continue;
		ans=min(ans,dp[i]+ask(i));
	}
	printf("%d\n",ans);
	return 0;
}
