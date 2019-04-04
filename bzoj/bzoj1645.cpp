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
struct N{
	int l,r,h;
}a[40005];
int n;
int cc;
int to[40005];
struct B{
	LL r,pos;
	int add;
	friend bool operator < (B a,B b){
		return a.pos<b.pos;
	}
}b[80005];
int num;
LL sum[40005*4];
int cov[40005*4];
void upd(int o,int l,int r){
	if(cov[o]){
		sum[o]=to[r+1]-to[l];
	}else if(l==r){
		sum[o]=0;
	}else{
		sum[o]=sum[o<<1]+sum[o<<1|1];
	}
}
void change(int o,int l,int r,int L,int R,int d){
	if(L<=l&&r<=R){
		cov[o]+=d;
		upd(o,l,r);
		return;
	}
	int m=(l+r)>>1;
	if(L<=m) change(o<<1,l,m,L,R,d);
	if(R>m)  change(o<<1|1,m+1,r,L,R,d);
	upd(o,l,r);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	to[++cc]=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].h);
	//	a[i].h-=1;
		to[++cc]=a[i].h;
	}
	sort(to+1,to+cc+1);
	cc=unique(to+1,to+cc+1)-(to+1);
	for(int i=1;i<=n;i++){
		a[i].h=lower_bound(to+1,to+cc+1,a[i].h)-to;
	}
	for(int i=1;i<=n;i++){
		num++;
		b[num].add=1;
		b[num].r=a[i].h;
		b[num].pos=a[i].l;
		num++;
		b[num].add=-1;
		b[num].r=a[i].h;
		b[num].pos=a[i].r;
	}
	sort(b+1,b+num+1);
	LL ans=0;
	for(int i=1;i<num;i++){
		change(1,1,cc+2,1,b[i].r-1,b[i].add);
		ans+=sum[1]*(b[i+1].pos-b[i].pos);
	}
	printf("%lld\n",ans);
	return 0;
}
