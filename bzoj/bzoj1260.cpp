#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[55];
int n;
int f[55][55];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			int j=i+l-1;
			if(j>n) break;
			if(i==j) f[i][j]=1;
			else if(s[i]==s[j]){
				f[i][j]=min(f[i+1][j],f[i][j-1]);
				f[i][j]=min(f[i][j],f[i+1][j-1]+1);
			}else{
				f[i][j]=0x3f3f3f3f;
				for(int k=i;k<j;k++){
					f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
				}
			}
		}
	}
	printf("%d\n",f[1][n]);	
	return 0;
}
