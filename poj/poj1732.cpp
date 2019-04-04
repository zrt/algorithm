/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
char s[150];
int n;
char ss[50005][55];
char p[50005][55];
char map[26]={'2','2','2','3','3','3','4','4','1','1','5','5','6','6','0','7','0','7','7','8','8','8','9','9','9','0'};
struct N{
	int l,r,n;
}a[2500005];
int tot;
int nxt[66];
bool cmp(N a,N b){
	if(a.l!=b.l) return a.l<b.l;
	else return a.r<b.r;
}
int dp[150];
int pre[150];
int stk[150],top;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s",s);
	int l=strlen(s);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",ss[i]);
	for(int i=0;i<n;i++){
		int ls=0;
		for(;ss[i][ls];ls++){
			p[i][ls]=map[ss[i][ls]-'a'];
		}
		int k=-1;
		nxt[0]=k;
		for(int j=1;j<ls;j++){
			while(~k&&p[i][k+1]!=p[i][j]) k=nxt[k];
			if(p[i][k+1]==p[i][j]) k++;
			nxt[j]=k;
		}
		k=-1;
		for(int j=0;j<l;j++){
			while(~k&&p[i][k+1]!=s[j]) k=nxt[k];
			if(p[i][k+1]==s[j]) k++;
			if(k==ls-1){
				k=nxt[k];
				a[tot].l=j-ls+1;
				a[tot].r=j;
				a[tot].n=i;
				tot++;
			}
		}
	}
	sort(a,a+tot,cmp);
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	int ans;
	for(int i=0;i<tot;i++){
		ans=dp[a[i].l-1]+1;
		if(ans<dp[a[i].r]){
			pre[a[i].r]=i;
			dp[a[i].r]=ans;
		}
	}
	if(dp[l-1]==0x3f3f3f3f){
		puts("No solution.");
	}else{
		int P=l-1;
		for(;~P;){
			stk[top++]=pre[P];
			P=a[pre[P]].l-1;
		}
		while(top){
			printf("%s ",ss[a[stk[--top]].n]);
		}
	}
	return 0;
}
