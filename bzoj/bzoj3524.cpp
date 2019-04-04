#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int root[500006];
int tot;
int ls[10000060],rs[10000060],sum[10000060];
int add(int o,int l,int r,int pos){
	int p=++tot;
	sum[p]=sum[o]+1;
	if(l==r) return p;
	int mid=(l+r)>>1;
	if(pos<=mid) ls[p]=add(ls[o],l,mid,pos),rs[p]=rs[o];
	else ls[p]=ls[o],rs[p]=add(rs[o],mid+1,r,pos);
	return p;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		root[i]=add(root[i-1],1,n,x);
	}
	for(int i=0,a,b,l,r;i<m;i++){
		scanf("%d%d",&a,&b);
		a--;
		int k=(b-a)/2;
		l=1,r=n;
		a=root[a],b=root[b];
		while(l!=r){
			int tmp=sum[b]-sum[a];
			if(tmp<=k) break;
			else{
				tmp=sum[ls[b]]-sum[ls[a]];
				if(tmp>k){
					r=(l+r)>>1;
					a=ls[a];b=ls[b];
				}else{
					l=(l+r)/2+1;
					a=rs[a],b=rs[b];
				}
			}
		}
		if(l==r&&sum[b]-sum[a]>k){
			printf("%d\n",l);
		}else puts("0");
	}
	return 0;
}
