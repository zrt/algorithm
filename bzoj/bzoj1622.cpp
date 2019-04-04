#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[1005][1005];
char a[105][35];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]);
		for(int j=0;s[i][j];j++){
			if(s[i][j]<'a'){
				s[i][j]+='a'-'A';
			}
		}
	}
	for(int j=1;j<=m;j++){
		scanf("%s",a[j]);
		for(int i=0;a[j][i];i++){
			if(a[j][i]<'a'){
				a[j][i]+='a'-'A';
			}
		}
	}
	int num;
	for(int i=1;i<=n;i++){
		num=0;
		for(int j=1;j<=m;j++){
			int pos=0;
			for(int k=0;s[i][k];k++){
				if(s[i][k]==a[j][pos]) pos++;
				if(a[j][pos]==0) break;
			}
			if(a[j][pos]==0) num++;
		}
		printf("%d\n",num);
	}
	
	
	
	return 0;
}
