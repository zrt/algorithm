#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[300005];
//最小表示法
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int i=0,j=1;
	while(i<n&&j<n){
		int k=0;
		while(k<n&&a[(i+k)%n]==a[(j+k)%n]) k++;
		if(a[(i+k)%n]<a[(j+k)%n]) j+=k+1;
		else i+=k+1;
		if(i==j) j++;
	}
	if(i<n){
		for(int p=0;p<n-1;p++) printf("%d ",a[(i+p)%n]);
		printf("%d\n",a[(i+n-1)%n]);
	}else{
		for(int p=0;p<n-1;p++) printf("%d ",a[(j+p)%n]);
		printf("%d\n",a[(j+n-1)%n]);
	}
	return 0;
}
