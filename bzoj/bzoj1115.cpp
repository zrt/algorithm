#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n,a[1005],b[1005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int tt;
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) b[i-1]=a[i]-a[i-1];
		int sg=0;
		for(int i=0;i<n;i++){
			if((i&1)!=(n&1)){
				sg^=b[i];
			}
		}
		if(sg){
			puts("TAK");
		}else{
			puts("NIE");
		}
	}
	return 0;
}
