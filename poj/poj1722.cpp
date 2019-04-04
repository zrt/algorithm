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
int n,t;
bool f[105][20005];
bool pre[105][20005];//1 + 0 -
int a[105];
int w;
bool opr[105];
int minn,maxx;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	w=10000;
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	f[1][w+a[0]-a[1]]=1;pre[1][w+a[0]-a[1]]=0;
	minn=maxx=w+a[0]-a[1];
	for(int i=2;i<n;i++){
		for(int j=minn;j<=maxx;j++){
			if(f[i-1][j]){
				if(j+a[i]<20000){
					f[i][j+a[i]]=1;
					pre[i][j+a[i]]=1;
					if(j+a[i]>maxx){
						maxx=j+a[i];
					}
				}
				if(j-a[i]>-20000){
					f[i][j-a[i]]=1;
					pre[i][j-a[i]]=0;
					if(j-a[i]<minn){
						minn=j-a[i];
					}
				}
			}
		}
	}
	int p=t+w;
	for(int i=n-1;i>=1;i--){
		opr[i]=pre[i][p];
		if(opr[i]){
			p-=a[i];
		}else p+=a[i];
	}
	// opr - + - -a+b
	//-(b-c)  zai c qian mian jia yi ge jianhao
	int cnt=0;
	for(int i=1;i<n;i++){
		if(opr[i]){
			printf("%d\n",i-cnt);//yin wei qian mian de jian hao dao zhi wei zhi qian yi
			cnt++;
		}
	}
	for(int i=1;i<n;i++){
		if(!opr[i]){
			puts("1");
		}
	}
	return 0;
}
