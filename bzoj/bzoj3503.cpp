#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
typedef long long LL;
LL a[50][50];
LL x[50];
LL v[50];
void gauss(){
	for(int i=1;i<=m;i++){
		if(!((x[i]>>i)&1)){
			for(int j=i+1;j<=m;j++){
				if((x[j]>>i)&1){
					swap(x[i],x[j]);break;
				}
			}
		}
		if(!((x[i]>>i)&1)) continue;
		for(int j=i+1;j<=m;j++){
			if((x[j]>>i)&1){
				x[j]^=x[i];
			}
		}
	}
	for(int i=m;i>=1;i--){
		if((x[i]>>i)&1){
			for(int j=i+1;j<=m;j++){
				if((x[i]>>j)&1) v[i]^=v[j];
			}
		}else{
			v[i]=1;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		a[1][i]=1LL<<i;
	}
	for(int i=2;i<=n+1;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=a[i-1][j]^a[i-1][j-1]^a[i-1][j+1]^a[i-2][j];
		}
	}
	for(int i=1;i<=m;i++){
		x[i]=a[n+1][i];
	}
	gauss();
	for(int i=1;i<=m;i++) a[1][i]=v[i];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=a[i-1][j]^a[i-1][j-1]^a[i-1][j+1]^a[i-2][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%lld ",a[i][j]);
		}
		puts("");
	}
	return 0;
}
