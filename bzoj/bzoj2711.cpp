#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int x[205],y[205];
typedef long long LL;
LL ans;
bool a[205][80005];
void calc(){
	for(int i=1;i<=n;i++) ans-=x[i]*x[i];
	memset(a,0,sizeof a);
	const int zero=40000;
	a[0][zero]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=80000;j++){
			if(a[i-1][j]) a[i][j+x[i]]=a[i][j-x[i]]=1;
		}
	}
	for(int i=0;i<40000;i++){
		if(a[n][zero+i]||a[n][zero-i]){
			ans+=i*i;break;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	calc();
	for(int i=1;i<=n;i++) x[i]=y[i];
	calc();
	printf("%.2f\n",ans/2.0);
	return 0;
}
