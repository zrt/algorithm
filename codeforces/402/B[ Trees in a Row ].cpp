#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;
int n,k,a[1500];
int p[1500];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		int q=a[i];
		for(int j=i;j>=0;j--,q-=k){
			if(q<=0){
				 p[i]=1<<25;break;
			}
			if(a[j]!=q){
				p[i]++;
			}
		}
		q=a[i];
		for(int j=i;j<n;j++,q+=k){
			if(a[j]!=q) p[i]++;
		}
	}
	p[n]=n;
	int minn=1<<30,minx;
	for(int i=0;i<=n;i++){
		if(p[i]<minn){
			minn=p[i];minx=i;
		}
	}
	if(minx<n){
		int q=a[minx];
		for(int j=minx;j>=0;j--,q-=k){
			p[j]=q-a[j];
		}
		q=a[minx];
		for(int j=minx;j<n;j++,q+=k){
			p[j]=q-a[j];
		}
		printf("%d\n",minn);
		for(int i=0;i<n;i++){
			if(!p[i]) continue;
			else if(p[i]>0){
				printf("+ %d %d\n",i+1,p[i]);
			}else if(p[i]<0){
				printf("- %d %d\n",i+1,-p[i]);
			}
		}
	}else{
		int q=1;
		printf("%d\n",n);
		for(int i=0;i<n;i++,q+=k){
			if(q>a[i]){
				printf("+ %d %d\n",i+1,q-a[i]);
			}else{
				printf("- %d %d\n",i+1,a[i]-q);
			}
		}
	}
	return 0;
}

