#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const int MAXN=50005;
int n,m,pos[MAXN],c[MAXN];
LL s[MAXN],ans;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
LL sqr(LL x){
	return x*x;
}
struct data{
	int l,r,id;
	LL a,b;
}a[MAXN];
bool cmp(const data&a,const data&b){
	if(pos[a.l]==pos[b.l]) return a.r<b.r;
	return a.l<b.l;
}
bool cmp_id(const data&a,const data&b){
	return a.id<b.id;
}
void update(int p,int add){
	ans-=sqr(s[c[p]]);
	s[c[p]]+=add;
	ans+=sqr(s[c[p]]);
}
void solve(){
	for(int i=1,l=1,r=0;i<=m;i++){
		for(;r<a[i].r;r++) update(r+1,1);
		for(;r>a[i].r;r--) update(r,-1);
		for(;l<a[i].l;l++) update(l,-1);
		for(;l>a[i].l;l--) update(l-1,1);
		if(a[i].l==a[i].r){
			a[i].a=0;a[i].b=1;
			continue;
		}
		a[i].a=ans-(a[i].r-a[i].l+1);
		a[i].b=(a[i].r-a[i].l+1)*1LL*(a[i].r-a[i].l);
		LL g=gcd(a[i].a,a[i].b);
		a[i].a/=g;a[i].b/=g;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	int block=sqrt(n);
	for(int i=1;i<=n;i++) pos[i]=(i-1)/block+1;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].id=i;
	}
	sort(a+1,a+m+1,cmp);
	solve();
	sort(a+1,a+m+1,cmp_id);
	for(int i=1;i<=m;i++){
		printf("%lld/%lld\n",a[i].a,a[i].b);
	}
	
	return 0;
}
//modui algorithm
