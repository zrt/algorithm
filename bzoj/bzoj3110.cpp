#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int root[50005*4],ls[5000500*5],rs[5000500*5],sum[5000500*5],lazy[5000500*5];
int tot;
void down(int o,int l,int r){
	if(lazy[o]){
		int mid=(l+r)>>1;
		if(!ls[o]) ls[o]=++tot;
		if(!rs[o]) rs[o]=++tot;
		lazy[ls[o]]+=lazy[o];
		lazy[rs[o]]+=lazy[o];
		sum[ls[o]]+=(mid-l+1)*lazy[o];
		sum[rs[o]]+=(r-mid)*lazy[o];
		lazy[o]=0;
	}
}
void cg(int&o,int l,int r,int L,int R){
	if(!o) o=++tot;
	if(l==L&&r==R){
		lazy[o]++;
		sum[o]+=R-L+1;
	}else{
		down(o,l,r);
		int mid=(l+r)>>1;
		if(R<=mid) cg(ls[o],l,mid,L,R);
		else if(L>mid) cg(rs[o],mid+1,r,L,R);
		else cg(ls[o],l,mid,L,mid),cg(rs[o],mid+1,r,mid+1,R);
		sum[o]=sum[ls[o]]+sum[rs[o]];
	}
}
void Insert(int a,int b,int c){
	int l=1,r=n,mid,o=1;
	while(l!=r){
		cg(root[o],1,n,a,b);
		mid=(l+r)>>1;
		if(c<=mid) r=mid,o<<=1;
		else l=mid+1,o=o<<1|1;
	}
	cg(root[o],1,n,a,b);
}
int q(int&o,int l,int r,int L,int R){
	if(!o) return 0;
	if(l==L&&r==R){
		return sum[o];
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid) return q(ls[o],l,mid,L,R);
		else if(L>mid) return q(rs[o],mid+1,r,L,R);
		else return q(ls[o],l,mid,L,mid)+q(rs[o],mid+1,r,mid+1,R);
		sum[o]=sum[ls[o]]+sum[rs[o]];
	}
}
int ask(int a,int b,int k){
	int o=1;
	int l=1, r=n;
	while(l!=r){
		int mid=(l+r)>>1;
		int tmp=q(root[o<<1|1],1,n,a,b);
	//	printf("%d %d %d\n",l,r,tmp);
		if(tmp>=k){
			l=mid+1;o=o<<1|1;
		}else{
			r=mid;o<<=1;
			k-=tmp;
		}
	}
	return l;
}
int main(){

	scanf("%d%d",&n,&m);
	for(int i=0,t,a,b,c;i<m;i++){
		scanf("%d%d%d%d",&t,&a,&b,&c);
		if(t&1){
			Insert(a,b,c);
		}else{
			printf("%d\n",ask(a,b,c));
		}
	}
	return 0;
}
