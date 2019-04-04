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
char s[400005];
int nxt[400005];
int num[400005];
int tot;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(~scanf("%s",s)){
		int j=-1;
		nxt[0]=j;
		int l=strlen(s);
		for(int i=1;i<l;i++){
			while((~j)&&s[j+1]!=s[i]) j=nxt[j];
			if(s[i]==s[j+1]) j++;
			nxt[i]=j;
		}
		tot=0;
		for(int i=l-1;~i;i=nxt[i])
			num[++tot]=i+1;
		for(int i=tot;i;i--){
			printf("%d ",num[i]);
		}
		putchar('\n');
	}
	return 0;
}
