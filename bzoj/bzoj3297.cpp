#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
string s[1005];
int L,n;
char m[1005];
string dp[1005];
bool check(int num,int end){
	int start=end-s[num].length()+1;
	if(start<=0) return 0;
	for(int k=0;k<s[num].length();k++){
		if(m[start+k]=='?') continue;
		if(m[start+k]!=s[num][k]) return 0;
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&L,&n);
	scanf("%s",m+1);
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=1;i<=L;i++){
		dp[i]="{";
		for(int j=0;j<n;j++){
			if(check(j,i)) {
				dp[i]=min(dp[i],dp[i-s[j].length()]+s[j]);
			}
		}
	}
	cout<<dp[L]<<endl;
	return 0;
}
