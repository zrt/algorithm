#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,tt;
int sg,tot;

int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		sg=0;tot=0;
		for(int i=0,x;i<n;i++){
			scanf("%d",&x);
			sg^=x;
			if(x>1) tot++;
		}
		if((sg==0&&tot==0)||(sg>0&&tot>0)){
			puts("John");
		}else puts("Brother");
	}
	return 0;
}
