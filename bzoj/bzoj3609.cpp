#include<cstdio>
using namespace std;
//by zrt [SJZEZ]
// QQ:401794301

int n,m;
int main(){
	//freopen("game.in","r",stdin);
	//freopen("game.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(m>=n){
			if(n&1){
				puts("1");
			}else puts("0");
		}else{
			int t=(n-1)/m+1;
			if((n-t)&1){
				puts("0");
			}else puts("1");
		}
	}
	//fclose(stdin);
	//fclose(stdout);
//	while(1);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	return 0;
}
