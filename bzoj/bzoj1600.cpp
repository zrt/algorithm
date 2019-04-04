/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
//http://blog.csdn.net/sdj222555/article/details/8241546
//dp[i, j]´ú±íÊ¹ÓÃÁËiÌõ±ß¹¹³É±ß³¤Ö®ºÍÎªjµÄ·½°¸Êý
#include<cstdio>
//by zrt
//problem:
using namespace std;
int dp[5][2505],n;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	dp[0][0]=1;
	scanf("%d",&n);
	int p=(n+1)>>1;
	for(int k=1;k<=4;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<p;j++){
				if(i>=j) dp[k][i]+=dp[k-1][i-j];
			}
		}
	}
	printf("%d\n",dp[4][n]);
	return 0;
}
