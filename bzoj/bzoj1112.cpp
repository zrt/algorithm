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
LL n,k;
LL a[100005];
LL num[100005],sum[100005],ls[100005],rs[100005],val[100005],fa[100005],siz[100005];
inline void upd(int o){
	siz[o]=siz[ls[o]]+siz[rs[o]]+num[o];
	sum[o]=num[o]*val[o]+sum[ls[o]]+sum[rs[o]];
}
inline void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[rs[x]]=y;
	else ls[y]=0;
	fa[x]=fa[y];
	if(fa[y]){
		if(ls[fa[y]]==y) ls[fa[y]]=x;else rs[fa[y]]=x;
	}
	fa[y]=x;rs[x]=y;
	upd(y);
}
inline void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;
	else rs[y]=0;
	fa[x]=fa[y];
	if(fa[y]){
		if(ls[fa[y]]==y) ls[fa[y]]=x;else rs[fa[y]]=x;
	}
	fa[y]=x;ls[x]=y;
	upd(y);
}
int root;
inline void splay(int x,int z){
	while(fa[x]!=z){
		int y=fa[x];
		if(fa[y]==z){
			if(ls[y]==x) zig(x);
			else zag(x);
		}else{
			if(ls[fa[y]]==y){
				if(ls[y]==x){
					zig(y),zig(x);
				}else{
					zag(x);zig(x);
				}
			}else{
				if(ls[y]==x){
					zig(x),zag(x);
				}else{
					zag(y),zag(x);
				}
			}
		}
	}
	if(!z) root=x;
	upd(x);
}
int c;
inline void insert(LL x){
	int o=root;
	int f=0;
	while(o){
		f=o;
		if(val[o]==x){
			num[o]++;
			splay(o,0);
			return;
		}
		if(x<val[o]){
			o=ls[o];
		}else{
			o=rs[o];
		}
	}
	o=++c;
	if(f){
		if(x<val[f]){
			ls[f]=o;
		}else{
			rs[f]=o;
		}
	}else root=o;
	fa[o]=f;
	val[o]=x;
	num[o]=1;
	splay(o,0);
}
inline void del(LL x){
	int o=root;
	while(1){
		if(val[o]==x){
			num[o]--;
			splay(o,0);
			return;
		}
		if(x<val[o]){
			o=ls[o];
		}else o=rs[o];
	}
}
inline void ask(int k){
	int o=root;
	while(1){
		if(siz[ls[o]]>=k) {
			o=ls[o];continue;
		}
		if(siz[ls[o]]+num[o]>=k) {
			splay(o,0);return;
		}else{
			k-=siz[ls[o]]+num[o];
			o=rs[o];
		}
	}
}
LL ans;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	ans=inf*1LL*1000000;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<k;i++){
		insert(a[i]);
	}
	for(int i=k;i<=n;i++){
		if(i>k){
			del(a[i-k]);
		}
		insert(a[i]);
		ask((k+1)/2);
		LL aim=val[root];
		ans=min(ans,siz[ls[root]]*aim-sum[ls[root]]+sum[rs[root]]-siz[rs[root]]*aim);
	}
	printf("%lld\n",ans);
	return 0;
}
