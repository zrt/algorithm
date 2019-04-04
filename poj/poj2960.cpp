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
int k;
int s[105];
int sg[10005];
bool nxt[10005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d",&k),k){
		for(int i=0;i<k;i++) scanf("%d",&s[i]);
		sg[0]=0;
		for(int i=1;i<=10000;i++){
			memset(nxt,0,sizeof nxt);
			for(int j=0;j<k;j++){
				if(i-s[j]>=0) nxt[sg[i-s[j]]]=1;
			}
			for(int j=0;;j++) if(!nxt[j]){
				sg[i]=j;break;
			}
		}
		int m;
		scanf("%d",&m);
		for(int i=0,x,SG;i<m;i++){
			SG=0;
			scanf("%d",&x);
			for(int j=0,y;j<x;j++){
				scanf("%d",&y);
				SG^=sg[y];
			}
			if(SG) putchar('W');
			else putchar('L');
		}
		puts("");
	}
	
	return 0;
}
