#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x7fffffff) ;
#define N 1000000
int n;char s[N];
int ans;
int tmp[26][26];
int tmp2[26][26];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%s",&n,s);
	for(int i=0;i<n;i++) s[i]-='a';
	/*
	int tmp,tmp2;
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			tmp2=0;
			tmp=-inf;
			if(i==j) continue;
			for(int k=0;k<n;k++){
				if(s[k]==i) {
					tmp2++,tmp++;
					if(tmp>ans) ans=tmp;
				}else if(s[k]==j) {
					tmp2--,tmp=tmp2;
					if(tmp2<0) tmp2=0;
				}
			}
		}
	}*/
	memset(tmp,128,sizeof tmp);
	for(int k=0;k<n;k++){
		//1. s[k]==i
		for(int j=0;j<26;j++){
			if(j==s[k]) continue;
			tmp2[s[k]][j]++;tmp[s[k]][j]++;
			if(tmp[s[k]][j]>ans) ans=tmp[s[k]][j];
		}
		
		//2. s[k]==j
		for(int i=0;i<26;i++){
			if(i==s[k]) continue;
			tmp2[i][s[k]]--,tmp[i][s[k]]=tmp2[i][s[k]];
			if(tmp[i][s[k]]>ans) ans=tmp[i][s[k]];
			if(tmp2[i][s[k]]<0) tmp2[i][s[k]]=0;
		}
	}
	printf("%d\n",ans);
	return 0 ;
}
