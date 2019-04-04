#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[10005];
int f[10005][5];
// 00 01 10 11
inline int cnt(int x){
	int ret(0);
	while(x){
		ret++;
		x&=(x-1);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0][1]=f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				if(((j>>1)&1)==(k&1)){
					int c=cnt((k<<1)|j);
					if(c==a[i]){
						f[i][j]+=f[i-1][k];
					} 
				}
			}
		}
	}
	printf("%d\n",f[n][0]+f[n][2]);
	return 0;
}
