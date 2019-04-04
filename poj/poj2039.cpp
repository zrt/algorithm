#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
char a[205][205];
char s[205];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n,L;
	while(scanf("%d",&n),n){
		scanf("%s",s);
		L=strlen(s);
		for(int i=0;i<L;i++){
			a[i/n][i%n]=s[i];
		}
		int h=L/n;
		for(int i=1;i<h;i+=2){
			for(int j=0;j<n/2;j++){
				swap(a[i][j],a[i][n-j-1]);
			}
		}
		for(int i=0;i<L;i++){
			putchar(a[i%h][i/h]);
		}
		puts("");
	}
	
	return 0;
}
