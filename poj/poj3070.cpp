#include<cstdio>
using namespace std;
int x;
inline void mul(int a[][2],int b[][2]){
	int c[2][2]={0};
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				c[i][j]+=a[i][k]*b[k][j];
				if(c[i][j]>=10000) c[i][j]%=10000;
			}
		}
	}
	for(int i=0;i<2;i++) for(int j=0;j<2;j++) a[i][j]=c[i][j];
}
int main(){
	while(scanf("%d",&x)&&(~x)){
		if(x==0){
			puts("0");continue;
		}
		int t[2][2]={{0,1},{0,0}};
		int p[2][2]={{0,1},{1,1}};
		x--;
		while(x){
			if(x&1) mul(t,p);
			mul(p,p);
			x>>=1;
		}
		printf("%d\n",t[0][1]);
	}
	return 0;
}
