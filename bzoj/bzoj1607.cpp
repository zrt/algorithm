/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int num[1000005];
int a[10000005];
int n,nt,t[100005],x[100005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);num[x[i]]++;
		t[i]=x[i];
	}
	sort(x,x+n);
	nt=unique(x,x+n)-x;
	for(int i=0;i<nt;i++){
		for(int j=x[i];j<=1000000;j+=x[i]){
			a[j]+=num[x[i]];
		}
	}
	for(int i=0;i<n;i++) printf("%d\n",a[t[i]]-1);
	return 0;
}
