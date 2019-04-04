#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[100005];
int n;
long long ans;
int j;
const double eps=1e-8;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&f[i]);
	}
	sort(f,f+n);
	for(int i=0;i<n;i++){
		while(f[j]+eps<f[i]*0.9) j++;
		ans+=i-j;
	}
	printf("%lld\n",ans);
	return 0;
}
