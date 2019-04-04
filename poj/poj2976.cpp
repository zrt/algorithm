#include<cstdio>
#include<iostream>
#include<algorithm> 
using namespace std;
int n,k;
int a[1000],b[1000];
double c[1000];
bool jud(double mid){
	for(int i=0;i<n;i++){
		c[i]=(double)a[i]-(double)b[i]*mid;
	}
	double ret=0.0;
	sort(c,c+n);
	for(int p=k;p<n;p++){
		ret+=c[p];
	}
	if(ret>0.0){
		return true;
	}else{
		return false;
	}
}
int main(){
	while(scanf("%d%d",&n,&k)==2&&n){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		double l=0.0,r=1.0;
		for(int i=1;i<=100;i++){
			double mid=(l+r)/2.0;
			if(jud(mid)){//true mid small false mid large
				l=mid;
			}
			else{
				r=mid;
			}
		}
		printf("%.0f\n",l*100);
	}
	return 0;
}
//有序序列从小到大递增  