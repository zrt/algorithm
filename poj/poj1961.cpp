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
	int l;
	int kase=1;
	while(scanf("%d",&l)&&l){
		printf("Test case #%d\n",kase++);
		scanf("%s",s);
		int j=-1;
		nxt[0]=j;
		for(int i=1;i<l;i++){
			while(~j&&s[j+1]!=s[i])j=nxt[j];
			if(s[j+1]==s[i]) j++;
			nxt[i]=j;
		}
		for(int i=1;i<l;i++){
			if((!((i+1)%(i-nxt[i])))&&~nxt[i]){
				printf("%d %d\n",i+1,(i+1)/(i-nxt[i]));
			}
		}
		puts("");
	}
	
	return 0;
}
