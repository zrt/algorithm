#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long t,m,n;
long long h[100050];
struct N{
	long long h,w;
	N(long long a=0,long long b=0){
		h=a;w=b;
	}
};
N stack[100050];long long top;
int main(){
	//freopen("in.txt","r",stdin);//!!!!!!!!!!!!!!!!!!!!!!
	while(scanf("%lld",&n)==1&&n){
		long long ans=0;
		for(long long  i=0;i<n;i++){
			scanf("%lld",&h[i]);
		}
		h[n]=0;
		top=0;
		for(long long  j=0;j<=n;j++){
			long long  w=1;
			while(top>0&&stack[top-1].h>h[j]){
				ans=max(ans,stack[top-1].h*(stack[top-1].w+w-1));
				w+=stack[top-1].w;
				top--;
			}
			if(top>0&&stack[top-1].h==h[j]){
				stack[top-1].w+=w;
			}else{
				stack[top++]=N(h[j],w);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}