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
int tt;
int n;
unsigned  pow[10005];
struct SegmentTree{
	unsigned  hash[40005];
	void build(){
		memset(hash,0,sizeof hash);
	}
	int _pos;
	void add(int pos){
		_pos=pos;
		change(1,1,n);
	}
	void change(int o,int l,int r){
		if(l==r){
			hash[o]=17;
		}else{
			int m=(l+r)>>1;
			if(_pos<=m) change(o<<1,l,m);
			else change(o<<1|1,m+1,r);
			hash[o]=hash[o<<1]*pow[r-m]+hash[o<<1|1];
		}
	}
	unsigned ask(int o,int l,int r,int L,int R){
		if(L==l&&R==r) return hash[o];
		else{
			int m=(l+r)>>1;
			unsigned  p,q;
			if(R<=m){
				return ask(o<<1,l,m,L,R);
			}else if(L>m){
				return ask(o<<1|1,m+1,r,L,R);
			}else{
				p=ask(o<<1,l,m,L,m);
				q=ask(o<<1|1,m+1,r,m+1,R);
				return p*pow[R-m]+q;
			}
		}
	}
}t1,t2;
int a[10005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	pow[0]=1;
	for(int i=1;i<=10005;i++) pow[i]=pow[i-1]*27;
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		t1.build();t2.build();
		bool flag=1;
		for(int i=0;i<n;i++){
			t1.add(a[i]);t2.add(n-a[i]+1);
			int L=min(a[i],n-a[i]+1);
			if(t1.ask(1,1,n,a[i]-L+1,a[i])!=t2.ask(1,1,n,n-a[i]-L+2,n-a[i]+1)) {
				flag=0,puts("Y");break;
			}
		}
		if(flag) puts("N");
	}
	return 0;
}
