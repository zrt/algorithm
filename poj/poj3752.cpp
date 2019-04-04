#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;
int a[500][500]={0};
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int m,n;
	scanf("%d%d",&m,&n);
	int count=m*n;int i=0,j=-1;int t=1;
	while(count){
		while(j+1<n&&a[i][j+1]==0){
			j++;a[i][j]=t;t++;if(t>26) t=1;count--;
		}
		while(i+1<m&&a[i+1][j]==0){
			i++;a[i][j]=t;t++;if(t>26) t=1;count--;
		}
		while(j-1>=0&&a[i][j-1]==0){
			j--;a[i][j]=t;t++;if(t>26) t=1;count--;
		}
		while(i-1>=0&&a[i-1][j]==0){
			i--;a[i][j]=t;t++;if(t>26) t=1;count--;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			putchar(' ');putchar(' ');putchar(' ');
			putchar(a[i][j]+'A'-1);
		}
		puts("");
	}
	return 0;
}
