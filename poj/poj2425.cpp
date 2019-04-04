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
int n;
int H[1005],X[1000005],P[1000005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int sg[1005];
int dfs(int x){
	if(~sg[x]) return sg[x];
	bool nxt[1005];
	memset(nxt,0,sizeof nxt);
	for(int i=H[x];i;i=X[i]){
		nxt[dfs(P[i])]=1;
	}
	for(int i=0;;i++){
		if(!nxt[i]){
			return sg[x]=i;
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(~scanf("%d",&n)){
		memset(H,0,sizeof H);tot=0;
		memset(sg,-1,sizeof sg);
		for(int i=0,x;i<n;i++){
			scanf("%d",&x);
			for(int j=0,y;j<x;j++){
				scanf("%d",&y);
				add(i,y);
			}
		}
		int q;
		while(scanf("%d",&q),q){
			int SG=0;
			for(int i=0,x;i<q;i++){
				scanf("%d",&x);
				SG^=dfs(x);
			}
			if(SG) puts("WIN");
			else puts("LOSE");
		}
	}
	return 0;
}
