#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;
int n,a[105];
int minn,minx,maxn,maxx;
bool getx(int n){
	maxn=0;minn=1<<30;
	for(int i=0;i<n;i++){
		if(a[i]>maxn){
			maxn=a[i];maxx=i;
		}
		if(a[i]<minn){
			minn=a[i];minx=i;
		}
	}
	if(maxn!=minn){
		return true;
	}else{
		return false;
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	while(getx(n)){
		a[maxx]-=a[minx];
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}	
	printf("%d",sum);
	return 0;
}

