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
char s[1000005];
int nxt[1000005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%s",s)&&s[0]!='.'){
		int j=-1;
		nxt[0]=j;
		int l=strlen(s);
		for(int i=1;i<l;i++){
			while((~j)&&s[j+1]!=s[i]) j=nxt[j];
			if(s[j+1]==s[i]) j++;
			nxt[i]=j;
		}
		if(l%(l-1-nxt[l-1])) puts("1");
		else printf("%d\n",l/(l-1-nxt[l-1]));
	}
	return 0;
}
