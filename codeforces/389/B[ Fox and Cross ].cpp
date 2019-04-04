#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;
int n;
char x[100][100];
bool vis[100][100];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf(" %c",&x[i][j]);
		}
	}
	for(int i=1;i<n-1;i++){
		for(int j=1;j<n-1;j++){
			if(!vis[i][j]){
				if(x[i][j]=='#'){
					if(vis[i-1][j]==false&&vis[i+1][j]==false&&vis[i][j-1]==false&&vis[i][j+1]==false&&x[i-1][j]=='#'&&x[i+1][j]=='#'&&x[i][j-1]=='#'&&x[i][j+1]=='#'){
						vis[i][j]=vis[i-1][j]=vis[i+1][j]=vis[i][j-1]=vis[i][j+1]=1;
					}
				}
			}
		}
	}
	int sign=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(x[i][j]=='#'&&vis[i][j]==false){
				sign=0;break;
			}
		}
	}
	if(sign){
		puts("YES");
	}else{
		puts("NO");
	}
	return 0;
}

