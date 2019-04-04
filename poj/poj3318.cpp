#include<cstdio>
using namespace std;
int a[500][500],b[500][500],c[500][500];
char C;
int sum,sign;
inline void read(){
	sign=1;
	while(((C=getchar())<'0'||C>'9')&&C!='-');
	if(C=='-'){
		sum=0;sign=-1;
	}
	else sum=C-'0';
	while((C=getchar())>='0'&&C<='9'){
		sum*=10;sum+=C-'0';
	}
	sum*=sign;
}
int main(){
	int n,i,j,k,x;
	read();n=sum;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			read();
			a[i][j]=sum;
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			read();
			b[i][j]=sum;
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j])
				for(k=0;k<n;k++)
					c[i][k]+=a[i][j]*b[j][k];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			read();
			x=sum;
			if(x!=c[i][j]){
				puts("NO");
				goto ed;
			}
		}
	puts("YES");
	ed:;
	return 0;
}