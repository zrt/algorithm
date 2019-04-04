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
int n;
int a[10005];
long long sum;
long long px,psum;
int p;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	px=a[0];p=1;
	for(int i=1;i<n;i++){
		psum+=(a[i]-px)*p;
		p++;
		px=a[i];
		sum+=psum;
	}
	printf("%lld\n",sum<<1);
	return 0;
}
