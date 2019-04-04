#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[2050][2050];
int h[2050];
int ansa,ansb;
struct N{
	int x,h;
	N(int a=0,int b=0){
		x=a,h=b;
	}
}stk[3000];
int top;
void up(int x,int y){
	ansa=max(ansa,min(x,y)*min(x,y));
	ansb=max(ansb,x*y);
}
void work(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) if(a[i][j]) h[j]++;else h[j]=0;
		for(int j=1;j<=m;j++){
			int now=j;
			while(top>0&&stk[top-1].h>h[j]){
				up(j-stk[top-1].x,stk[top-1].h);
				now=stk[top-1].x;
				top--;
			}
			if(top>0&&stk[top-1].h==h[j]){
				continue;
			}else{
				stk[top++]=N(now,h[j]);
			}
		}
		while(top>0){
			up(m-stk[top-1].x+1,stk[top-1].h);
			top--;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&x);
			a[i][j]=((i+j)&1)^x;
		}
	}
	work();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]^=1;
	work();
	printf("%d\n%d\n",ansa,ansb);
	return 0;
}
