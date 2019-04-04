#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int maxx[50005][20],minn[50005][20];
int lg;
// [ )
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&maxx[i][0]);
		minn[i][0]=maxx[i][0];
	}
	for(lg=0;(1<<lg)<=n;lg++);lg--;
	for(int j=1;j<=lg;j++){
		for(int i=1;i+(1<<j)<=n+1;i++){
			minn[i][j]=min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
			maxx[i][j]=max(maxx[i][j-1],maxx[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=0,x,y;i<q;i++){
		scanf("%d%d",&x,&y);
		int a;
		for(a=0;(1<<a)<=y-x+1;a++);a--;
		printf("%d\n",max(maxx[x][a],maxx[y-(1<<a)+1][a])-min(minn[x][a],minn[y-(1<<a)+1][a]));
	}
	return 0;
}
