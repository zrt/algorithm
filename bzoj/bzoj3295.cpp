#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
#define lowbit(x) ((x)&-(x))
int n,m,a[100005];
int X[40],Y[40];
int to[100005];
int root[100005];
int tot;
int ls[10000005],rs[10000005],sum[10000005];
void add(int&o,int l,int r,int pos){
	if(!o) o=++tot;
	if(l==r){
		sum[o]++;
		return;
	}else{
		int mid=(l+r)>>1;
		if(pos<=mid){
			add(ls[o],l,mid,pos);
		}else{
			add(rs[o],mid+1,r,pos);
		}
		sum[o]=sum[ls[o]]+sum[rs[o]];
	}
}
void del(int&o,int l,int r,int pos){
	if(l==r){
		sum[o]--;
		return;
	}else{
		int mid=(l+r)>>1;
		if(pos<=mid){
			del(ls[o],l,mid,pos);
		}else{
			del(rs[o],mid+1,r,pos);
		}
		sum[o]=sum[ls[o]]+sum[rs[o]];
	}
}
void add(int pos,int val){
	while(pos<=n){
		add(root[pos],1,n,val);
		pos+=lowbit(pos);
	}
}

int _c;
void ask1(int l,int r,int L){
	if(L<=l){
		for(int i=1;i<=X[0];i++) _c-=sum[X[i]];
		for(int i=1;i<=Y[0];i++) _c+=sum[Y[i]];
	}else{
		int mid=(l+r)>>1;
		if(L<=mid){
			for(int i=1;i<=X[0];i++) _c-=sum[rs[X[i]]],X[i]=ls[X[i]];
			for(int i=1;i<=Y[0];i++) _c+=sum[rs[Y[i]]],Y[i]=ls[Y[i]];
			ask1(l,mid,L);
		}else{
			for(int i=1;i<=X[0];i++) X[i]=rs[X[i]];
			for(int i=1;i<=Y[0];i++) Y[i]=rs[Y[i]];
			ask1(mid+1,r,L);
		}
	}
}
void ask2(int l,int r,int R){
	if(r<=R){
		for(int i=1;i<=X[0];i++) _c-=sum[X[i]];
		for(int i=1;i<=Y[0];i++) _c+=sum[Y[i]];
	}else{
		int mid=(l+r)>>1;
		if(R>mid){
			for(int i=1;i<=X[0];i++) _c-=sum[ls[X[i]]],X[i]=rs[X[i]];
			for(int i=1;i<=Y[0];i++) _c+=sum[ls[Y[i]]],Y[i]=rs[Y[i]];
			ask2(mid+1,r,R);
		}else{
			for(int i=1;i<=X[0];i++) X[i]=ls[X[i]];
			for(int i=1;i<=Y[0];i++) Y[i]=ls[Y[i]];
			ask2(l,mid,R);
		}
	}
}
int Ask1(int l,int r,int val){
	X[0]=Y[0]=0;
	l--;
	while(l>0){
		X[++X[0]]=root[l];
		l-=lowbit(l);
	}
	while(r>0){
		Y[++Y[0]]=root[r];
		r-=lowbit(r);
	}
	_c=0;
	ask1(1,n,val);//more
	return _c;
}
int Ask2(int l,int r,int val){
	X[0]=Y[0]=0;
	l--;
	while(l>0){
		X[++X[0]]=root[l];
		l-=lowbit(l);
	}
	while(r>0){
		Y[++Y[0]]=root[r];
		r-=lowbit(r);
	}
	_c=0;
	ask2(1,n,val);//less
	return _c;
}
void Del(int pos,int val){
	while(pos<=n){
		del(root[pos],1,n,val);
		pos+=lowbit(pos);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),to[a[i]]=i;
	LL ans=0;
	for(int i=1;i<=n;i++){
		add(i,a[i]);
		ans+=Ask1(1,i-1,a[i]);
	}
	while(m--){
		int x;
		scanf("%d",&x);
		printf("%lld\n",ans);
		Del(to[x],x);
		int i=to[x];
		ans-=Ask1(1,i,a[i])+Ask2(i,n,a[i]);
	}
	return 0;
}
