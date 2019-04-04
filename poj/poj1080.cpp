#include<iostream>
#include<cstring>
#include<cstdio>
//by zrt
//problem:
using namespace std;
int T,n,m;
char s1[150],s2[150];
int dp[150][150];
int map[150][150];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	map['C']['C']=map['G']['G']=map['T']['T']=map['A']['A']=5;
	map['T'][0]=map[0]['T']=map['C']['A']=map['A']['T']=map['T']['A']=map['A']['C']=-1;
	map['A']['G']=map['G']['A']=map['C']['T']=map['T']['C']=map['G'][0]=map[0]['G']=map['G']['T']=map['T']['G']=-2;
	map['A'][0]=map[0]['A']=map['C']['G']=map['G']['C']=-3;
	map[0]['C']=map['C'][0]=-4;
	
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%d%s",&n,s1+1,&m,s2+1);
		memset(dp,0,sizeof dp);
		dp[1][0]=map[s1[1]][0];dp[0][1]=map[0][s2[1]];
		for(int i=2;i<=n;i++){
			dp[i][0]=dp[i-1][0]+map[s1[i]][0];
		}
		for(int i=2;i<=m;i++){
			dp[0][i]=dp[0][i-1]+map[s2[i]][0];
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i-1][j-1]+map[s1[i]][s2[j]],max(dp[i][j-1]+map[0][s2[j]],dp[i-1][j]+map[s1[i]][0]));
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
