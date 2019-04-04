#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char s[10];
// sum+= a[i]*(i-L+1)*(R-i) = a[i]*(i*(R+L-1)-R*(L-1)-i*i)
typedef long long LL;
LL sum[400005],sumi[400005],sumi2[400005],lazy[400005];
LL gcd(LL x,LL y){
	return y?gcd(y,x%y):x;
}
LL si[400005],si2[400005];
void add(int o,int l,int r,int v){
	sum[o]+=v*1LL*(r-l+1);
	sumi[o]+=v*(si[r]-si[l-1]);
	sumi2[o]+=v*(si2[r]-si2[l-1]);
	lazy[o]+=v;
}
void down(int o,int l,int r){
	if(lazy[o]){
		int mid=(l+r)>>1;
		add(o<<1,l,mid,lazy[o]);
		add(o<<1|1,mid+1,r,lazy[o]);
		lazy[o]=0;
	}
}
int _l,_r;
void up(int o){
	sum[o]=sum[o<<1]+sum[o<<1|1];
	sumi[o]=sumi[o<<1]+sumi[o<<1|1];
	sumi2[o]=sumi2[o<<1]+sumi2[o<<1|1];
}
void cg(int o,int l,int r,int L,int R,int v){
	if(l==L&&r==R){
		add(o,l,r,v);
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid) cg(o<<1,l,mid,L,R,v);
		else if(L>mid) cg(o<<1|1,mid+1,r,L,R,v);
		else{
			cg(o<<1,l,mid,L,mid,v);
			cg(o<<1|1,mid+1,r,mid+1,R,v);
		}
		up(o);
	}
}
LL ask(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		return sumi[o]*(_r+_l-1)-sum[o]*_r*(_l-1)-sumi2[o];
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid) return ask(o<<1,l,mid,L,R);
		else if(L>mid) return ask(o<<1|1,mid+1,r,L,R);
		else{
			return
			ask(o<<1,l,mid,L,mid)+
			ask(o<<1|1,mid+1,r,mid+1,R);
		}
		//up(o);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) si[i]=si[i-1]+i,si2[i]=si2[i-1]+i*1LL*i;
	int l,r,v;
	while(m--){
		scanf("%s",s);
		if(s[0]=='C'){
			scanf("%d%d%d",&l,&r,&v);
			cg(1,1,n,l,r-1,v);
		}else{
			scanf("%d%d",&l,&r);
			_l=l,_r=r;
			LL fz=ask(1,1,n,l,r),fm=(r-l)*1LL*(r-l+1)/2;
			LL g=gcd(fz,fm);
			fz/=g,fm/=g;
			printf("%lld/%lld\n",fz,fm);
		}
	}
	
	return 0;
}
