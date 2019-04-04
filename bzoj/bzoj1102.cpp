/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
#include<cstring>
//by zrt
//problem:
using namespace std;
int n,n2;
int f[1000005];
bool vis[1000005];
int a[1005][1005];
bool higher[1005][1005];
bool lower[1005][1005];
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
int xk[]={0,1,1};
int yk[]={1,0,1};
int Xk[]={1,1,1,0,0,-1,-1,-1};
int Yk[]={1,0,-1,-1,1,1,0,-1};
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	n2=n*n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<=n2;i++) f[i]=i;
	int x,y;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<8;k++){
				x=i+Xk[k];y=j+Yk[k];
				if(x>=0&&y>=0&&x<n&&y<n){
					if(a[i][j]==a[x][y]){
						f[get(i*n+j)]=get(x*n+y);
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==2&&j==3){
				i=2;j=3;
			}
			for(int k=0;k<8;k++){
				x=i+Xk[k];y=j+Yk[k];
				if(x>=0&&y>=0&&x<n&&y<n){
					if(a[i][j]!=a[x][y]){
						if(a[i][j]<a[x][y]){
							int p=get(i*n+j);
							higher[p/n][p%n]=1;
						}else{
							int p=get(i*n+j);
							lower[p/n][p%n]=1;
						}
					}
				}
			}
		}
	}
	int sf=0,sg=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int k=get(i*n+j);
			if(!vis[k]){
				vis[k]=1;
				if(!higher[k/n][k%n]){
					sf++;
			//		printf("sf %d %d\n",k/n+1,k%n+1);
				}
				if(!lower[k/n][k%n]){
					sg++;
			//		printf("sg %d %d\n",k/n+1,k%n+1);
				}
			}
		}
	}
	printf("%d %d",sf,sg);
	return 0;
}
