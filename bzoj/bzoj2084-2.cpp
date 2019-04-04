#include<cstdio>
using namespace std;
int n;
char a[500005];
int r[500005];
long long ans;
inline int max(int a,int b){
	if(a>b) return a;
	return b;
}
inline int min(int a,int b){
	if(a<b) return a;
	return b;
}
int main(){
	scanf("%d%s",&n,a);
	int i(0),j(0),lim=n-1,k;
	for(;i<lim;){
		while(i-j>=0&&i+j+1<n&&a[i-j]!=a[i+j+1]) j++;
		ans+=(r[i]=j);
		k=1;
		while(i>=k&&k<=j&&r[i-k]<j-k){
			ans+=(r[i+k]=min(r[i-k],j-k));
			k++;
		}
		j=max(j-k,0);i+=k;
	}
	printf("%lld\n",ans);
	return 0;
}
