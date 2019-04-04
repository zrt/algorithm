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
int n;
int a[25];
int b[25];
int sum;
bool ok[25];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=1;i<=n;i++) b[i]=a[i]+b[i-1];
	int ans=0;
	if(sum&1) {
		puts("0");
		goto ed;
	}
	for(int i=1;i<=n;i++){
		if(b[i-1]>=sum/2) break;
		for(int j=i;j<=n;j++){
			if(b[j]-b[i-1]==sum/2) {
				ans++;break;
			}
		}
	}
	printf("%d\n",ans*(ans-1)/2);
	ed:
	return 0;
}
