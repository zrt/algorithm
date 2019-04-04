/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
double a[150];
int n,b[150];
bool c[20005];
int pre[20005];
double sum;
void print(int x){
	if(x-b[pre[x]-1]!=0) print(x-b[pre[x]-1]),printf(" %d",pre[x]);
	else printf("%d",pre[x]);
	
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d",&n)&&n){
		sum=0;
		for(int i=0;i<n;i++) scanf("%lf",&a[i]),sum+=a[i];
		for(int i=0;i<n;i++){
			b[i]=a[i]/sum*20000;
		}
		memset(c,0,sizeof c);
		c[0]=1;
		int maxx=0;
		for(int i=0;i<n;i++){
			for(int j=maxx;j>=0;j--){
				if(c[j]){
					if(!c[j+b[i]]){
						c[j+b[i]]=1;
						pre[j+b[i]]=i+1;
						if(j+b[i]<10200&&j+b[i]>maxx){
							maxx=j+b[i];
						}
					}
				}
			}
		}
		for(int i=10000;;i--){
			if(c[i]){
			//	printf("%d",pre[i]);
				print(i);
				puts("");
				break;
			}
		}
	}
	
	return 0;
}
