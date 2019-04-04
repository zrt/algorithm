#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int a[50005];
int to[50005],cc;
struct N{
	int l,r,id,p;
	friend bool operator < (const N&a,const N&b){
		if(a.id!=b.id) return a.id<b.id;
		return a.r<b.r;
	}
}q[50005];
int SIZE;
long long Ans;
long long ans[50005];
int c[50005];
#define lowbit(x) ((x)&-(x))
void add(int x,int d){
	while(x<=n){
		c[x]+=d;
		x+=lowbit(x);
	}
}
int ask(int x){
	int ret=0;
	while(x>0){
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),to[i]=a[i];
	sort(to+1,to+n+1);
	cc=unique(to+1,to+n+1)-(to+1);
	for(int i=1;i<=n;i++) a[i]=lower_bound(to+1,to+cc+1,a[i])-to;
	SIZE=sqrt(n+1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].p=i;q[i].id=(q[i].l-1)/SIZE+1;
	}
	sort(q+1,q+m+1);
	int L=1,R=0;
	for(int i=1;i<=m;i++){
		while(L<q[i].l) add(a[L],-1),Ans-=ask(a[L]-1),L++;
		while(R>q[i].r) add(a[R],-1),Ans-=R-L-ask(a[R]),R--;
		while(L>q[i].l) add(a[L-1],1),Ans+=ask(a[L-1]-1),L--;
		while(R<q[i].r) add(a[R+1],1),Ans+=R-L+2-ask(a[R+1]),R++;
		ans[q[i].p]=Ans;
	}
	for(int i=1;i<=m;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}
