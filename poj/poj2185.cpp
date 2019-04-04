/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
// 错误的方法.
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
char s[10005][100];
typedef long long ll;
ll r,c;
ll gcd(ll a,ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
int nxt[10005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n,m;
	r=c=1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	for(int i=0;i<n;i++){
		int j=-1;
		nxt[0]=j;
		for(int k=1;k<m;k++){
			while(~j&&s[i][j+1]!=s[i][k]) j=nxt[j];
			if(s[i][j+1]==s[i][k]) j++;
			nxt[k]=j;
		}
		r=lcm(r,m-1-nxt[m-1]);
	}
	for(int i=0;i<m;i++){
		int j=-1;
		nxt[0]=j;
		for(int k=1;k<n;k++){
			while(~j&&s[j+1][i]!=s[k][i]) j=nxt[j];
			if(s[j+1][i]==s[k][i])j++;
			nxt[k]=j;
		}
		c=lcm(c,n-1-nxt[n-1]);
	}
	r=min(r,(ll)m);
	c=min(c,(ll)n);
	printf("%lld\n",r*c);
	return 0;
}
/*
实例1：
2 8
ABCDEFAB
AAAABAAA
实例2：
2 8
ABCDEFAB
AAAABABC
*/
//http://blog.sina.com.cn/s/blog_69c3f0410100tyjl.html