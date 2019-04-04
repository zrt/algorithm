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
int stk[100005],top;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%*d",&n);
	int h,num=0;
	for(int i=1;i<=n;i++){
		scanf("%*d%d",&h);
		
		while(top>0&&stk[top-1]>h) num++,top--;
		while(top>0&&stk[top-1]==h) top--;
		stk[top++]=h;
	}
	while(top>0){
		if(stk[top-1]>0) num++;top--;
	}
	printf("%d\n",num);
	return 0;
}
