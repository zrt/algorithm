#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	if(n-k+1<k) k=n-k+1;
	if(n==1) puts("1");else
	printf("%d\n",2*k);
	return 0;
}
