/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
//by zrt
//problem:
using namespace std;
bool ok[50005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int c,h,v;
	scanf("%d%d",&c,&h);
	ok[0]=1;
	for(int i=0;i<h;i++){
		scanf("%d",&v);
		for(int j=c-v;j>=0;j--){
			if(ok[j]) ok[j+v] =1;
		}
	}
	for(int i=c;i>=0;i--){
		if(ok[i]){
			printf("%d\n",i);break;
		}
	}
	return 0;
}
