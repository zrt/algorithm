#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k;
struct N{
	int l,r,id,p;
	friend bool operator < (const N&a,const N&b){
		if(a.id!=b.id) return a.id<b.id;
		return a.r<b.r;
	}
}q[50005];
int a[50005];
typedef long long LL;
LL Ans,ans[50005];
int c[50005];
int SIZE;
void upd(int val,int t){
	Ans-=c[val]*1LL*c[val];
	c[val]+=t;
	Ans+=c[val]*1LL*c[val];
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	SIZE=sqrt(n+1);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=(q[i].l-1)/SIZE+1;
		q[i].p=i;
	}
	sort(q+1,q+m+1);
	int L=1,R=0;
	for(int i=1;i<=m;i++){
		while(L<q[i].l) upd(a[L],-1),L++;
		while(R>q[i].r) upd(a[R],-1),R--;
		while(L>q[i].l) upd(a[L-1],1),L--;
		while(R<q[i].r) upd(a[R+1],1),R++;
		ans[q[i].p]=Ans;
	}
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}
