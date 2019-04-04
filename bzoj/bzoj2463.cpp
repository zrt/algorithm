#include<cstdio>
using namespace std;
int n;
int tot,x,y;
int main(){
	while(scanf("%d",&x),x){
		if(x&1) puts("Bob");
		else puts("Alice");
	}
	return 0;
}
