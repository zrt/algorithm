#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;
int f[2][505][505];
char a[505],b[505],c[505];
int l1,l2,l3;
inline void max(int&a,int b){
	if(a<b) a=b;
}
int main(){
//	freopen("array.in","r",stdin);
//	freopen("array.out","w",stdout);
	scanf("%s%s%s",a+1,b+1,c+1);
	l1=strlen(a+1),l2=strlen(b+1),l3=strlen(c+1);
	f[0][0][0]=0;
	register int tmp;
	for(register int i=0;i<=l1;i++){
		for(register int j=0;j<=l2;j++){
			for(register int k=0;k<=l3;k++){
				tmp=0x80808080;
				if(i>0) max(tmp,f[(i&1)^1][j][k]);
				if(j>0) max(tmp,f[i&1][j-1][k]);
				if(i>0&&j>0&&a[i]==b[j]) max(tmp,f[(i&1)^1][j-1][k]+1);
				if(i>0&&j>0&&k>0&&a[i]==b[j]&&b[j]==c[k]) max(tmp,f[(i&1)^1][j-1][k-1]+1);
				if(i==0&&j==0&&k==0) f[i][j][k]=0;
				else f[i&1][j][k]=tmp;
			}
		}
	}
	if(f[l1&1][l2][l3]>=l3) printf("%d\n",f[l1&1][l2][l3]);
	else puts("NO SOLUTION");
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
