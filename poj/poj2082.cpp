#include<cstdio>
using namespace std;
int n;
inline long long max(long long a,long long b){
	return a>=b?a:b;
}
struct N{
	int x,y;
	N(int a=0,int b=0){
		x=a,y=b;
	}
};
N stk[50005];
int top;
long long ans;
int x,y;
int main(){
	while(scanf("%d",&n)&&(~n)){
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			if(top==0){
				stk[top++]=N(x,y);
			}else if(stk[top-1].y<y){
				stk[top++]=N(x,y);
			}else if(stk[top-1].y==y){
				stk[top-1].x+=x;
			}else{
				int w=0;
				while(top>0&&stk[top-1].y>y){
					ans=max((long long)ans,(w+stk[top-1].x)*(long long)stk[top-1].y);
					x+=stk[top-1].x;w+=stk[top-1].x;
					top--;
				}
				if(top==0||stk[top-1].y<y){
					stk[top++]=N(x,y);
				}else{
					stk[top-1].x+=x;
				}
			}
		}
		int w=0;
		while(top>0){
			ans=max((long long)ans,(w+stk[top-1].x)*(long long)stk[top-1].y);
			w+=stk[top-1].x;
			top--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}