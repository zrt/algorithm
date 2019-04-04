#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
#define int LL
struct opt{
	int t,x;
}p[100005];
int n,L,R;
char s[10];
int a[100005],b[100005],c[100005],m;
int mn[100005<<2],mx[100005<<2];
int lazy1[100005<<2],lazy2[100005<<2],lazy3[100005<<2];
// default lazy1 == 1 lazy2/3 ==0
// val= val * lazy1 + lazy2 + lazy3 * a[pos]
void bd(int o,int l,int r){
	lazy1[o]=1;lazy2[o]=lazy3[o]=0;
	if(l==r){
		mn[o]=mx[o]=a[l];
	}else{
		int mid=(l+r)>>1;
		bd(o<<1,l,mid);
		bd(o<<1|1,mid+1,r);
		mn[o]=mn[o<<1];
		mx[o]=mx[o<<1|1];
	}
}
void do_1(int o,int l,int r,int x){
	mn[o]*=x;mx[o]*=x;
	lazy1[o]*=x;lazy2[o]*=x;lazy3[o]*=x;
}
void do_2(int o,int l,int r,int x){
	mn[o]+=x;mx[o]+=x;
	lazy2[o]+=x;
}
void do_3(int o,int l,int r,int x){
	mn[o]+=x*a[l];mx[o]+=x*a[r];
	lazy3[o]+=x;
}
void down(int o,int l,int r){
	int mid=(l+r)>>1;
	if(lazy1[o]!=1){
		do_1(o<<1,l,mid,lazy1[o]);
		do_1(o<<1|1,mid+1,r,lazy1[o]);
		lazy1[o]=1;
	}
	if(lazy2[o]){
		do_2(o<<1,l,mid,lazy2[o]);
		do_2(o<<1|1,mid+1,r,lazy2[o]);
		lazy2[o]=0;
	}
	if(lazy3[o]){
		do_3(o<<1,l,mid,lazy3[o]);
		do_3(o<<1|1,mid+1,r,lazy3[o]);
		lazy3[o]=0;
	}
}
void up(int o){
	mn[o]=mn[o<<1];
	mx[o]=mx[o<<1|1];
}


