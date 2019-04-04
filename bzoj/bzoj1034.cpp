#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[100006],b[100006];
int solve(int*a,int*b){
	int h1,t1,h2,t2;
	h1=h2=0;t1=t2=n;
	int ret(0);
	for(int i=0;i<n;i++){
		if(a[h1]>b[h2]){
			ret+=2;h1++;h2++;
		}else if(a[t1-1]>b[t2-1]){
			ret+=2;t1--;t2--;
		}else{
			if(a[h1]==b[t2-1]) ret+=1;
			h1++;t2--;
		}
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+n);
	printf("%d %d\n",solve(a,b),2*n-solve(b,a));
	return 0;
}
