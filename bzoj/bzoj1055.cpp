#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n[4],l;
char s[250];
int a[250];
bool f[250][250][4];
int to[4][20][2];
int To(char c){
	switch(c){
		case 'W' :
			return 0;
		case 'I' :
			return 1;
		case 'N' :
			return 2;
		case 'G' :
			return 3;			
		default  :
			return -1;
	}
	return -1;
}
int main(){
	scanf("%d%d%d%d",&n[0],&n[1],&n[2],&n[3]);
	for(int i=0;i<4;i++){
		for(int j=0;j<n[i];j++){
			scanf("%s",s);
			to[i][j][0]=To(s[0]);
			to[i][j][1]=To(s[1]);
		}
	}
	scanf("%s",s+1);
	l=strlen(s+1);
	for(int i=1;i<=l;i++){
		a[i]=To(s[i]);
		if(a[i]==-1) {
			puts("The name is wrong!");
			return 0;
		}
	}
	for(int i=1;i<=l;i++) f[i][i][a[i]]=1;
	for(int p=2;p<=l;p++){
		for(int i=1;i<=l;i++){
			int j=i+p-1;
			if(j>l) break;
			for(int k=i;k<j;k++){
				for(int c=0;c<4;c++){
					for(int h=0;h<n[c];h++){
						f[i][j][c]|=f[i][k][to[c][h][0]]&f[k+1][j][to[c][h][1]];
					}
				}
			}
		}
	}
	bool out=0;
	if(f[1][l][0]){
		out=1;
		putchar('W');
	}
	if(f[1][l][1]){
		out=1;
		putchar('I');
	}
	if(f[1][l][2]){
		out=1;
		putchar('N');
	}
	if(f[1][l][3]){
		out=1;
		putchar('G');
	}
	if(!out){
		puts("The name is wrong!");
	}else puts("");
	return 0;
}