void dfs(int o,int l,int r){
	if(l==r){
		c[l]=mn[o];
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		dfs(o<<1,l,mid);
		dfs(o<<1|1,mid+1,r);
	}
}
int getL_0(int x){
	int o=1,l=1,r=m;
	while(l!=r){
		int mid=(l+r)>>1;
		down(o,l,r);
		if(mn[o<<1|1]+x<L) o=o<<1|1,l=mid+1;
		else o=o<<1,r=mid;
	}
	if(mn[o]+x>=L) return 0;
	else return l;
}
int getR_0(int x){
	int o=1,l=1,r=m;
	while(l!=r){
		int mid=(l+r)>>1;
		down(o,l,r);
		if(mx[o<<1]+x>R) o=o<<1,r=mid;
		else o=o<<1|1,l=mid+1;
	}
	if(mx[o]+x<=R) return m+1;
	else return l;
}
int getL_2(int x){
	int o=1,l=1,r=m;
	while(l!=r){
		int mid=(l+r)>>1;
		down(o,l,r);
		if(mn[o<<1|1]*x<L) o=o<<1|1,l=mid+1;
		else o=o<<1,r=mid;
	}
	if(mn[o]*x>=L) return 0;
	else return l;
}
int getR_2(int x){
	int o=1,l=1,r=m;
	while(l!=r){
		int mid=(l+r)>>1;
		down(o,l,r);
		if(mx[o<<1]*x>R) o=o<<1,r=mid;
		else o=o<<1|1,l=mid+1;
	}
	if(mx[o]*x<=R) return m+1;
	else return l;
}
int getL_3(int x){
	int o=1,l=1,r=m;
	while(l!=r){
		int mid=(l+r)>>1;
		down(o,l,r);
		if(mn[o<<1|1]+x*a[mid+1]<L) o=o<<1|1,l=mid+1;
		else o=o<<1,r=mid;
	}
	if(mn[o]+x*a[l]>=L) return 0;
	else return l;
}
int getR_3(int x){
	int o=1,l=1,r=m;
	while(l!=r){
		int mid=(l+r)>>1;
		down(o,l,r);
		if(mx[o<<1]+x*a[mid]>R) o=o<<1,r=mid;
		else o=o<<1|1,l=mid+1;
	}
	if(mx[o]+x*a[l]<=R) return m+1;
	else return l;
}
void set(int o,int l,int r,int L,int R,int x){
	if(l==L&&r==R){
		mn[o]=mx[o]=x;
		lazy1[o]=lazy3[o]=0;
		lazy2[o]=x;
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid) set(o<<1,l,mid,L,R,x);
		else if(L>mid) set(o<<1|1,mid+1,r,L,R,x);
		else set(o<<1,l,mid,L,mid,x),set(o<<1|1,mid+1,r,mid+1,R,x);
		up(o);
	}
}
void setL(int x){
	// 1..x -> L
	set(1,1,m,1,x,L);
}
void setR(int x){
	// x..m -> R
	set(1,1,m,x,m,R);
}
void change0(int o,int l,int r,int L,int R,int x){
	if(l==L&&r==R){
		do_2(o,l,r,x);
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid) change0(o<<1,l,mid,L,R,x);
		else if(L>mid) change0(o<<1|1,mid+1,r,L,R,x);
		else change0(o<<1,l,mid,L,mid,x),change0(o<<1|1,mid+1,r,mid+1,R,x);
		up(o);
	}
}
void change2(int o,int l,int r,int L,int R,int x){
	if(l==L&&r==R){
		do_1(o,l,r,x);
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid) change2(o<<1,l,mid,L,R,x);
		else if(L>mid) change2(o<<1|1,mid+1,r,L,R,x);
		else change2(o<<1,l,mid,L,mid,x),change2(o<<1|1,mid+1,r,mid+1,R,x);
		up(o);
	}
}
void change3(int o,int l,int r,int L,int R,int x){
	if(l==L&&r==R){
		do_3(o,l,r,x);
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid) change3(o<<1,l,mid,L,R,x);
		else if(L>mid) change3(o<<1|1,mid+1,r,L,R,x);
		else change3(o<<1,l,mid,L,mid,x),change3(o<<1|1,mid+1,r,mid+1,R,x);
		up(o);
	}
}
#undef int
int main(){
	#define int LL
	scanf("%lld%lld%lld",&n,&L,&R);
	for(int i=0;i<n;i++){
		scanf("%s%lld",s,&p[i].x);
		switch(s[0]){
			case '+' :
				p[i].t=0;
				break;
			case '-' :
				p[i].t=0;p[i].x*=-1;
				break;
			case '*' :
				p[i].t=2;
				break;
			case '@' :
				p[i].t=3;
				break;
		}
	}
	scanf("%lld",&m);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);b[i]=a[i];
	}
	sort(a+1,a+m+1);
	bd(1,1,m);
	for(int i=0;i<n;i++){
		if(p[i].t==0){
			int l=getL_0(p[i].x);
			int r=getR_0(p[i].x);
			// L+1..R-1
			if(l+1<=r-1)change0(1,1,m,l+1,r-1,p[i].x);
			if(l>=1) setL(l);
			if(r<=m) setR(r);
		}else if(p[i].t==2){
			int l=getL_2(p[i].x);
			int r=getR_2(p[i].x);
			// L+1..R-1
			if(l+1<=r-1)change2(1,1,m,l+1,r-1,p[i].x);
			if(l>=1) setL(l);
			if(r<=m) setR(r);
		}else{
			int l=getL_3(p[i].x);
			int r=getR_3(p[i].x);
			// L+1..R-1
			if(l+1<=r-1)change3(1,1,m,l+1,r-1,p[i].x);
			if(l>=1) setL(l);
			if(r<=m) setR(r);
		}
	}
	dfs(1,1,m);
	for(int i=1;i<=m;i++){
		printf("%lld\n",c[lower_bound(a+1,a+m+1,b[i])-a]);
	}
	return 0;
}
