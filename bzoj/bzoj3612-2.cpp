#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int f[150005][15];
int g(int a,int b){
	if(a<0||b<0) return 0;
	else return f[a][b];
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int tt,n,k,p;
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%d%d",&n,&k,&p);
		if(k==1){
			puts("1");continue;
		}
		if(k==2){
			printf("%d\n",n%p);continue;
		}
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++) f[i][1]=1;
		for(int j=2;j<=k;j++){
			for(int i=2;i<=(n+n-j+1)*j/2;i++){
				f[i][j]=(g(i-j,j-1)+g(i-j,j)-g(i-n-1,j-1))%p;
		//		if(f[i][j]<0){
		//			puts("!!!!!!!!!!!!!!!!");
		//			printf("%d %d\n",i,j);
		//		}
			}
		}
		int tot=0;
		//k
		for(int j=1;j<k;j++){
			for(int i=1;i<=(n+n-j+1)*j>>1;i++){
				tot+=f[i][j]*1LL*f[i][k-j]%p;
				tot+=f[i][j]*1LL*f[i][k-1-j]%p;
				tot%=p;
			}
		}
		printf("%d\n",tot);
		
	}
	
	return 0;
}
