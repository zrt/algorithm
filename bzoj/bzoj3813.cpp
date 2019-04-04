#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int n=100000;
const int MAXN=100005;
long long h[MAXN<<2];
const int mod=19961993;
int prime[61]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,};
int a[MAXN<<2];
int m;
int ans;long long ansh;
int _l,_r;
void merge(int x,int y,int z){
	h[x]=h[y]|h[z];
	a[x]=a[y]*1LL*a[z]%mod;
	long long t=h[y]&h[z];
	for(int i=0;i<60;i++) if(t&(1LL<<i)) a[x]=a[x]*1LL*prime[i]%mod;
}
void bd(int o,int l,int r){
	if(l==r){
		a[o]=1;
		h[o]=2;
	}else{
		int mid=(l+r)>>1;
		bd(o<<1,l,mid);
		bd(o<<1|1,mid+1,r);
		merge(o,o<<1,o<<1|1);
	}
}
void upd(int o,int l,int r,int pos,int w){
	if(l==r){
		h[o]=0;
		for(int i=0;i<60;i++){
			if(w%prime[i]==0){
				w/=prime[i];
				h[o]|=1LL<<i;
			}
		}
		a[o]=w;
	}else{
		int mid=(l+r)>>1;
		if(pos<=mid) upd(o<<1,l,mid,pos,w);
		else upd(o<<1|1,mid+1,r,pos,w);
		merge(o,o<<1,o<<1|1);
	}
}
void ask(int o,int l,int r){
	if(_l<=l&&r<=_r){
		ans=ans*1LL*a[o]%mod;
		long long t=ansh&h[o];
		ansh|=h[o];
		for(int i=0;i<60;i++) if(t&(1LL<<i)) ans=ans*1LL*prime[i]%mod;
	}else{
		int mid=(l+r)>>1;
		if(_l<=mid) ask(o<<1,l,mid);
		if(_r>mid) ask(o<<1|1,mid+1,r);
	}
}
int main(){
	scanf("%d",&m);
	bd(1,1,n);
	int t,x,y;
	while(m--){
		scanf("%d%d%d",&t,&x,&y);
		if(t&1){
			upd(1,1,n,x,y);
		}else{
			ans=1;ansh=0;
			_l=x,_r=y;
			ask(1,1,n);
	//		printf("%d %lld\n",ans,ansh);
			for(int i=0;i<60;i++) if(ansh&(1LL<<i)) ans=ans*1LL*(prime[i]-1)%mod;
			printf("%d\n",ans);
		}
	}
	return 0;
}
