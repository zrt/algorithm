#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[100005];
int to[100005],cc;
int root[100005];
int ls[100005*40],rs[100005*40];
int siz[100005*40];
int tot;
int insert(int o,int l,int r,int d){
	int now=++tot;
	siz[now]=siz[o]+1;
	if(l==r){
		return now;
	}else{
		int mid=(l+r)/2;
		if(d<=mid) ls[now]=insert(ls[o],l,mid,d),rs[now]=rs[o];
		else rs[now]=insert(rs[o],mid+1,r,d),ls[now]=ls[o];
	}
	return now;
}
int ask(int o1,int o2,int l,int r,int k){
	if(l==r){
		return l;
	}else{
		int mid=(l+r)/2;
		int sum=(siz[ls[o2]]-siz[ls[o1]]);
		if(k<=sum) return ask(ls[o1],ls[o2],l,mid,k);
		else return ask(rs[o1],rs[o2],mid+1,r,k-sum);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),to[i]=a[i];
	sort(to+1,to+n+1);
	cc=unique(to+1,to+n+1)-(to+1);
	for(int i=1;i<=n;i++) a[i]=lower_bound(to+1,to+n+1,a[i])-to;
	for(int i=1;i<=n;i++) root[i]=insert(root[i-1],1,cc,a[i]);
	int l,r,k;
	while(m--){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",to[ask(root[l-1],root[r],1,cc,k)]);
	}
	//system("pause");
	return 0;
	
}
