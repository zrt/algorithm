#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int a[50005];
int b[50005];
int last[50005];
int to[50005];
int n2;
int n,m;
int root[50005];
int sum[2000005];
int cc;
int ls[2000005];
int rs[2000005];
int mk(int l,int r){
	if(l==r){
		++cc;
		return cc;
	}else{
		int now=++cc;
		int mid=(l+r)>>1;
		ls[now]=mk(l,mid);
		rs[now]=mk(mid+1,r);
		return now;
	}
}

int add(int o,int pos,int l,int r){
	if(l==r){
		++cc;
		sum[cc]=sum[o]+1;
		return cc;
	}else{
		int mid=(l+r)>>1;
		int now=++cc;
		if(pos<=mid){
			ls[now]=add(ls[o],pos,l,mid);
			rs[now]=rs[o];
			sum[now]=sum[ls[now]]+sum[rs[now]];
			return now;
		}else{
			ls[now]=ls[o];
			rs[now]=add(rs[o],pos,mid+1,r);
			sum[now]=sum[ls[now]]+sum[rs[now]];
			return now;
		}
	}
}
int lim,_sum;
void ask(int Rtree,int Ltree,int l,int r){
	if(sum[Rtree]-sum[Ltree]==0) return;
	if(r<lim){
		_sum+=sum[Rtree]-sum[Ltree];
	}else{
		int mid=(l+r)>>1;
		ask(ls[Rtree],ls[Ltree],l,mid);
		if(mid+1<lim) ask(rs[Rtree],rs[Ltree],mid+1,r);
	}
}
int ask(int l,int r){
	//root[r]-root[l-1] < l
	_sum=0;lim=l+1;
	ask(root[r],root[l-1],1,50000);
	return _sum;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	root[0]=mk(1,50000);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),to[i]=a[i];
	sort(to+1,to+n+1);
	n2=unique(to+1,to+n+1)-(to+1);
	for(int i=1;i<=n;i++) a[i]=lower_bound(to+1,to+n2+1,a[i])-to;
	for(int i=1;i<=n;i++) b[i]=last[a[i]],last[a[i]]=i;
	for(int i=1;i<=n;i++){
		root[i]=add(root[i-1],b[i]+1,1,50000);
	}
	scanf("%d",&m);
	int x,y;
	while(m--){
		scanf("%d%d",&x,&y);
		printf("%d\n",ask(x,y));
	}
	return 0;
}
