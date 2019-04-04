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
int s1,s2,s3;
int cnt[85];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&s1,&s2,&s3);
	for(int i=1;i<=s1;i++){
		for(int j=1;j<=s2;j++){
			for(int k=1;k<=s3;k++){
				cnt[i+j+k]++;
			}
		}
	}
	int maxx,maxn=0;
	int ssum=s1+s2+s3;
	for(int i=1;i<=ssum;i++){
		if(cnt[i]>maxn){
			maxn=cnt[i];maxx=i;
		}
	}
	printf("%d\n",maxx);
	return 0;
}
