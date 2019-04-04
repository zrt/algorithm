/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
int n,m,opt,x;
const int MAXN=50005,MAXM=50005;
int lft[MAXN*3],rgt[MAXN*3],sum[MAXN*3],_l,_r;
bool empty[MAXN*3],set[MAXN*3];
void mk(int o,int l,int r){
	if(l==r){
		lft[o]=rgt[o]=sum[o]=1;
	}else{
		int mid=(l+r)>>1;
		mk(o<<1,l,mid);
		mk(o<<1|1,mid+1,r);
		lft[o]=rgt[o]=sum[o]=sum[o<<1]+sum[o<<1|1];
	}
}
void pushdown(int o,int l,int r){
	int mid=(l+r)>>1;
	if(empty[o]){
		lft[o<<1]=rgt[o<<1]=sum[o<<1]=mid-l+1;
		lft[o<<1|1]=rgt[o<<1|1]=sum[o<<1|1]=r-mid;
		empty[o<<1]=empty[o<<1|1]=1;set[o<<1]=set[o<<1|1]=empty[o]=0;
	}
	if(set[o]){
		lft[o<<1]=rgt[o<<1]=sum[o<<1]=0;
		lft[o<<1|1]=rgt[o<<1|1]=sum[o<<1|1]=0;
		empty[o<<1]=empty[o<<1|1]=set[o]=0;
		set[o<<1]=set[o<<1|1]=1;
	}
}
void add(int o,int l,int r){
	if(_l<=l&&_r>=r){
		set[o]=1;empty[o]=0;
		lft[o]=rgt[o]=sum[o]=0;
		return;
	}else{
		int mid=(l+r)>>1;
		pushdown(o,l,r);
		if(_l<=mid) add(o<<1,l,mid);
		if(_r>mid) add(o<<1|1,mid+1,r);
		if(sum[o<<1]==mid-l+1){
			lft[o]=sum[o<<1]+lft[o<<1|1];
		}else lft[o]=lft[o<<1];
		if(sum[o<<1|1]==r-mid){
			rgt[o]=sum[o<<1|1]+rgt[o<<1];
		}else rgt[o]=rgt[o<<1|1];
		sum[o]=max(max(sum[o<<1],sum[o<<1|1]),lft[o<<1|1]+rgt[o<<1]);
	}
}
void change(int o,int l,int r){
	if(_l<=l&&_r>=r){
		empty[o]=1;set[o]=0;
		lft[o]=rgt[o]=sum[o]=r-l+1;
		return;
	}else{
		int mid=(l+r)>>1;
		pushdown(o,l,r);
		if(_l<=mid) change(o<<1,l,mid);
		if(_r>mid) change(o<<1|1,mid+1,r);
		if(sum[o<<1]==mid-l+1){
			lft[o]=sum[o<<1]+lft[o<<1|1];
		}else lft[o]=lft[o<<1];
		if(sum[o<<1|1]==r-mid){
			rgt[o]=sum[o<<1|1]+rgt[o<<1];
		}else rgt[o]=rgt[o<<1|1];
		sum[o]=max(max(sum[o<<1],sum[o<<1|1]),lft[o<<1|1]+rgt[o<<1]);
	}
}
int ask(int x){
	if(sum[1]<x)return 0;
	int o=1,l=1,r=n;
	int h=x;
	while(l!=r){
		pushdown(o,l,r);
		if(sum[o<<1]>=x){
			o=o<<1;
			r=(l+r)>>1;
			continue;
		}
		if(lft[o<<1|1]+rgt[o<<1]>=x) break;
		if(sum[o<<1|1]>=x){
			o=o<<1|1;
			l=((l+r)>>1)+1;
		}
	}
	if(l==r){
		return l;
	} else{
		pushdown(o,l,r);
		int mid=(l+r)>>1;
		x-=rgt[o<<1];
		int k=mid+x;
		return k-h+1;
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	
	scanf("%d%d",&n,&m);
	mk(1,1,n);
	while(m--){
		scanf("%d%d",&opt,&x);
		if(opt&1){
			int k=ask(x);
			printf("%d\n",k);
			if(k==0) continue;
			_l=k;_r=k+x-1;
			add(1,1,n);
		}else{
			_l=x;
			scanf("%d",&_r);
			_r+=_l-1;
			change(1,1,n);
		}
	} 
	return 0;
}
