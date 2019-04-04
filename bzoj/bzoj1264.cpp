#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int tot[20005];
int a[20005][10],num[500005];
int stk[500005];
int top;
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=5*n;i++){
		scanf("%d",&x);
		a[x][tot[x]++]=i;
	}
	int p=0;
	for(int i=1,x;i<=5*n;i++){
		scanf("%d",&x);
		for(int j=4;j>=0;j--){
			num[p++]=a[x][j];
		}
	}
	for(int i=0;i<p;i++){
		if(!top||num[i]>stk[top-1]) stk[top++]=num[i];
		else *lower_bound(stk,stk+top,num[i])=num[i];
	}
	printf("%d\n",top);
	return 0;
}
