#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
//suo qiu chuan chang bi wei oushu
//lijie manacher
int n;
char a[500005];
int r[500005];// huiwen banjing
long long ans;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%s",&n,a);
	int i(0),j(0);
	for(;i<n-1;){
		while(i-j>=0&&i+j+1<n&&a[i-j]!=a[i+j+1]) j++;
		r[i]=j;ans+=j;
		int k=1;
		while(i-k>=0&&k<=j&&r[i-k]<j-k){
			ans+=(r[i+k]=min(r[i-k],j-k));
			k++;
		}
		j=max(j-k,0);i+=k;
	}
	printf("%lld\n",ans);
	return 0;
}
