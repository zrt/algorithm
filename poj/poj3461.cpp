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
//zhong yu li jie kmp le
int T;
char a[10005],b[1000005];
int la,lb;
int nxt[10005];
void mk(){
	int j=-1;
	nxt[0]=-1;
	for(int i=1;i<la;i++){
		while((~j)&&a[j+1]!=a[i]) j=nxt[j];
		if(a[j+1]==a[i]) j++;
		nxt[i]=j;
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",a,b);
		la=strlen(a);lb=strlen(b);
		int j=-1,cnt=0;
		if(la>lb){
			puts("0");continue;
		}
		mk();
		for(int i=0;i<lb;i++){
			while((~j)&&a[j+1]!=b[i]) j=nxt[j];
			if(a[j+1]==b[i]) j++;
			if(j==la-1){
				cnt++;
				j=nxt[j];
			}
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}
