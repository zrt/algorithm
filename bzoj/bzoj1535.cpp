#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
//无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std;
typedef long long ll;
const double eps(1e-10);
const int inf(0x7fffffff);
#define N 510000
char s[N];
int nxt[N];
int L[N],l,tot;
bool judge(int x){
	int j=nxt[x];
	for(int i=x+1;i<l;i++){
		while(~j&&s[j+1]!=s[i]) j=nxt[j];
		if(s[j+1]==s[i]) j++;
		if(!~j) return false;
		if(j==x) j=nxt[j];
	}
	return true;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s",s);
	l = strlen(s) ;
	int j ;
	nxt[0]=j=-1;
	for(int i=1; i<l; i++){
		while(~j&&s[j+1]!=s[i]) j=nxt[j];
		if(s[j+1]==s[i]) j++;
		nxt[i]=j;
	}
	for(int i=l-1;~i;i=nxt[i]) L[tot++] = i;
	int l=0,r=tot,m ;
	while(l+1<r){
		m=(l+r)>>1;
		if(judge(L[m])){
			l=m;
		}else r=m;
	}
	printf("%d\n",L[l]+1);
	return 0;
}
