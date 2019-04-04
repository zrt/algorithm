#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[105];
int f[105][2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int k=0;k<=1;k++){
				if((i-j+1 )&1){
					if(a[i]&1){
						if(a[j]&1){
							if(f[j-1][k^1]){
								f[i][k]=1;
							}
						}
					}
				}
			}
		}
	}
	if(f[n][1]){
		puts("Yes");
	}else puts("No");

	return 0;
}