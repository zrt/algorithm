#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
struct N{
	int l,r;long long c;
}a[10005];
int n,m,e;
bool cmp(N a,N b){
	return a.l<b.l;
}
long long f[86499*4];
bool lazy[86499*4];
int _l,_r;
long long _c;
void upd(int o){
	if(lazy[o]){
		lazy[o]=0;
		f[o<<1]=min(f[o<<1],f[o]);
		f[o<<1|1]=min(f[o<<1|1],f[o]);
		lazy[o<<1]=1;
		lazy[o<<1|1]=1;
	}
}
void ask(int o,int l,int r,int pos){
	if(l==r){
		_c=f[o];
		return;
	}else{
		int m=l+(r-l)/2;
		upd(o);
		if(pos<=m){
			ask(o<<1,l,m,pos);
		}else{
			ask(o<<1|1,m+1,r,pos);
		}
	}
}
void add(int o,int l,int r){
	if(_l<=l&&r<=_r){
		f[o]=min(f[o],_c);
		lazy[o]=1;
		return;
	}else{
		int m=(l+r)>>1;
		upd(o);
		if(_l<=m) add(o<<1,l,m);
		if(_r>m) add(o<<1|1,m+1,r);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&m,&e);
	m+=2;e+=2;
	for(int i=1;i<=n;i++){
		scanf("%d%d%lld",&a[i].l,&a[i].r,&a[i].c);
		a[i].l+=2;
		a[i].r+=2;
	}
	memset(f,0x3f,sizeof f);
	sort(a+1,a+n+1,cmp);
	_l=1,_r=m-1;_c=0;
	add(1,1,86499);
	for(int i=1;i<=n;i++){
		ask(1,1,86499,a[i].l-1);
		_l=a[i].l,_r=a[i].r,_c+=a[i].c;
		add(1,1,86499);
	}
	ask(1,1,86499,e);
	if(_c==0x3f3f3f3f3f3f3f3f) puts("-1");
	else printf("%lld\n",_c);
	return 0;
}
