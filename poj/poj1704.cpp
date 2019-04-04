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
typedef long long ll;
const double eps=1e-9;
int T,n;
int a[1005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int i=1;
		if(n&1){
			a[1]=0;n++;i++;
		}
		for(;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		int Nim=a[2]-a[1]-1;
		for(int i=3;i<=n;i+=2){
			Nim^=a[i+1]-a[i]-1;
		}
		if(Nim){
			puts("Georgia will win");
		}else puts("Bob will win");
	}
	
	return 0;
}
