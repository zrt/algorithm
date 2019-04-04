#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n;
int a[105];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int sum = 0;
	for(int i=1;i<=n;i+=2){
		sum += a[i+1]-a[i];
	}
	printf("%d\n",sum);



	return 0;
}
