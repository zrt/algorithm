#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
long long  a[200005], b[200005];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++) scanf("%I64d",&a[i]);
	b[1] = 0;
	b[n] = a[1];
	for(int i=2;i<=n/2;i++){
		b[i] = max(b[i-1], a[i]-b[n-(i-1)+1]);
		b[n-i+1] = a[i]- b[i];
	}
	for(int i=1;i<=n;i++){
		printf("%I64d ",b[i]);
	}

	return 0;
}
