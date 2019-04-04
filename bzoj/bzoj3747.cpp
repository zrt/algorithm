#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int f[1000005],w[1000005];
long long mx[1000005<<2],lazy[1000005<<2];
int _l,_r,_c;
void up(int o){
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void down(int o){
	if(lazy[o]){
		mx[o<<1]+=lazy[o];
		mx[o<<1|1]+=lazy[o];
		lazy[o<<1]+=lazy[o];
		lazy[o<<1|1]+=lazy[o];
		lazy[o]=0;
	}
}
void add(int o,int l,int r){
	if(_l<=l&&r<=_r){
		mx[o]+=_c;
		lazy[o]+=_c;
	}else{
		down(o);
		int mid=(l+r)>>1;
		if(_l<=mid) add(o<<1,l,mid);
		if(_r>mid) add(o<<1|1,mid+1,r);
		up(o);
	}
}
int met[1000005],last[1000005];
long long ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&f[i]);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) last[i]=met[f[i]],met[f[i]]=i;
	for(int i=1;i<=n;i++){
		_l=last[i]+1,_r=i,_c=w[f[i]];
		add(1,1,n);
		if(last[i]){
			_l=last[last[i]]+1;
			_r=last[i];
			_c=-w[f[i]];
			add(1,1,n);
		}
		ans=max(ans,mx[1]);
	}
	printf("%lld\n",ans);
	return 0;
}
