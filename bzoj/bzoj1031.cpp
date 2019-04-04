#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x3fffffff) ;
#define MAXN 120050
char s[MAXN*2];
int n,l;
int sa[MAXN*2],t[MAXN*2],t2[MAXN*2],m,c[MAXN*2];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++) s[i+n]=s[i];
	l=n;n*=2;m=129;
	//build sa
	int i,*x=t,*y=t2;
	for(i=0;i<m;i++) c[i]=0;
	for(i=0;i<n;i++) c[x[i]=s[i]]++;
	for(i=1;i<m;i++) c[i]+=c[i-1];
	for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int k=1;k<=n;k<<=1){
		int p=0;
		for(i=n-k;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
		//first
		for(i=0;i<m;i++) c[i]=0;
		for(i=0;i<n;i++) c[x[y[i]]]++;
		for(i=0;i<m;i++) c[i]+=c[i-1];
		for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		//
		swap(x,y);
		p=1;x[sa[0]]=0;
		for(i=1;i<n;i++){
			x[sa[i]]= y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
		}
		if(p>=n) break;
		m=p;
	}
	for(int i=0;i<n;i++){
		if(sa[i]<l) putchar(s[sa[i]+l-1]);
	}
	puts("");
	return 0 ;
}
