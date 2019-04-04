#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int n;
LL x[200005];
LL r[200005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++) scanf("%I64d",&x[i]);
	int ok=1;
	for(int i=1;i<=n/2 && ok;i++){
		LL mxr1=-1,mxr2=-1;
		for(int j=1;j*j<x[i];j++){
			if(x[i]%j==0){
				LL a = j;
				LL b = x[i]/j;
				if((a+b)%2 !=0) continue;
				LL r1 = (b-a)/2;
				LL r2 = (a+b)/2;
				if(r1 <= r[(i-1)*2]) continue;
				if(mxr2 == -1 || r2 < mxr2){
					mxr1 = r1;
					mxr2 = r2;
				}
			}
		}
		if(mxr2 == -1){
			ok = 0;
			break;
		}
		r[i*2-1] = mxr1;
		r[i*2  ] = mxr2;
	}

	for(int i=2;i<=n;i++){
		if(r[i]<=r[i-1]){
			ok=0;break;
		}
	}

	if(!ok) puts("No");
	else puts("Yes");
	if(ok){
		for(int i=1;i<=n;i++){
			printf("%I64d ",r[i]*r[i] - r[i-1]*r[i-1]);
		}
	}

	

	return 0;
}