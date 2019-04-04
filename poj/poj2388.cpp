#include<iostream>
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int a[10000];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int mid=n/2; 
	nth_element(a,a+mid,a+n);
	printf("%d",a[mid]);
	return 0;
}
