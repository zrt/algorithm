#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int sg(int x,int y){
	if((x&1)==1&&(y&1)==1) return 0;
	for(int k=1;;k++){
		if((x-1)%(1LL<<(k+1))<(1LL<<k)&&(y-1)%(1LL<<(k+1))<(1LL<<k)) return k;
	}
}
int tt;
int main(){
	scanf("%d",&tt);
	while(tt--){
		int sum=0;
		int n;
		scanf("%d",&n);n>>=1;
		for(int i=1,x,y;i<=n;i++){
			scanf("%d%d",&x,&y);
			sum^=sg(x,y);
		}
		if(sum) puts("YES");
		else puts("NO");
	}
	return 0;
}
