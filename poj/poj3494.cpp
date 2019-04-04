/*
ID: zrtdrea1
PROG:
LANG: C++
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
int n,m;
int a[2005][2005];
int p[2005][2005];
int ans;
void scan(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int j=0;j<m;j++){
		p[0][j]=a[0][j];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]){
				p[i][j]=1+p[i-1][j];
			}else{
				p[i][j]=0;
			}
		}
	}
}
struct N{
	int x,y; // x -- y | y递增 
	N(int a=0,int b=0){
		x=a,y=b;
	}
};
N stk[2005];int top;
int w[2005];
void solve(){
	ans=0;
	for(int i=0;i<n;i++){
		top=0;
		memset(w,0,sizeof w);
		for(int j=0;j<m;j++){
			if(i==4) {
				top=top;
			}
			if(p[i][j]){
				if(top>0&&w[j]) stk[top-1].x-=w[j];
				if(top==0){
					stk[top++]=N(1+w[j],p[i][j]);
				}else if(p[i][j]>stk[top-1].y){
					stk[top++]=N(1+w[j],p[i][j]);
				}else if(p[i][j]==stk[top-1].y){
					stk[top-1].x+=1+w[j];
				}else{
					while(top>0&&stk[top-1].y>p[i][j]){
						ans=max(ans,stk[top-1].x*stk[top-1].y);
						if(top>1) stk[top-2].x+=stk[top-1].x;
						w[j]+=stk[top-1].x-w[j];
						top--;
					}
					j--;continue;
				}
			}else{
				while(top>0){
					ans=max(ans,stk[top-1].x*stk[top-1].y);
					if(top>1)stk[top-2].x+=stk[top-1].x;
					top--;
				}
			}
		}
		while(top>0){
			ans=max(ans,stk[top-1].x*stk[top-1].y);
			if(top>1)stk[top-2].x+=stk[top-1].x;
			top--;
		}
	} 
	printf("%d\n",ans);
}
int main(){
	#ifdef LOCAL
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	while(~scanf("%d%d",&n,&m)){
		scan();
		solve();
	}
	return 0;
}
