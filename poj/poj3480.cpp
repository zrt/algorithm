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
/*对于任意一个 Anti-SG 游戏，如果我们规定当局面中所有的单一游
 *戏的 SG 值为 0 时，游戏结束，则先手必胜当且仅当： （1）游戏的 SG 函
 *数不为 0 且游戏中某个单一游戏的 SG 函数大于 1；（2）游戏的 SG 函数
 *为 0 且游戏中没有单一游戏的 SG 函数大于 1。*/
int t,n,x,tot,sg;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&t);
	while(t--){
		sg=tot=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x>1) tot++;
			sg^=x;
		}
		if((sg>0&&tot>0)||(sg==0&&tot==0)){
			puts("John");
		}else puts("Brother");
	}
	
	return 0;
}
