#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,m,k,d;
LL mx[200005*4],ls[200005*4],rs[200005*4],s[200005*4];
void up(int o){
	s[o]=s[o<<1]+s[o<<1|1];
	ls[o]=max(ls[o<<1],s[o<<1]+ls[o<<1|1]);
	rs[o]=max(rs[o<<1|1],s[o<<1|1]+rs[o<<1]);
	mx[o]=max(max(mx[o<<1],mx[o<<1|1]),ls[o<<1|1]+rs[o<<1]);
}
void bd(int o,int l,int r){
	if(l==r){
		s[o]=mx[o]=ls[o]=rs[o]=-k;
	}else{
		int mid=(l+r)/2;
		bd(o<<1,l,mid);bd(o<<1|1,mid+1,r);
		up(o);
	}
}
void add(int o,int l,int r,int p,int k){
	if(l==r){
		s[o]+=k;
		mx[o]=ls[o]=rs[o]=s[o];
	}else{
		int mid=(l+r)/2;
		if(p<=mid) add(o<<1,l,mid,p,k);
		else add(o<<1|1,mid+1,r,p,k);
		up(o);
	}
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	bd(1,1,n);
	for(int i=0,r,x;i<m;i++){
		scanf("%d%d",&r,&x);
		add(1,1,n,r,x);
		if(mx[1]>d*k){
			puts("NIE");
		}else puts("TAK");
	}
	return 0;
}
