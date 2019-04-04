#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int l;
const int MAXN=1000005;
char s[MAXN];
int nxt[MAXN];
int num[MAXN];
int sum[MAXN];
const int mod=1e9+7;
void solve(){
	nxt[1]=0;
	int L=strlen(s+1);
	int j=0;
	for(int i=2;i<=L;i++){
		while(j&&s[j+1]!=s[i]) j=nxt[j];
		if(s[j+1]==s[i]) j++;
		nxt[i]=j;
	}
	memset(sum,0,sizeof sum);
	memset(num,0,sizeof num);
	sum[0]=1;
	for(int i=1;i<=L;i++) sum[i]=sum[nxt[i]]+1;
	j=0;
	for(int i=2;i<=L;i++){
		while(j&&s[j+1]!=s[i]) j=nxt[j];
		if(s[j+1]==s[i]) j++;
		while(j>i/2) j=nxt[j];
		num[i]=sum[j]-1;
	}
//	for(int i=1;i<=L;i++) printf("%d ",num[i]);
//		puts("");
	long long ans=1;
	for(int i=1;i<=L;i++) ans=ans*(num[i]+1)%mod;
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s+1);
		solve();
	}
	return 0;
}
