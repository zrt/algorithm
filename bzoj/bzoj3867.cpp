#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q;
bool same[400000];
typedef long long LL;
LL mx[400000],num[400000];
int tt;
void bd(int o,int l,int r){
	if(l==r){
		mx[o]=num[l];
		same[o]=1;
	}else{
		int mid=(l+r)>>1;
		bd(o<<1,l,mid);
		bd(o<<1|1,mid+1,r);
		mx[o]=max(mx[o<<1],mx[o<<1|1]);
		same[o]=same[o<<1]&&same[o<<1|1]&&(mx[o<<1]==mx[o<<1|1]);
	}
}
void cg(int o,int l,int r,int L,int R,LL d){
	if(l==L&&r==R){
		same[o]=1;
		mx[o]=d;
	}else{
		int mid=(l+r)>>1;
		if(same[o]) mx[o<<1]=mx[o<<1|1]=mx[o],same[o<<1]=same[o<<1|1]=same[o];
		if(R<=mid) cg(o<<1,l,mid,L,R,d);
		else if(L>mid) cg(o<<1|1,mid+1,r,L,R,d);
		else{
			cg(o<<1,l,mid,L,mid,d);
			cg(o<<1|1,mid+1,r,mid+1,R,d);
		}
		mx[o]=max(mx[o<<1],mx[o<<1|1]);
		same[o]=same[o<<1]&&same[o<<1|1]&&(mx[o<<1]==mx[o<<1|1]);
	}
}
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
void _(int o,int l,int r,LL d){
	if(mx[o]<=d) return;
	if(same[o]){
		mx[o]=gcd(mx[o],d);
	}else{
		int mid=(l+r)>>1;
		_(o<<1,l,mid,d);
		_(o<<1|1,mid+1,r,d);
		mx[o]=max(mx[o<<1],mx[o<<1|1]);
		same[o]=same[o<<1]&&same[o<<1|1]&&(mx[o<<1]==mx[o<<1|1]);
	}
}
void to(int o,int l,int r,int L,int R,LL d){
	if(L==l&&R==r){
		_(o,l,r,d);
	}else{
		int mid=(l+r)>>1;
		if(same[o]) mx[o<<1]=mx[o<<1|1]=mx[o],same[o<<1]=same[o<<1|1]=same[o];
		if(R<=mid) to(o<<1,l,mid,L,R,d);
		else if(L>mid) to(o<<1|1,mid+1,r,L,R,d);
		else{
			to(o<<1,l,mid,L,mid,d);
			to(o<<1|1,mid+1,r,mid+1,R,d);
		}
		mx[o]=max(mx[o<<1],mx[o<<1|1]);
		same[o]=same[o<<1]&&same[o<<1|1]&&(mx[o<<1]==mx[o<<1|1]);
	}
}
void dfs(int o,int l,int r){
	if(same[o]){
		for(int i=l;i<=r;i++){
			printf("%lld ",mx[o]);
		}
	}else{
		int mid=(l+r)>>1;
		dfs(o<<1,l,mid);
		dfs(o<<1|1,mid+1,r);
	}
}
int main(){
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
		bd(1,1,n);
		LL t,l,r,x;
		scanf("%d",&q);
		while(q--){
			scanf("%lld%lld%lld%lld",&t,&l,&r,&x);
			if(t&1){
				cg(1,1,n,l,r,x);
			}else{
				to(1,1,n,l,r,x);
			}
		}
		dfs(1,1,n);
		puts("");
	}
	
	return 0;
}
