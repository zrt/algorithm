#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt

using namespace std;
typedef long long LL;
char s[150];
unsigned long long h[150];
int l;
unsigned long long p[150];
//131
unsigned long long hash(int l,int r){// [l,r]
	return h[r]-h[l-1]*p[r-l+1];
}
int dp[150][150];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s",s+1);
	l=strlen(s+1);
	p[0]=1;
	for(int i=1;i<=l;i++) p[i]=p[i-1]*131;
	for(int i=1;i<=l;i++) h[i]=h[i-1]*131+s[i]-'A'+1;
	for(int a=1;a<=l;a++){
		for(int i=1;i<=l;i++){
			int j=i+a-1;
			if(j>l) break;
			for(int k=i;k<j;k++){
				if(j-k<k-i+1){// i........k k+1..j
					if(hash(i,i+j-k-1)==hash(k+1,j)) dp[i][j]=(dp[i][j]+dp[i][k])%2014;
					if(hash(k-(j-k)+1,k)==hash(k+1,j)) dp[i][j]=(dp[i][j]+dp[i][k])%2014;
				}else if(j-k>k-i+1){// i..k k+1.......j
					if(hash(i,k)==hash(k+1,k+1+k-i)) dp[i][j]=(dp[i][j]+dp[k+1][j])%2014;
					if(hash(i,k)==hash(j-(k-i+1)+1,j)) dp[i][j]=(dp[i][j]+dp[k+1][j])%2014;
				}
			}
			dp[i][j]++;
		}
	}
	printf("%d\n",(dp[1][l]-1+2014)%2014);
	return 0;
}
