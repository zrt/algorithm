#include<iostream>
#include<cstdio>
using namespace std;
int t,m,n;
char map[1000][1000];
int h[1000][1000];
struct N{
	int h,w;
	N(int a=0,int b=0){
		h=a;w=b;
	}
};
N stack[1000];int top;
int main(){
	//freopen("in.txt","r",stdin);//!!!!!!!!!!!!!!!!!!!!!!
	scanf("%d",&t);
	while(t--){
		int ans=0;
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)for(int j=0;j<n;j++) scanf(" %c",&map[i][j]);
		for(int i=0;i<n;i++){
			if(map[0][i]=='F'){
				h[0][i]=1;
			}else{
				h[0][i]=0;
			}
		}
		for(int i=1;i<m;i++) for(int j=0;j<n;j++)
		{
			if(map[i][j]=='F'&&map[i-1][j]=='F'){
				h[i][j]=h[i-1][j]+1;
			}else if(map[i][j]=='F') h[i][j]=1 ; else h[i][j]=0;
		}
		for(int i=0;i<m;i++) h[i][n]=0;
		top=0;
		for(int i=0;i<m;i++) for(int j=0;j<=n;j++){
			int w=1;
			while(top>0&&stack[top-1].h>h[i][j]){
				ans=max(ans,stack[top-1].h*(stack[top-1].w+w-1));
				w+=stack[top-1].w;
				top--;
			}
			if(top>0&&stack[top-1].h==h[i][j]){
				stack[top-1].w+=w;
			}else{
				stack[top++]=N(h[i][j],w);
			}
		}
		printf("%d\n",ans*3);
	}
	return 0;
}