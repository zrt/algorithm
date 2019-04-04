#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef long double ld;
int n;
LL w;
struct N{
	LL s,q;
	ld sq;
	void read(){
		scanf("%lld%lld",&s,&q);
		sq=s/(ld)q;
	}
	friend bool operator < (const N&a,const N&b){
		return a.sq<b.sq;
	}
}a[500005];
LL ans;
LL sum[80000];
int siz[80000];
void add(int o,int l,int r,int pos){
	if(l==r){
		siz[o]++;
		sum[o]+=l;
	}else{
		int mid=(l+r)>>1;
		if(pos<=mid) add(o<<1,l,mid,pos);
		else add(o<<1|1,mid+1,r,pos);
		siz[o]=siz[o<<1]+siz[o<<1|1];
		sum[o]=sum[o<<1]+sum[o<<1|1];
	}
}
void add(N a){
	add(1,1,20000,a.q);
}
LL ask(ld k){
	int o=1,l=1,r=20000;
	ld W=w;
	int ret=0;
	while(l!=r){
		int mid=(l+r)>>1;
		if(sum[o<<1]*k>W) o=o<<1,r=mid;
		else W-=sum[o<<1]*k,ret+=siz[o<<1],o=o<<1|1,l=mid+1;
	}
	int tt=W/(l*k);
	return ret+min(tt,siz[o]);
}
int main(){
	scanf("%d%lld",&n,&w);
	for(int i=1;i<=n;i++) a[i].read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		add(a[i]);
		ans=max(ans,ask(a[i].sq));
	}
	printf("%lld\n",ans);	
	return 0;
}
