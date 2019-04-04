#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:POJ2299 merge-sort
using namespace std;
int a[500005],tmp[500005],n;
long long cnt;
void merge(int l,int mid,int r){
	int p=l,q=mid+1,pos=l;
	while(p<=mid&&q<=r){
		if(a[p]<=a[q]){
			tmp[pos++]=a[p++];
		}else{
			cnt+=mid-p+1;
			tmp[pos++]=a[q++];
		}
	}
	if(q==r+1){
		while(p<=mid){
			tmp[pos++]=a[p++];
		}
	}
	for(int i=l;i<pos;i++){
		a[i]=tmp[i];
	}
}
void merge_sort(int l,int r){
	if(l==r) return;
	else if(l==r-1) {
		if(a[l]>a[r]){
			cnt++;
			swap(a[l],a[r]);
		}
	}
	else{
		//mid belong to left qujian quan bi
		int mid=(l+r)>>1;
		merge_sort(l,mid);
		merge_sort(mid+1,r);
		merge(l,mid,r);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d",&n)==1&&n){
		cnt=0;
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		merge_sort(0,n-1);
		cout<<cnt<<'\n';
	}
	return 0;
}
