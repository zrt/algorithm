#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,a[100005];
int SIZE;
struct N{
	int l,r,a,b,p;
	friend bool operator < (const N&a,const N&b){
		if((a.l-1)/SIZE!=(b.l-1)/SIZE) return a.l<b.l;
		return a.r<b.r;
	}
}q[1000005];
int ans[1000005];
int c[100005];
int num[320];
void upd(int val,int t){
	int id=(val-1)/SIZE+1;
	if(c[val]) num[id]--;
	c[val]+=t;
	if(c[val]) num[id]++;
}
int ask(int x){
	int id=(x-1)/SIZE+1;
	int ret=0;
	for(int i=1;i<id;i++){
		ret+=num[i];
	}
	for(int i=(id-1)*SIZE+1;i<=x;i++){
		if(c[i]) ret++;
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	SIZE=sqrt(n+1);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&q[i].l,&q[i].r,&q[i].a,&q[i].b);
		q[i].p=i;
	}
	sort(q+1,q+m+1);
	int L=1,R=0;
	for(int i=1;i<=m;i++){
		while(L<q[i].l) upd(a[L],-1),L++;
		while(R>q[i].r) upd(a[R],-1),R--;
		while(L>q[i].l) upd(a[L-1],1),L--;
		while(R<q[i].r) upd(a[R+1],1),R++;
		ans[q[i].p]=ask(q[i].b)-ask(q[i].a-1);
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
