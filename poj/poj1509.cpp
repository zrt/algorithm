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
int T;
char s[10005];
int l;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		l=strlen(s);
		int i=0,j=1;
		while(1){
			int k=0;
			while(k<l&&s[(i+k)%l]==s[(j+k)%l]) k++;
			if(k==l) break;
			if(s[(i+k)%l]>s[(j+k)%l]){
				i+=k+1;
			}else j+=k+1;
			if(i==j) j++;
			if(i>=l||j>=l) break;
		}
		printf("%d\n",min(i,j)+1);
	}
	return 0;
}
