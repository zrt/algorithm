#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int mx;
int a[200005],b[200005],cc;
struct N{
	int l,r,id,p;
	friend bool operator < (const N&a,const N&b){
		if(a.id!=b.id) return a.id<b.id;
		return a.r<b.r;
	}
}q[200005];
int SIZE;
int ans[200005];
int siz[200005];
int num[200005];
void upd(int val,int t){
	int id=val/SIZE+1;
	if(num[val]) siz[id]--;
	num[val]+=t;
	if(num[val]) siz[id]++;
}
int ask(){
	for(int i=1;;i++){
		if(siz[i]==SIZE) continue;
		for(int j=(i-1)*SIZE;;j++){
			if(!num[j]) return j;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	mx=n+2;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) if(a[i]>mx) a[i]=mx;
	SIZE=sqrt(n+1);
	// i-th block (i-1)*SIZE+1 .. i*SIZE
	// i-th belong to (i-1)/SIZE+1
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=(q[i].l-1)/SIZE+1;q[i].p=i;
	}
	sort(q+1,q+m+1);
	int L=1,R=0;
	for(int i=1;i<=m;i++){
		while(L<q[i].l) upd(a[L],-1),L++;
		while(R>q[i].r) upd(a[R],-1),R--;
		while(L>q[i].l) upd(a[L-1],1),L--;
		while(R<q[i].r) upd(a[R+1],1),R++;
		ans[q[i].p]=ask();
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
