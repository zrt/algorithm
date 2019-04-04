#include <cstdio>
#include <algorithm>

using namespace std;


int n,k;

int a[400005][5];
int c[2] = {-1,1};
int mx[800005][1<<5];
// int mn[200005][1<<5];
int calc(int* x,int s){
	int ret = 0;
	for(int i=0;i<k;i++){
		ret += c[s>>i&1]*x[i];
	}
	return ret;
}
void merge(int o){
	for(int i=0;i<(1<<k);i++){
		mx[o][i] = max(mx[o<<1][i],mx[o<<1|1][i]);
	}
}
void build(int o,int l,int r){
	if(l==r){
		for(int i=0;i<(1<<k);i++){
			mx[o][i] = calc(a[l],i);
		}
	}else{
		int mid=(l+r)/2;
		build(o<<1,l,mid);
		build(o<<1|1,mid+1,r);
		merge(o);
	}
}
void cg(int o,int l,int r,int pos,int* x){
	// printf("%d %d %d %d\n",o,l,r,pos);
	if(l==r){
		for(int i=0;i<(1<<k);i++){
			mx[o][i] = calc(x,i);
		}
	}else{
		int mid=(l+r)/2;
		if(pos<=mid)
			cg(o<<1,l,mid,pos,x);
		else
			cg(o<<1|1,mid+1,r,pos,x);
		merge(o);
	}
}

int ask(int o,int l,int r,int L,int R, int k){
	if(l==L && r==R){
		return mx[o][k];
	}else{
		int mid=(l+r)/2;
		if(R<=mid) return ask(o<<1,l,mid,L,R,k);
		else if(L>mid) return ask(o<<1|1,mid+1,r,L,R,k);
		else return max(ask(o<<1,l,mid,L,mid,k),ask(o<<1|1,mid+1,r,mid+1,R,k));
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) for(int j=0;j<k;j++) scanf("%d",&a[i][j]);

	int q;
	scanf("%d",&q);

	build(1,1,n);

	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x;
			int tmp[5];
			scanf("%d",&x);
			for(int i=0;i<k;i++) scanf("%d",&tmp[i]);
			cg(1,1,n,x,tmp);
		}else{
			int l,r;
			scanf("%d%d",&l,&r);
			int mx = 0;
			for(int i=0;i<(1<<k);i++){
				mx = max(mx,ask(1,1,n,l,r,i)+ask(1,1,n,l,r,i^((1<<k)-1)));
			}
			printf("%d\n",mx);
		}
	}


	return 0;
}
