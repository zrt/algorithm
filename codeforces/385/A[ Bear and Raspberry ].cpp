#include<iostream>
#include<cstdio>
//by zrt
//problem:cf0
using namespace std;
int ans=0;
int n,c,a[105],tmp;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n-1;i++){
		if((tmp=a[i]-a[i+1]-c)>0) {
			ans=max(ans,tmp);
		}
	}
	printf("%d",ans);
	return 0;
}

